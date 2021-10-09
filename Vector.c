//
// Created by Hikaze on 2021/9/30 9:12.
// 
//

#include "Vector.h"

#define ASSERT(x) if(!x)exit(-1) //伪断言，不符合条件则退出

Vector* VectorInit(){
    Vector* pRtn = (Vector*) calloc(1, sizeof(Vector));
    ASSERT(pRtn);
    return pRtn;
}
//#define DEBUG
void VectorReAlloc(Vector* vector){
#ifndef DEBUG
    void **pNew = (void **) realloc(vector->pArray, 2 * vector->capacity * sizeof(void *));
    ASSERT(pNew);//空检测
    vector->pArray = pNew;
    vector->capacity *= 2;
#endif
#ifdef DEBUG
    void** pNew = (void**)calloc(2*vector->capacity,sizeof(void*));
    ASSERT(pNew);
    for(size_t i = 0; i<vector->size;i++){
        pNew[i] = vector->pArray[i];
    }
    vector->pArray = pNew;
    vector->capacity  = vector->capacity*2;
#endif
}

void VectorElementCpy(Vector * vector, size_t from, size_t to){
    vector->pArray[to] = vector->pArray[from];
}

void VectorFree(Vector* vector){
    if(vector){
        if(vector->capacity){
            free(vector->pArray);
        }
    }
    free(vector);
}

void VectorPushBack(Vector *vector, void *pData) {
    ASSERT(vector);//空检测
    if(!vector->capacity){
        vector->pArray = (void**) calloc(8, sizeof(void*));
        vector->capacity = 8;
    }
    //已用空间==可用空间时表示满，扩增
    if (vector->size == vector->capacity) {
        //重分配空间
        VectorReAlloc(vector);
    }
    vector->pArray[vector->size] = pData;
    vector->size++;
}

void* VectorPopBack(Vector *vector) {
    ASSERT(vector);//空检测
    void* p =vector->pArray[vector->size-1];
    vector->size--;
    return p;
}

void VectorInsertElement(Vector * vector, size_t index, void* pData){
    ASSERT(vector);//空检测
    ASSERT(!(index>vector->size-1));
    if(vector->size == vector->capacity){
        //重分配空间
        VectorReAlloc(vector);
    }
    vector->size++;
    if(index == vector->size){//如果在末尾插入，直接pushback
        VectorPushBack(vector, pData);
        return;
    }
    for(size_t i = vector->size; i>index;i--){
        VectorElementCpy(vector, i-1, i);
    }
    vector->pArray[index] = pData;
}

void VectorInsertVector(Vector * vector, size_t index, Vector* pVector){
    ASSERT(vector);//空检测
    ASSERT(pVector);
    ASSERT(!(vector==pVector));//不能等于原矢量指针
    ASSERT(!(index>vector->size-1));
    while(vector->size + pVector->size > vector->capacity){
        VectorReAlloc(vector);
    }
    vector->size += pVector->size;
    if(index == vector->size){//如果在末尾插入，直接pushback
        for(size_t i = 0; i<pVector->size; i++){
            VectorPushBack(vector, pVector->pArray[i]);
        }
        return;
    }
    for(size_t i = vector->size; i>index-1;i--){
        VectorElementCpy(vector, i, i+pVector->size);
    }
    for(size_t i =0; i<pVector->size; i++){
        vector->pArray[index+i] = pVector->pArray[i];
    }
}

void VectorSort(
        Vector * vector,
        size_t begin,
        size_t end,
        int order,
        int (*compareCallback)(void* pA, void* pB),
        void(*sortCallback)(void**,size_t,size_t,int,int (*)(void* pA, void* pB))){
    ASSERT(vector);//空检测
    //传递参数
    sortCallback(vector->pArray,begin,end, order,compareCallback);
}

void VectorDebugPrint(Vector * vector, void(*printCallback)(void*)){
    ASSERT(vector);//空检测
    printf_s("Vector:  \t0x%zx\n", (size_t)vector);
    printf_s("Array:   \t0x%zx\n", (size_t)vector->pArray);
    printf_s("Size:    \t%zu\n", vector->size);
    printf_s("Capacity:\t%zu\n\n", vector->capacity);
    for(size_t i = 0; i<vector->size; i++){
        if(!(i%8)) printf_s("\n");
        printCallback(vector->pArray[i]);
    }
    printf_s("\n");
}