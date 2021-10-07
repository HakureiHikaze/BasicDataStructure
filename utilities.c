//
// Created by Hikaze on 2021/10/7 20:31.
// 
//

#include "utilities.h"

void printInt(void* a){
    printf_s("%zu", a);
}

char compareInt(void* a, void* b){
    if(a > b) return 1;
    else return -1;
}