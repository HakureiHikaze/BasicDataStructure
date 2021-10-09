//
// Created by Hikaze on 2021/10/7 20:22.
// 
//
#include <stdio.h>
#include "SeqQueue.h"
#include "utilities.h"

int main(int argc, char** argv){
    SeqQueue * test = SQInit();
    for(size_t i =0; i< 512; i++){
        SQEnqueue(test,(void*) i);
    }
    SQPrint(test,printInt);
    for(size_t i =0; i< 512; i++){
        SQDequeue(test);
    }
    SQPrint(test,printInt);
    for(size_t i =0; i< 512; i++){
        SQEnqueue(test,(void*) i);
    }
    SQPrint(test,printInt);
    SQFree(test);
    return 0;
}