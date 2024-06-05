#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(const double interval)
{
    const double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    constexpr Color darkBlue{44, 44, 127, 255};

    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;

    Game game;

    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        game.handleInput();
        if (EventTriggered(0.3))
        {
            game.moveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
