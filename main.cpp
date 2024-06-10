#include <iostream>
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
    constexpr int screenWidth = 500;
    constexpr int screenHeight = 620;


    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    Game game;
    const Font font = LoadFontEx("resources/Font/monogram.ttf", 64, nullptr, 0);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);

        game.handleInput();
        if (EventTriggered(0.2))
        {
            game.moveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);

        DrawTextEx(font, "Score", {365, 15}, 38, 2, RAYWHITE);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3f, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        const auto [scoreX, scoreY] = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {320 + (170 - scoreX) / 2, 65}, 38, 2, RAYWHITE);

        DrawTextEx(font, "Next", {370, 175}, 38, 2, RAYWHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3f, 6, lightBlue);

        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, RAYWHITE);
        }

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
