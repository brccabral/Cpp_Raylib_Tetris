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
    int ClearFullRows();

    int grid[20][20] = {};

private:

    [[nodiscard]] bool IsRowFull(int row) const;
    void ClearRow(int row);
    void MoveRowDown(int row, int rowsNum);

    int numRows;
    int numCols;
    int cellSize;

    std::vector<Color> colors;
};
