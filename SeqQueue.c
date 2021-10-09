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
_Bool SQisEmpty(SeqQueue* pSQ){
    if(!pSQ) return 1;
    if(!pSQ->pData) return 1;
    if(!pSQ->size) return 1;
    return 0;
}

void SQEnqueue(SeqQueue* pSQ, void* data){
    ASSERT(pSQ);
    if(pSQ->size == pSQ->capacity){
        size_t old_capacity = pSQ->capacity;
        void** pNew = (void**)realloc(pSQ->pData, 2*old_capacity*sizeof(void*));
        for(size_t i = old_capacity;i< old_capacity*2;i++){
            pNew[i] = 0;
        }
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
    size_t newRear;
    if(pSQ->size == 0) {
        newRear = 0;
    }else{
        newRear = SQIndexing(pSQ, pSQ->rear + 1);
    }
    pSQ->pData[newRear] = data;
    pSQ->rear = newRear;
    pSQ->size++;
}

void* SQDequeue(SeqQueue* pSQ){
    ASSERT(pSQ&&pSQ->pData);
    void* pRtn = pSQ->pData[pSQ->head];
    pSQ->head = SQIndexing(pSQ,pSQ->head+1);
    pSQ->size--;

    if(pSQ->size<pSQ->capacity/4){
        for(size_t i = pSQ->head; i<pSQ->size;i++){

        }
    }

    return pRtn;
}

size_t SQIndexing(SeqQueue * pSQ,size_t raw){
    return raw%(pSQ->capacity);
}

void SQPrint(SeqQueue* pSQ, PrintCallback printCallback){
    if(!pSQ){
        printf_s("Null pointer pSQ.\n");
        return;
    }
    if(SQisEmpty(pSQ)){
        printf_s("Empty queue.\n");
        return;
    }
    printf_s("Sequence queue:\t0x%p\n",pSQ);
    printf_s("Capacity:\t%zu\nSize:\t\t%zu\nHead:\t\t%zu\nRear:\t\t%zu\n",
             pSQ->capacity,pSQ->size,pSQ->head,pSQ->rear);
    printf_s("By physics:\n");
    for(size_t i =0 ; i< pSQ->capacity; i++){
        printCallback(pSQ->pData[i]);
        if(!((i+1)%8)) printf_s("\n");
        else printf_s("\t");
    }
    printf_s("\nBy logic:\n");
    for(size_t i =pSQ->head; i<pSQ->head+pSQ->size;i++){
        printCallback(pSQ->pData[SQIndexing(pSQ,i)]);
        if(!((i+1)%8)) printf_s("\n");
        else printf_s("\t");
    }
    printf_s("\n\n");
}