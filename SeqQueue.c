//
// Created by Hikaze on 2021/10/9 11:40.
// 
//

#include "SeqQueue.h"
#include "ASSERT.h"
#include "utilities.h"
//内部实现，实现循环索引
size_t SQIndexing(SeqQueue *, size_t);
//内部实现，重新分配空间（扩大或减小）
void SQRealloc(SeqQueue *, _Bool isLarger);

SeqQueue *SQInit() {
    SeqQueue *pRtn = (SeqQueue *) calloc(1, sizeof(SeqQueue));
    ASSERT(pRtn);//断言
    pRtn->pData = (void **) calloc(INIT_SIZE, sizeof(void *));//INIT_SIZE由SeqQueue指定或用户指定
    ASSERT(pRtn->pData);
    pRtn->size = 0;
    pRtn->capacity = INIT_SIZE;
    pRtn->head = 0;
    pRtn->rear = 0;
    return pRtn;
}

void SQFree(SeqQueue *pSQ) {
    //释放空间
    if (pSQ) {
        free(pSQ->pData);
        free(pSQ);
    }
}

_Bool SQisEmpty(SeqQueue *pSQ) {
    if (!pSQ) return 1;//已被释放时
    if (!pSQ->pData) return 1;//数据指针已被释放时
    if (!pSQ->size) return 1;//数据长度为0时
    return 0;
}

void SQEnqueue(SeqQueue *pSQ, void *data) {
    ASSERT(pSQ);
    //空间不足时扩增一倍空间
    if (pSQ->size == pSQ->capacity) {
        SQRealloc(pSQ,1);
    }
    //新队尾索引
    size_t newRear;
    if (pSQ->size == 0) {
        newRear = pSQ->head;
    } else {
        newRear = SQIndexing(pSQ, pSQ->rear + 1);//循环索引
    }
    pSQ->pData[newRear] = data;
    pSQ->rear = newRear;
    pSQ->size++;
}

void *SQDequeue(SeqQueue *pSQ) {
    ASSERT(pSQ && pSQ->pData);
    void *pRtn = pSQ->pData[pSQ->head];//取出到返回缓冲
    if(pSQ->size>1)pSQ->head = SQIndexing(pSQ, pSQ->head + 1);//循环索引
    pSQ->size--;
    //若出队后元素数小于等于容量的四分之一，则减小一半容量
    if (pSQ->size <= pSQ->capacity / 4) {
        SQRealloc(pSQ, 0);
    }
    return pRtn;
}

size_t SQIndexing(SeqQueue *pSQ, size_t raw) {
    return raw % (pSQ->capacity);//循环索引实现
    //todo:只传递pSQ->capasity以提高运行效率
}

void SQRealloc(SeqQueue *pSQ, _Bool isLarger) {
    //SQPrint(pSQ,printInt);
    if (isLarger) {//扩增的情形
        size_t old_capacity = pSQ->capacity;//缓存旧容量
        //todo: 其实不需要缓存旧容量
        void **pNew = (void **) realloc(pSQ->pData, 2 * old_capacity * sizeof(void *));//为新指针分配两倍大小空间
        //无论是否重分配成功，原指针指向的内存将会被释放
        ASSERT(pNew);//断言
        for (size_t i = old_capacity; i < old_capacity * 2; i++) {
            pNew[i] = 0;//初始化空间，但其实没有必要，只是为了输出好看
        }
        pSQ->pData = pNew;//放弃原指针，原指针指向的内存已被释放
        pSQ->capacity *= 2;
        if (pSQ->head > pSQ->rear) {//如果队列跨界（被队列空间末尾分割一部分到空间起始
            if (pSQ->head >= old_capacity / 2) {//队头（跨空间末尾段）元素更少的情形，复制这些元素到新的空间末尾，并重置head的位置
                for (size_t i = pSQ->head; i < old_capacity; i++) {
                    pSQ->pData[i + old_capacity] = pSQ->pData[i];
                    pSQ->pData[i] = 0;//清理原空间，但其实不需要，只是为了输出好看
                }
                pSQ->head += old_capacity;
            } else {//队尾（跨空间起始段）元素更少的情形，复制这些元素到队列中断点后面
                for (size_t i = 0; i < pSQ->head; i++) {
                    pSQ->pData[i + old_capacity] = pSQ->pData[i];
                    pSQ->pData[i] = 0;//清理原空间，但其实不需要，只是为了输出好看
                }
                pSQ->rear += old_capacity;
            }
        }
    } else {//缩减的情形
        void** pBuffer = (void**) calloc(pSQ->capacity/2, sizeof(void*));//减少空间时realloc的表现偏离预想，用正常方法代之
        ASSERT(pBuffer);//断言
        for(size_t i = 0; i<pSQ->size;i++){//按顺序复制全队列元素（含循环）到pBuffer缓冲
            pBuffer[i] = pSQ->pData[SQIndexing(pSQ, pSQ->head+i)];
        }
        free(pSQ->pData);//释放原队列空间
        pSQ->pData = pBuffer;
        pSQ->capacity/=2;
        pSQ->head = 0;
        if(pSQ->size)pSQ->rear = pSQ->size-1;
        else pSQ->rear = pSQ->head;
    }
}

size_t SQGetSize(SeqQueue* pSQ){
    ASSERT(pSQ);
    return pSQ->size;
}

void SQPrint(SeqQueue *pSQ, PrintCallback printCallback) {
    //输出队列信息，输出函数由用户代码提供
    if (!pSQ) {
        printf_s("Null pointer pSQ.\n");
        printf_s("\n\n");
        return;
    }
    if (SQisEmpty(pSQ)) {
        printf_s("Empty queue.\n");
        //printf_s("Sequence queue:\t0x%p\n", pSQ);
        printf_s("Capacity:\t%zu\nSize:\t\t%zu\nHead:\t\t%zu\nRear:\t\t%zu\n",
                 pSQ->capacity, pSQ->size, pSQ->head, pSQ->rear);
        printf_s("\n\n");
        return;
    }
    //printf_s("Sequence queue:\t0x%p\n", pSQ);
    printf_s("Capacity:\t%zu\nSize:\t\t%zu\nHead:\t\t%zu\nRear:\t\t%zu\n",
             pSQ->capacity, pSQ->size, pSQ->head, pSQ->rear);
    printf_s("\nBy physics:\n");
    for (size_t i = 0; i < pSQ->capacity; i++) {
        printCallback(pSQ->pData[i]);
        if (!((i + 1) % 10)) printf_s("\n");
        //else printf_s("\t");
    }
    printf_s("\nBy logic:\n");
    for (size_t i = pSQ->head; i < pSQ->head + pSQ->size; i++) {
        printCallback(pSQ->pData[SQIndexing(pSQ, i)]);
        if (!((i + 1) % 10)) printf_s("\n");
        //else printf_s("\t");
    }
    printf_s("\n\n");
    fflush(stdout);
}