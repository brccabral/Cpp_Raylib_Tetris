#include <raylib.h>
#include "grid.h"

int main()
{
    constexpr Color darkBlue{44, 44, 127, 255};

    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;

    Grid grid;

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
