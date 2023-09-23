# Sudoku solver written in C

Sudoku solver using plain C and the backtracking algorithm.

## Usage

```console
$ sudoku-solver input1.csv input2.csv input3.csv
```

Doesn't have to be a csv, the program will pick up the first 81 digits of each file.

## Build

```console
$ ./build.sh
```

OR

```console
$ cc sudoku-solver.c -o sudoku-solver
```

cc, gcc, clang... Whatever
