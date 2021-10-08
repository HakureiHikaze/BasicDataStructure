//
// Created by Hikaze on 2021/10/7 20:37.
// 
//

#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef struct Matrix_{
    long* data;
    size_t columns;
    size_t lines;
}Matrix;

extern Matrix * MatrixInit(size_t lines, size_t columns);
extern void MatrixFree(Matrix * pMatrix);
extern void MatrixSetElement(Matrix * pMatrix, size_t line, size_t column, long pData);
extern long MatrixGetElement(Matrix * pMatrix, size_t line, size_t column);
extern void MatrixDraw(Matrix * pMatrix);