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

void printBoard(const Board& board)
{
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            std::cout << board[r][c] << " ";        // each entry in board and space
        }
        std::cout << "\n";
    }
    for (int c = 1; c <= COLS; ++c)
    {
        std::cout << c << " ";
    }
    std::cout << "\n\n";
}

bool isValidMove(const Board& board, int col)
{
    if (col < 0 || col >= COLS)
    {
        return false;
    }
    return board[0][col] == EMPTY;  // empty top row
}

int dropPiece(Board& board, int col, char piece)
{
    for (int r = ROWS - 1; r >= 0; --r)     // start from bottom up
    {
        if (board[r][col] == EMPTY)
        {
            board[r][col] = piece;
            return r;
        }
    }
    return -1;
}



int main()
{
    std::cout << "Testing board creation: " << std::endl;
    Board board = createBoard();
    printBoard(board);
    return 0;
}