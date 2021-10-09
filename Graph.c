//
// Created by Hikaze on 2021/10/8 12:38.
// 
//

#include "Graph.h"
#include "ASSERT.h"

AMGraph * AMGInit(size_t size){
    AMGraph * pRtn = (AMGraph*) calloc(1, sizeof(AMGraph));
    ASSERT(pRtn);
    pRtn->pData = (void*) calloc(size, sizeof(void*));
    pRtn->pAM = MatrixInit(size,size);
    pRtn->size = size;
    ASSERT(pRtn->pAM&&pRtn->pData);
    return pRtn;
}

void AMGFree(AMGraph* pAMG){
    if(pAMG){
        if(pAMG->pData) free(pAMG->pData);
        if(pAMG->pAM) MatrixFree(pAMG->pAM);
    }
}

void AMGSetEdge(AMGraph* pMAG, size_t indexA, size_t indexB, long weight){
    ASSERT(pMAG&&pMAG->pAM&&pMAG->pData);
    ASSERT(indexA<pMAG->size&&indexB<pMAG->size);
    MatrixSetElement(pMAG->pAM, indexA+1, indexB+1,weight);
    pMAG->edge++;
}