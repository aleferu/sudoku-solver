#!/usr/bin/env bash

set -xe

mkdir -p target
g++ -Wall -Wextra -Wconversion -pedantic -g src/main.cpp src/solver.cpp -o target/sudoku-solver-GUI -lraylib -Isrc
