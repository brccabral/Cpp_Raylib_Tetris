#pragma once
#include <map>
#include <vector>
#include "colors.h"
#include "position.h"

class Block
{
public:

    Block();

    void Draw();
    void Move(int rows, int columns);
    std::vector<Position> getCellPositions();
    void Rotate();
    void UndoRotate();

    int id = 0;
    std::map<int, std::vector<Position>> cells;

private:

    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};

class LBlock : public Block
{
public:

    LBlock();
};

class JBlock : public Block
{
public:

    JBlock();
};

class IBlock : public Block
{
public:

    IBlock();
};

class OBlock : public Block
{
public:

    OBlock();
};

class SBlock : public Block
{
public:

    SBlock();
};

class TBlock : public Block
{
public:

    TBlock();
};

class ZBlock : public Block
{
public:

    ZBlock();
};
