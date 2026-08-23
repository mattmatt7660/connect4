#include <iostream>
#include <vector>
#include <limits>

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

int getColInput(const Board& board, char piece)
{
    int col;
    while (true)
    {
        std::cout << "Player " << piece << ", choose a column (1 - " << COLS << "): ";
        if (!(std::cin >> col))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Not a number. Try again. \n";
            continue;
        }
        col -= 1;

        if (!isValidMove(board, col))
        {
            std::cout << "Invalid move (full column/not in range). Try again.";
            continue;
        }
        return col;
    }
}

bool checkWinner(const Board& board, int row, int col, char piece)
{
    const int directions[4][2] = 
    {
        {0,1},  // horizontal
        {1,0},  // vertical
        {1,1},  // diagonal down right
        {1,-1}  // diagonal down left
    };

    for (auto& direction : directions)
    {
        int row_diff = direction[0];
        int col_diff = direction[1];
        int count = 1;

        // traverse forward in this direction
        int r = row + row_diff, c = col + col_diff;
        while (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == piece)    // valid pos
        {
            count++;
            r += row_diff;
            c += col_diff;
        }

        // traverse backwards in the same direction
        r = row - row_diff;
        c = col - col_diff;
        while (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == piece)    // valid pos
        {
            count++;
            r -= row_diff;
            c -= col_diff;
        }

        if (count >= 4) return true;
    }

    return false;


}



int main()
{
    std::cout << "Testing board creation: " << std::endl;
    Board board = createBoard();
    dropPiece(board, 3, 'X');
    dropPiece(board, 3, 'X');
    dropPiece(board, 2, 'X');
    printBoard(board);
    return 0;
}