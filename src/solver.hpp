#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <cstddef>

#define SUDOKU_N 9
#define SUDOKU_LENGTH (SUDOKU_N * SUDOKU_N)
#define SUDOKU_BLOCK_SIZE (SUDOKU_N / 3)
#define SUDOKU_BLANK 0

class Solver {
public:
    Solver(void);
    bool solve(void);
    bool is_full(size_t* row, size_t* column) const;
    bool is_valid_position_for_number(size_t number, size_t row, size_t column) const;
    bool is_number_in_block(size_t number, size_t row, size_t column) const;
    bool is_number_in_row(size_t number, size_t row) const;
    bool is_number_in_column(size_t number, size_t column) const;
    void modify_at(size_t number, size_t row, size_t column);
    size_t at(size_t row, size_t column) const;

private:
    size_t m_grid[SUDOKU_LENGTH];
};

#endif // SOLVER_HPP
