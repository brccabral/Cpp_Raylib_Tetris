#pragma once
#include <raylib.h>
#include <vector>

class Grid
{
public:

    Grid();

    void Draw() const;
    [[nodiscard]] bool IsCellOutside(int row, int column) const;
    [[nodiscard]] bool IsCellEmpty(int row, int column) const;

    int grid[20][20] = {};

private:

    int numRows;
    int numCols;
    int cellSize;

    std::vector<Color> colors;
};
