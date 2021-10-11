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
/**
 * @brief 顺序栈结构
 * @param pData 数据数组指针
 * @param size 栈元素数，等于栈顶索引+1，
 * @param capacity 顺序栈数组最大空间，可扩充或缩窄
 */
typedef struct SeqStack_{
    void** pData;
    size_t size,capacity;
}SeqStack;
/**
 * @brief 初始化顺序栈指针
 * @return SStack指针
 */
extern SeqStack * SStackInit();
/**
 * @brief 释放顺序栈
 * @param pSS SStack指针
 */
extern void SStackFree(SeqStack* pSS);
/**
 * @brief 顺序栈入栈
 * @param pSS SStack指针
 * @param data 入栈数据项
 */
extern void SStackPush(SeqStack* pSS, void* data);
/**
 * @brief 顺序栈出栈
 * @param pSS SStack指针
 * @return 出栈数据项
 */
extern void* SStackPop(SeqStack* pSS);
/**
 * @brief 获取栈元素数量
 * @param pSS SStack指针
 * @return 栈元素数量
 */
extern size_t SStackGetSize(SeqStack* pSS);
/**
 * @brief 判断栈是否为空，当且仅当size>=1时返回0
 * @param pSS SStack指针
 * @return
 */
extern _Bool SStackIsEmpty(SeqStack* pSS);
/**
 * @brief 输出顺序栈信息
 * @param pSS SStack指针
 * @param printCallback 对数据项的外部输出函数
 */
extern void SStackPrint(SeqStack* pSS, PrintCallback printCallback);
