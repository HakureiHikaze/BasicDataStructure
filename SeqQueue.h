//
// Created by Hikaze on 2021/10/9 11:40.
// 
//

#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "PrintCallback.h"
//预先设置初始化时默认分配的大小
#ifndef INIT_SIZE
#define INIT_SIZE 1
#endif
/**
 * @brief 顺序队列数据结构
 * @param pData 数据指针数组指针
 * @param size 已存储的队列项数量，在Enqueue、Dequeue、Init更新
 * @param head 队首的索引，在Enqueue Dequeue Init Realloc 更新
 * @param rear 队尾的索引，在Enqueue Dequeue Init Realloc 更新
 * @param capacity 数据指针数组的分配长度，在Init Realloc更新
 */
typedef struct SeqQueue_{
    void** pData;
    size_t size, head, rear, capacity;
}SeqQueue;
/**
 * @brief 初始化顺序队列指针
 * @return 初始化的队列指针
 */
extern SeqQueue * SQInit();
/**
 * @brief 释放队列指针
 * @param pSQ 队列指针
 */
extern void SQFree(SeqQueue* pSQ);
/**
 * @brief 元素入队
 * @param pSQ 队列指针
 * @param data 入队元素
 */
extern void SQEnqueue(SeqQueue* pSQ, void* data);
/**
 * @brief 元素出队
 * @param pSQ 队列指针
 * @return 出队元素
 */
extern void* SQDequeue(SeqQueue* pSQ);
/**
 * @brief 测试队列是否为空
 * @param pSQ 队列指针
 * @return pSQ pSQ->pData任意为空或size0时返回1
 */
extern _Bool SQisEmpty(SeqQueue* pSQ);
/**
 * @brief 获取队列长度
 * @param pSQ 队列指针
 * @return 队列长度
 */
extern size_t SQGetSize(SeqQueue* pSQ);
/**
 * @brief 输出队列信息
 * @param pSQ 队列指针
 * @param printCallback绘制数据项的回调函数
 */
extern void SQPrint(SeqQueue* pSQ, PrintCallback printCallback);