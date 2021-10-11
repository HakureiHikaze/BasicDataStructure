//
// Created by Hikaze on 2021/10/7 20:22.
// 
//
#include <stdio.h>
#include "SeqStack.h"
#include "utilities.h"

int main(int argc, char** argv){
    SeqStack * test = SStackInit();
    for(size_t i =0; i< 2147483648; i++){
        SStackPush(test,(void*) i);

    }
    //SStackPrint(test,printInt);
    for(size_t i =0; i< 2147483648; i++){
        SStackPop(test);

    }
    //SStackPrint(test,printInt);
    for(size_t i =0; i< 2147483648; i++){
        SStackPush(test,(void*) i);

    }
    //SStackPrint(test,printInt);
    SStackFree(test);
    return 0;
}