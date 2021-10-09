//
// Created by Hikaze on 2021/10/9 11:40.
// 
//

#include "SeqQueue.h"
#include "ASSERT.h"

size_t SQIndexing(SeqQueue *,size_t);

SeqQueue * SQInit(){
    SeqQueue * pRtn = (SeqQueue*) calloc(1, sizeof(SeqQueue));
    ASSERT(pRtn);
    pRtn->pData = (void**) calloc(INIT_SIZE, sizeof(void*));
    ASSERT(pRtn->pData);
    pRtn->size = 0;
    pRtn->capacity = 16;
    pRtn->head = 0;
    pRtn->rear = 0;
    return pRtn;
}

void SQFree(SeqQueue* pSQ){
    if(pSQ){
        free(pSQ->pData);
        free(pSQ);
    }
}

void SQEnqueue(SeqQueue* pSQ, void* data){
    ASSERT(pSQ);
    if(pSQ->size == pSQ->capacity){
        size_t old_capacity = pSQ->capacity;
        void** pNew = (void**)realloc(pSQ->pData, 2*old_capacity*sizeof(void*));
        ASSERT(pNew);
        pSQ->pData = pNew;
        pSQ->capacity*=2;
        if(pSQ->head > pSQ->rear){
            if(pSQ->head>=old_capacity/2){
                for (size_t i = pSQ->head; i < old_capacity; i++) {
                    pSQ->pData[i+old_capacity] = pSQ->pData[i];
                    pSQ->pData[i] = 0;
                }
                pSQ->head +=old_capacity;
            }else{
                for(size_t i =0; i<pSQ->head;i++){
                    pSQ->pData[i+old_capacity] = pSQ->pData[i];
                    pSQ->pData[i] = 0;
                }
                pSQ->rear +=old_capacity;
            }
        }
    }

    size_t newRear = SQIndexing(pSQ, pSQ->rear+1);
    pSQ->pData[newRear] = data;
    pSQ->rear = newRear;
    pSQ->size++;
}

size_t SQIndexing(SeqQueue * pSQ,size_t raw){
    return raw%pSQ->size;
}