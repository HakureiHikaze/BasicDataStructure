//
// Created by Hikaze on 2021/10/8 12:38.
// 
//

#pragma once
#include "Matrix.h"
#include "Vector.h"

typedef struct AMGraph_{
    void* * pData;
    Matrix* pAM;
    size_t size, edge;
}AMGraph;

extern AMGraph * AMGInit(size_t size);
extern void AMGFree(AMGraph* pAMG);
extern Vector * AMGDFT(AMGraph* pAMG);
extern Vector * AMGBFT(AMGraph* pAMG);
extern void AMGSetEdge(AMGraph* pMAG, size_t indexA, size_t indexB, long weight);