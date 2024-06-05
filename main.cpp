#include <raylib.h>
#include "block.h"
#include "grid.h"

int main()
{
    constexpr Color darkBlue{44, 44, 127, 255};

    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;

    Grid grid;

    auto block = TBlock();
    block.Move(4, 3);

    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);

        grid.Draw();
        block.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
