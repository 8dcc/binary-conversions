#!/bin/bash

bin="conversor.out"
compensate="compensate.out"
buf="buffer.txt"

rows=$1

echo "" > $buf

for (( i=0; i<=rows; i++ )); do
    # Decimal to binary
    ./$bin d b $i >> $buf
done

./$compensate $rows < $buf
rm $buf
