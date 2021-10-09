//
// Created by Hikaze on 2021/10/9 11:40.
// 
//

#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "PrintCallback.h"

#ifndef INIT_SIZE
#define INIT_SIZE 16
#endif

typedef struct SeqQueue_{
    void** pData;
    size_t size, head, rear, capacity;
}SeqQueue;

extern SeqQueue * SQInit();
extern void SQFree(SeqQueue* pSQ);
extern void SQEnqueue(SeqQueue* pSQ, void* data);
extern void* SQDequeue(SeqQueue* pSQ);
extern _Bool SQisEmpty(SeqQueue* pSQ);
extern size_t SQGetSize(SeqQueue* pSQ);
extern void SQPrint(SeqQueue* pSQ, PrintCallback printCallback);