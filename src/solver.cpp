#include "solver.hpp"
#include <algorithm>


Solver::Solver(void) {
    std::fill(&m_grid[0], &m_grid[SUDOKU_LENGTH], 0);
}


bool Solver::solve(void) {
    size_t row;
    size_t column;
    if (this->is_full(&row, &column)) {
        return true;
    }

    for (size_t i = 1; i <= SUDOKU_N; ++i) {
        if (this->is_valid_position_for_number(i, row, column)) {
            this->modify_at(i, row, column);
            if (this->solve()) {
                return true;
            }
            this->modify_at(SUDOKU_BLANK, row, column);
        }
    }
    return false;
}


bool Solver::is_full(size_t* row, size_t* column) const {
    for (size_t i = 0; i < SUDOKU_LENGTH; ++i) {
        if (m_grid[i] == SUDOKU_BLANK) {
            *row = i / SUDOKU_N;
            *column = i % SUDOKU_N;
            return false;
        }
    }
    return true;
}


bool Solver::is_valid_position_for_number(size_t number, size_t row, size_t column) const {
    return !this->is_number_in_block(number, row, column) &&
           !this->is_number_in_column(number, column) &&
           !this->is_number_in_row(number, row);
}


bool Solver::is_number_in_block(size_t number, size_t row, size_t column) const {
    size_t starting_row = row / SUDOKU_BLOCK_SIZE * SUDOKU_BLOCK_SIZE;
    size_t starting_column = column / SUDOKU_BLOCK_SIZE * SUDOKU_BLOCK_SIZE;
    for (size_t i = 0; i < SUDOKU_BLOCK_SIZE; ++i) {
        for (size_t j = 0; j < SUDOKU_BLOCK_SIZE; ++j) {
            if (number == this->at(starting_row + i, starting_column + j)) {
                return true;
            }
        }
    }
    return false;
}


bool Solver::is_number_in_row(size_t number, size_t row) const {
    size_t starting_position = row * SUDOKU_N;
    for (size_t i = 0; i < SUDOKU_N; ++i) {
        if (m_grid[starting_position + i] == number) {
            return true;
        }
    }
    return false;
}


bool Solver::is_number_in_column(size_t number, size_t column) const {
    size_t starting_position = column;
    for (size_t i = 0; i < SUDOKU_N; ++i) {
        if (m_grid[starting_position + i * SUDOKU_N] == number) {
            return true;
        }
    }
    return false;
}


void Solver::modify_at(size_t number, size_t row, size_t column) {
    m_grid[row * SUDOKU_N + column] = number;
}


size_t Solver::at(size_t row, size_t column) const {
    return m_grid[row * SUDOKU_N + column];
}
