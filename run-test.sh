#!/bin/bash
echo "01. build omp version"
gcc -fopenmp ./omp_reduction.c -o reduction-omp.exe
echo "02. change code commet progma"
sed 's/#pragma/\/\/#pragma/g' -i omp_reduction.c
echo "03. build cpu version"
gcc -fopenmp ./omp_reduction.c -o reduction-cpu.exe
echo "04. recover progma"
sed 's/\/\/#pragma/#pragma/g' -i omp_reduction.c

echo "05. run both"
./reduction-omp.exe
./reduction-cpu.exe
echo "finish."
