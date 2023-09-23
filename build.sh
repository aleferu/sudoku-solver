#!/usr/bin/env bash

set -xe

gcc -Wall -Wextra -Wconversion -pedantic -g sudoku-solver.c -o sudoku-solver
