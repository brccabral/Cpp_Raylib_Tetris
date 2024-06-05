#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:

    Grid();

    void Draw();
    
    int grid[20][20] = {};

private:
    static std::vector<Color> getCellColors();

    int numRows;
    int numCols;
    int cellSize;

    std::vector<Color> colors;
};
