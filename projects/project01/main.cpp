#include <iostream>
#include <vector>
#include "main.h"

//const int BLANK{ 0 };
//const int X{ 1 };
//const int O{ 2 };
enum class Cell{BLANK,X,O};
enum class GameStatus{ONGOING,X_WON,O_WON,DRAW};

Cell getCurrentToken(const std::vector<std::vector<Cell>>& board);

bool isFull(const std::vector<std::vector<Cell>>& board)
{
    for (auto& row : board)
        for (auto elem : row)
            if (elem == Cell::BLANK)
                return false;
    return true;
}

GameStatus gameStatus(const std::vector<std::vector<Cell>>& board)
{
    int size=board.size();
    for (int row{ 0 }; row < size; row++)
    {
        for (int col{ 0 }; col < size - 4; col++)
        {
            if (board.at(row).at(col) != Cell::BLANK)
            {
                auto token = board.at(row).at(col);
                bool isWinner = true;
                for (int i{ 1 }; i < 5; i++)
                {
                    if (board.at(row).at(col + i) != token)
                    {
                        isWinner = false;
                        break;
                    }
                }
                if (isWinner)return static_cast<GameStatus>(token);
            }
        }
    }
    for (int row{ 0 }; row < size-4; row++)
    {
        for (int col{ 0 }; col < size; col++)
        {
            if (board.at(row).at(col) != Cell::BLANK)
            {
                auto token = board.at(row).at(col);
                bool isWinner = true;
                for (int i{ 1 }; i < 5; i++)
                {
                    if (board.at(row+1).at(col) != token)
                    {
                        isWinner = false;
                        break;
                    }
                }
                if (isWinner)return static_cast<GameStatus>(token);
            }
        }
    }
    for (int row{ 0 }; row < size - 4; row++)
    {
        for (int col{ 0 }; col < size-4; col++)
        {
            if (board.at(row).at(col) != Cell::BLANK)
            {
                auto token = board.at(row).at(col);
                bool isWinner = true;
                for (int i{ 1 }; i < 5; i++)
                {
                    if (board.at(row + i).at(col+i) != token)
                    {
                        isWinner = false;
                        break;
                    }
                }
                if (isWinner)return static_cast<GameStatus>(token);
            } 
            if (board.at(row+4).at(col) != Cell::BLANK)
            {
                auto token = board.at(row+4).at(col);
                bool isWinner = true;
                for (int i{ 1 }; i < 5; i++)
                {
                    if (board.at(row + 4-i).at(col+i) != token)
                    {
                        isWinner = false;
                        break;
                    }
                }
                if (isWinner)return static_cast<GameStatus>(token);
            }
        }
    }

    if (isFull(board))return GameStatus::DRAW;

    return GameStatus::ONGOING;
}



std::vector<std::vector<Cell>> makeBoard(int size=7)
{
    std::vector<std::vector<Cell>> board(size, std::vector<Cell>(size,Cell::BLANK));
    return board;
}

void horizontalBar(int size)
{
    // Print horizontal line
    std::cout << " +";
    for (int col = 0; col < size; ++col)
    {
        std::cout << "---+";
    }
    std::cout << "\n";
}

void printBoard(const std::vector<std::vector<Cell>>& board)
{
    int size = board.size();

    // Print column numbers
    std::cout << "   ";
    for (int col = 1; col <= size; ++col)
    {
        std::cout << col << "   ";
    }
    std::cout << "\n";

    // Print board with row numbers
    for (int row = 0; row < size; ++row)
    {
        horizontalBar(size);

        // Print row number and board content
        std::cout << row + 1 << "|";
        for (int col = 0; col < size; ++col)
        {
            char symbol = ' ';
            if (board[row][col] == Cell::X)
                symbol = 'X';
            else if (board[row][col] == Cell::O)
                symbol = 'O';

            std::cout << " " << symbol << " |";
        }
        std::cout << "\n";
    }

    horizontalBar(size);
}

bool play(std::vector<std::vector<Cell>>& board, int row, int col)
{
    int width=board.at(0).size();
    int height=board.size();
    Cell token{ getCurrentToken(board) };
    if (row >= height || row < 0 || col >= width || col < 0) return false;

    Cell& cell{ board.at(row).at(col) };
    if (cell !=Cell::BLANK)return false;

    cell = token;
}

Cell getCurrentToken(const std::vector<std::vector<Cell>>& board)
{

    int count{ 0 };
    for (auto& row : board)
        for (auto& cell : row)
            count+=cell !=Cell::BLANK;
    if (count % 2 == 0) return Cell::X;
    return Cell::O;
}

int main()
{
    auto board{ makeBoard() };
    while (gameStatus(board)==GameStatus::ONGOING)
    {
        printBoard(board);
        Cell token{getCurrentToken(board)};
        if(token==Cell::X)
            std::cout << "Player X's turn!\n";
        else
            std::cout << "Player O's turn!\n";
        std::cout << "row: ";
        int row;
        std::cin >> row;
        std::cout << "col: ";
        int col;
        std::cin >> col;
        bool playWorked{ play(board,row-1,col-1) };
        if(!playWorked)std::cout << "bad move\n";
    }
    std::cout << int(gameStatus(board)) << "\n";





}
