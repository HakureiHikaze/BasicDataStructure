//
// Created by Hikaze on 2021/10/7 20:22.
// 
//
#include <stdio.h>
#include "Matrix.h"

int main(int argc, char** argv){
    Matrix * test = MatrixInit(7,8);
    MatrixDraw(test);
    MatrixFree(test);
    return 0;
}