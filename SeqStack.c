//
// Created by Hikaze on 2021/10/10 20:18.
// 
//

#include "SeqStack.h"
#include <stdio.h>
#include "ASSERT.h"

void SStackRealloc(SeqStack* pSS, _Bool isLarger);

SeqStack * SStackInit(){
    SeqStack * pRtn = (SeqStack*) calloc(1, sizeof(SeqStack));
    ASSERT(pRtn);
    pRtn->pData = (void**) calloc(INIT_SIZE, sizeof(void*));
    ASSERT(pRtn->pData);
    pRtn->size = 0;
    pRtn->capacity = INIT_SIZE;
    return pRtn;
}

void SStackFree(SeqStack* pSS){
    if(pSS){
        if(pSS->pData){
            free(pSS->pData);
        }
        free(pSS);
    }
}

void SStackPush(SeqStack* pSS, void* data){
    ASSERT(pSS);
    ASSERT(pSS->pData);
    if(pSS->size == pSS->capacity){
        SStackRealloc(pSS, 1);
    }
    if(pSS->size!=0) {
        pSS->pData[pSS->size-1] = data;
    }else{
        pSS->pData[0] = data;
    }
    pSS->size++;
}

void* SStackPop(SeqStack* pSS){
    ASSERT(pSS);
    ASSERT(pSS->pData);
    ASSERT(pSS->size!=0);
    void* pRtn = pSS->pData[pSS->size-1];
    pSS->size--;
    if(pSS->size<pSS->capacity/4){
        SStackRealloc(pSS,0);
    }
    return pRtn;
}

size_t SStackGetSize(SeqStack* pSS){
    ASSERT(pSS);
    ASSERT(pSS->pData);
    return pSS->size;
}

_Bool SStackIsEmpty(SeqStack* pSS){
    if(pSS){
        if(pSS->pData){
            if(pSS->size == 0){
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 1;
}

void SStackPrint(SeqStack* pSS, PrintCallback printCallback){
    if(SStackIsEmpty( pSS)){
        printf_s("\nEmpty Stack.\n");
    }else{
        printf_s("Stack:\n");
        for(size_t i =0; i<pSS->capacity;i++){
            printCallback(pSS->pData[i]);
        }
    }
    printf_s("\nStack:\t0x%p\npData:\t%p\nSize: \t%zu\nCapacity:\t%zu\n",
             pSS,pSS->pData,pSS->size,pSS->capacity);
}

void SStackRealloc(SeqStack* pSS, _Bool isLarger){
    if(isLarger){
        void** pNew = (void**) realloc(pSS, pSS->capacity*2* sizeof(void*));
        ASSERT(pNew);
        pSS->pData = pNew;
        pSS->capacity*=2;
    }else{
        void** pNew = (void**) calloc(pSS->capacity/2, sizeof(void*));
        for(size_t i = 0; i<pSS->size;i++){
            pNew[i] = pSS->pData[i];
        }
        free(pSS->pData);
        pSS->pData = pNew;
        pSS->capacity/=2;
    }
}
