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

    constexpr int screenWidth = 500;
    constexpr int screenHeight = 620;

    Game game;

    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    const Font font = LoadFontEx("resources/monogram.ttf", 64, nullptr, 0);

    while (!WindowShouldClose())
    {
        game.handleInput();
        if (EventTriggered(0.2))
        {
            game.moveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);

        DrawTextEx(font, "Score", {365, 50}, 38, 2, RAYWHITE);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
