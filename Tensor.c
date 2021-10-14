//
// Created by Hikaze on 2021/10/12.
//

#include "Tensor.h"
#include "ASSERT.h"

Tensor* TensorInit(const size_t* pDimensionWidth, size_t dimensionCount){
    Tensor* pRtn = (Tensor*) calloc(1, sizeof (Tensor));
    pRtn->pDimensionWidth = (size_t*) calloc(dimensionCount+1, sizeof(size_t));
    ASSERT(pRtn&& pRtn->pDimensionWidth);
    size_t length = 1;
    for(size_t i = 0; i<dimensionCount;i++){
        length*=pDimensionWidth[i];
        pRtn->pDimensionWidth[i] = pDimensionWidth[i];
    }
    pRtn->pDimensionWidth[dimensionCount] = length;
    pRtn->aData = (long double*) calloc(length, sizeof(long double));
    pRtn->dimensionCount = dimensionCount;
    return pRtn;
}