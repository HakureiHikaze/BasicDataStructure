cmake_minimum_required(VERSION 3.5)
project(BasicDataStructure C)

set(CMAKE_C_STANDARD 11)

add_library(BasicDataStructure STATIC Vector.c SortAlgorithm.c Matrix.c Matrix.h ASSERT.h Graph.c Graph.h SeqQueue.c SeqQueue.h PrintCallback.h SeqStack.c SeqStack.h Tensor.c Tensor.h BitStream.c BitStream.h)

add_executable(test main.c utilities.c utilities.h)
target_link_libraries(test
        PRIVATE
            BasicDataStructure
        )