//
// Created by Hikaze on 2021/10/10 20:18.
// 
//

#pragma once
#include <stdlib.h>
#include "PrintCallback.h"
//预先设置初始化时默认分配的大小
#ifndef INIT_SIZE
#define INIT_SIZE 1
#endif

typedef struct SeqStack_{
    void** pData;
    size_t size,capacity;
}SeqStack;

extern SeqStack * SStackInit();
extern void SStackFree(SeqStack* pSS);
extern void SStackPush(SeqStack* pSS, void* data);
extern void* SStackPop(SeqStack* pSS);
extern size_t SStackGetSize(SeqStack* pSS);
extern _Bool SStackIsEmpty(SeqStack* pSS);
extern void SStackPrint(SeqStack* pSS, PrintCallback printCallback);
