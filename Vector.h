//
// Created by Hikaze on 2021/9/30 9:12.
// 
//

#pragma once
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define SMALL_TO_BIG 1
#define BIG_TO_SMALL -1

typedef struct Vector_{
    void** pArray;
    size_t size;
    size_t capacity;
}Vector;
/**
 * @brief 初始化矢量
 */
extern Vector* VectorInit();
/**
 * @brief 释放矢量
 * @param vector 矢量指针
 */
extern void VectorFree(Vector* vector);
/**
 * @brief 矢量追加一个元素
 * @param vector 矢量指针
 * @param pData 数据指针
 */
extern void VectorPushBack(Vector * vector, void* pData);
/**
 * @brief 矢量从末尾弹出一个元素
 * @param vector 矢量指针
 * @return 元素指针
 */
extern void* VectorPopBack(Vector * vector);
/**
 * @brief 在矢量中指定索引的元素前插入元素
 * @param vector 矢量指针
 * @param index 索引，取值范围[0,size]
 * @param pData 数据指针
 */
extern void VectorInsertElement(Vector * vector, size_t index, void* pData);
/**
 * @brief 在矢量中指定索引的元素前插入矢量
 * @param vector 矢量指针
 * @param index 索引，取值范围[0,size]
 * @param pVector 插入的矢量的指针
 */
extern void VectorInsertVector(Vector * vector, size_t index, Vector* pVector);
/**
 * @brief 对矢量指定索引间的元素（含两端）排序
 * @param vector 矢量指针
 * @param begin 起始索引
 * @param end 结束索引
 * @param order 从大到小排序或从小到大排序，宏：BIG_TO_SMALL, SMALL_TO_BIG
 * @param compareCallback 比较回调函数，若参数0 > 参数1则返回1，否则返回-1，原型: int(*)(void*, void*)
 * @param sortCallback 排序回调函数，原型: void(*)(void*, size_t,size_t,int(*)(void*, void*))
 */
extern void VectorSort(
        Vector * vector,
        size_t begin,
        size_t end,
        int order,
        int (*compareCallback)(void* pA, void* pB),
        void(*sortCallback)(
                void** pArray,
                size_t begin,
                size_t end,
                int order,
                int (*compareCallback)(void* pA, void* pB))
                );
/**
 * @brief 测试输出
 * @param vector 矢量指针
 * @param printCallback 输出元素数据回调函数，原型: void(*)(void*)
 */
extern void VectorDebugPrint(Vector * vector, void(*printCallback)(void* p));
/**
 * @brief 交换两个矢量的数据
 * @param vectorA 矢量A
 * @param vectorB 矢量B
 */
extern void VectorSwap(Vector* vectorA, Vector* vectorB);
/**
 * @brief 冒泡排序(含两端)
 * @param pArray 数组指针
 * @param begin 起始索引
 * @param end 结束索引
 * @param order 从大到小排序或从小到大排序，宏：BIG_TO_SMALL, SMALL_TO_BIG
 * @param compareCallback 比较回调函数，若参数0 > 参数1则返回true，原型: bool(*)(void*, void*)
 */

extern void BubbleSort(
        void** pArray,
        size_t begin,
        size_t end,
        int order,
        int(*compareCallback)(void* pA, void* pB)
        );
/**
 * @brief 选择排序
 * @param pArray 数组指针
 * @param begin 起始索引
 * @param end 结束索引
 * @param order 从大到小排序或从小到大排序，宏：BIG_TO_SMALL, SMALL_TO_BIG
 * @param compareCallback 比较回调函数，若参数0 > 参数1则返回true，原型: bool(*)(void*, void*)
 */
extern void SelectSort(
        void** pArray,
        size_t begin,
        size_t end,
        int order,
        int(*compareCallback)(void* pA, void* pB)
        );
/**
 * @brief 插入排序
 * @param pArray 数组指针
 * @param begin 起始索引
 * @param end 结束索引
 * @param order 从大到小排序或从小到大排序，宏：BIG_TO_SMALL, SMALL_TO_BIG
 * @param compareCallback 比较回调函数，若参数0 > 参数1则返回true，原型: bool(*)(void*, void*)
 */
extern void InsertSort(
        void** pArray,
        size_t begin,
        size_t end,
        int order,
        int(*compareCallback)(void* pA, void* pB)
        );
/**
 * @brief 快速排序
 * @param pArray 数组指针
 * @param begin 起始索引
 * @param end 结束索引
 * @param order 从大到小排序或从小到大排序，宏：BIG_TO_SMALL, SMALL_TO_BIG
 * @param compareCallback 比较回调函数，若参数0 > 参数1则返回true，原型: bool(*)(void*, void*)
 */
extern void QuickSort(
        void** pArray,
        size_t begin,
        size_t end,
        int order,
        int(*compareCallback)(void* pA, void* pB)
        );
/**
 * @brief 归并排序
 * @param pArray 数组指针
 * @param begin 起始索引
 * @param end 结束索引
 * @param order 从大到小排序或从小到大排序，宏：BIG_TO_SMALL, SMALL_TO_BIG
 * @param compareCallback 比较回调函数，若参数0 > 参数1则返回true，原型: bool(*)(void*, void*)
 */
extern void MergeSort(
        void** pArray,
        size_t begin,
        size_t end,
        int order,
        int(*compareCallback)(void* pA, void* pB)
        );