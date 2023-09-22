#include "raylib.h"
#include "solver.h"
#include "stdio.h"

int main(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "sudoku-solver-GUI");
    ClearWindowState(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    grid_type grid[GRID_SIZE];
    for (size_t i = 0; i < GRID_SIZE; ++i) {
        grid[i] = 0;
    }
    grid_solve(grid);

    // Main loop
    while (!WindowShouldClose()) {
        
        // Input
        

        // Draw
        BeginDrawing();

            ClearBackground(DARKGRAY);

            grid_draw(grid);

        EndDrawing();
    }


    CloseWindow();
}