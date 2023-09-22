#include "solver.h"
#include "raylib.h"


void modify_grid_at(grid_type grid[GRID_SIZE], grid_type row, grid_type column, grid_type number) {
    grid[row * N + column] = number;
}


grid_type grid_at(grid_type grid[GRID_SIZE], grid_type row, grid_type column) {
    return grid[row * N + column];
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
        if (grid[i] == GRID_BLANK) {
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
            modify_grid_at(grid, row, column, GRID_BLANK);
        }
    }

    return false;
}


void grid_draw(grid_type grid[GRID_SIZE]) {
    // Stay mad about magic values.
    // Idc about GUI programming.
    float padding = 10;
    static Rectangle rect = {0};
    rect.x = padding;
    rect.y = padding;
    rect.height = WINDOW_HEIGHT / 9.0 - 11;
    rect.width = rect.height;
    for (grid_type i = 0; i < N; ++i) {
        for (grid_type j = 0; j < N; ++j) {
            rect.x = (j + 1) * padding + j * rect.width;
            rect.y = (i + 1) * padding + i * rect.height;
            DrawRectangleRounded(rect, 0.5, 20, BLACK);
            char num_char = 48 + grid_at(grid, i, j);
            DrawText(&num_char, rect.x + 24, rect.y + 5, rect.height - 5, WHITE);
        }
    }
}
