//
// Created by Hikaze on 2021/10/7 20:37.
// 
//

#include "Matrix.h"
#include "ASSERT.h"
Matrix * MatrixInit(size_t lines, size_t columns){
    Matrix * pMatrixRtn = (Matrix *) calloc(1, sizeof (Matrix));
    ASSERT(pMatrixRtn);
    pMatrixRtn->columns = columns;
    pMatrixRtn->lines = lines;
    pMatrixRtn->data = (long*) calloc(columns*lines, sizeof(long));
    ASSERT(pMatrixRtn->data);
    return pMatrixRtn;
}

void MatrixFree(Matrix * pMatrix){
    ASSERT(pMatrix);
    ASSERT(pMatrix->data);
    free(pMatrix->data);
    free(pMatrix);
}

void MatrixSetElement(Matrix * pMatrix, size_t line, size_t column, long pData){
    ASSERT(pMatrix);
    ASSERT(pMatrix->data);
    ASSERT(column<=pMatrix->columns && line<=pMatrix->lines);
    pMatrix->data[(line-1)*pMatrix->columns+column-1] = pData;
}

long MatrixGetElement(Matrix * pMatrix, size_t line, size_t column){
    ASSERT(pMatrix);
    ASSERT(pMatrix->data);
    ASSERT(column<=pMatrix->columns && line<=pMatrix->lines);
    return pMatrix->data[(line-1)*pMatrix->columns+column-1];
}

void MatrixDraw(Matrix * pMatrix){
    ASSERT(pMatrix);
    ASSERT(pMatrix->data);
    printf_s("\nMatrix: \t0x%p\n", pMatrix);
    printf_s("Columns:\t%zu\n", pMatrix->columns);
    printf_s("Lines:  \t%zu\n\n", pMatrix->lines);
    for(size_t i = 0; i<pMatrix->lines;i++){
        for(size_t j =0; j<pMatrix->columns;j++){
            printf_s("%ld\t", pMatrix->data[i*pMatrix->columns+j]);
        }
        printf_s("\n");
    }
}