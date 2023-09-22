#include <stdbool.h>
#include <stddef.h>


#define N 9
#define GRID_SIZE (N * N)
#define BLOCK_SIZE (N / 3)
#define GRID_BLANK 0
#define grid_type size_t
#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900


void modify_grid_at(grid_type grid[GRID_SIZE], grid_type row, grid_type column, grid_type number);
grid_type grid_at(grid_type grid[GRID_SIZE], grid_type row, grid_type column);
bool is_number_in_row(grid_type grid[GRID_SIZE], grid_type number, grid_type row);
bool is_number_in_column(grid_type grid[GRID_SIZE], grid_type number, grid_type column);
bool is_number_in_block(grid_type grid[GRID_SIZE], grid_type number, grid_type row, grid_type column);
bool is_valid_position_for_number(grid_type grid[GRID_SIZE], grid_type number, grid_type row, grid_type column);
bool is_grid_full(grid_type grid[GRID_SIZE], grid_type* row, grid_type* column);
bool grid_solve(grid_type grid[GRID_SIZE]);
void grid_draw(grid_type grid[GRID_SIZE]);
