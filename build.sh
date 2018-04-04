#!/bin/bash
SRC=./src
INCLUDES=./src/includes

g++ -std=c++11 $(ls $SRC/*.cpp) $(ls $INCLUDES/*.cpp) $(ls $INCLUDES/*.h) -o bin/PAGE_FIFO
