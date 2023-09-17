#include <stdio.h>
#include <stdbool.h>


#define N 9
#define GRID_SIZE (N * N)
#define BLOCK_SIZE (N / 3)
#define BLANK 0
#define grid_type unsigned char


void modify_grid_at(grid_type grid[GRID_SIZE], grid_type row, grid_type column, grid_type number) {
    grid[row * N + column] = number;
}


grid_type grid_at(grid_type grid[GRID_SIZE], grid_type row, grid_type column) {
    return grid[row * N + column];
}


void grid_print(grid_type grid[GRID_SIZE]) {
    for (grid_type i = 0; i < N; ++i) {
        for (grid_type j = 0; j < N; ++j) {
            printf("%d ", grid_at(grid, i, j));
        }
        printf("\n");
    }
}


bool is_number_in_row(grid_type grid[GRID_SIZE], grid_type number, grid_type row) {
    grid_type starting_position = row * N;
    for (grid_type i = 0; i < N; ++i) {
        if (grid[starting_position + i] == number) {
            return true;
        }
    }
    return false;
}


bool is_number_in_column(grid_type grid[GRID_SIZE], grid_type number, grid_type column) {
    grid_type starting_position = column;
    for (grid_type i = 0; i < N; ++i) {
        if (grid[starting_position + i * N] == number) {
            return true;
        }
    }
    return false;
}


bool is_number_in_block(grid_type grid[GRID_SIZE], grid_type number, grid_type row, grid_type column) {
    grid_type starting_row = row / BLOCK_SIZE * BLOCK_SIZE;
    grid_type starting_column = column / BLOCK_SIZE * BLOCK_SIZE;
    for (grid_type i = 0; i < BLOCK_SIZE; ++i) {
        for (grid_type j = 0; j < BLOCK_SIZE; ++j) {
            if (number == grid_at(grid, starting_row + i, starting_column + j)) {
                return true;
            }
        }
    }
    return false;
}


bool is_valid_position_for_number(grid_type grid[GRID_SIZE], grid_type number, grid_type row, grid_type column) {
    return !is_number_in_block(grid, number, row, column) &&
           !is_number_in_column(grid, number, column) &&
           !is_number_in_row(grid, number, row);
}


bool is_grid_full(grid_type grid[GRID_SIZE], grid_type* row, grid_type* column) {
    for (grid_type i = 0; i < GRID_SIZE; ++i) {
        if (grid[i] == BLANK) {
            *row = i / N;
            *column = i % N;
            return false;
        }
    }
    return true;
}


bool grid_solve(grid_type grid[GRID_SIZE]) {
    grid_type row;
    grid_type column;
    if (is_grid_full(grid, &row, &column)) {
        return true;
    }

    for (grid_type i = 1; i <= N; ++i) {
        if (is_valid_position_for_number(grid, i, row, column)) {
            modify_grid_at(grid, row, column, i);
            if (grid_solve(grid)) {
                return true;
            }
            modify_grid_at(grid, row, column, BLANK);
        }
    }

    return false;
}


int main(void) {
    grid_type grid[GRID_SIZE] = {
        4, 0, 0, 0, 0, 0, 0, 0, 3,
        0, 0, 8, 0, 7, 0, 4, 5, 0,
        0, 9, 0, 0, 0, 6, 0, 0, 0,
        0, 0, 0, 0, 3, 0, 0, 0, 8,
        0, 0, 1, 0, 0, 0, 0, 0, 2,
        6, 0, 0, 0, 0, 7, 1, 3, 0,
        0, 0, 4, 0, 5, 0, 7, 1, 0,
        8, 0, 0, 4, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 2, 0, 0
    };


    printf("%d\n", grid_solve(grid));
    grid_print(grid);

    return 0;
}
