#include <iostream>
#include <vector>

const int ROWS = 6;
const int COLS = 7;
const char EMPTY = '.';

using Board = std::vector<std::vector<char>>;

Board createBoard()
{
    return Board(ROWS, std::vector<char>(COLS,EMPTY));
}

int main()
{
    createBoard();
}