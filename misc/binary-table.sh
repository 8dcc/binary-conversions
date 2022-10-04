#!/bin/bash

bin="conversor.out"
rows=$1

for (( i=0; i<=rows; i++ )); do
# for i in {0..$rows}; do
    # Decimal to binary
    ./$bin d b $i
done
