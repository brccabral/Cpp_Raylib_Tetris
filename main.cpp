#include <raylib.h>
#include "grid.h"

int main()
{
    constexpr Color darkBlue{44, 44, 127, 255};

    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;

    Grid grid;
    grid.grid[0][0] = 1;
    grid.grid[3][5] = 4;
    grid.grid[17][8] = 7;

    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);

        grid.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
