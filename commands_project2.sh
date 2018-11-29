#!/bin/bash

## uncomment #define SIMPLE_SOLUTION

gcc project2_mm.c -o init.out -msse4.2

./init.out 100
./init.out 1000
./init.out 10000
./init.out 100000

## uncomment #define UNROLL

gcc project2_mm.c -o unroll.out -msse4.2

./unroll.out 100
./unroll.out 1000
./unroll.out 10000
./unroll.out 100000

## uncomment #define UNROLL_JAM_SEPERATE_VARIABLES

gcc project2_mm.c -o unroll_jam_sep.out -msse4.2

./unroll_jam_sep.out 100
./unroll_jam_sep.out 1000
./unroll_jam_sep.out 10000
./unroll_jam_sep.out 100000

## uncomment #define UNROLL_JAM_ARRAYS

gcc project2_mm.c -o unroll_jam_arrays.out -msse4.2

./unroll_jam_arrays.out 100
./unroll_jam_arrays.out 1000
./unroll_jam_arrays.out 10000
./unroll_jam_arrays.out 100000

## uncomment #define UNROLL_JAM_ARRAYS

gcc project2_mm.c -o vector_intrincics.out -msse4.2

./vector_intrincics.out 100
./vector_intrincics.out 1000
./vector_intrincics.out 10000
./vector_intrincics.out 100000

exit