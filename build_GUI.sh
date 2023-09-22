#!/usr/bin/env bash

set -xe

mkdir -p target
gcc -Wall -Wextra -Wconversion -pedantic -g src/main.c src/solver.c -o target/sudoku-solver-GUI -lraylib -Isrc
