#include "raylib.h"
#include "solver.hpp"
#include <iostream>

int main(void) {
    InitWindow(1600, 900, "sudoku-solver-GUI");
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);
    Solver solver;

    // Main loop
    while (!WindowShouldClose()) {
        // int screenWidth = GetScreenWidth();
        // int screenHeight = GetScreenHeight();
        
        // Input
        

        // Draw
        BeginDrawing();

            ClearBackground(DARKGRAY);

        EndDrawing();
    }


    CloseWindow();
}