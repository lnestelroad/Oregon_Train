#!/bin/bash

clear

if [ -f ./run.out ]; then
    rm ./run.out
fi

g++ Oregon_Trail_Driver.cpp -o run.out
./run.out
