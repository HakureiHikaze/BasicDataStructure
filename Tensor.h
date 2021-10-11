//
// Created by Hikaze on 2021/10/12.
//

#pragma once
#include <stdlib.h>
/**
 * @brief 这个结构是我熬夜脑子抽风写着玩的
 */
typedef struct Tensor_{
    size_t* pDimensionWidth;
    size_t dimensionCount;
    long double* aData;
}Tensor;

extern Tensor* TensorInit(const size_t* pDimensionWidth, size_t dimensionCount);