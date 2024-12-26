#include "board.h"
using namespace std;

Board::Board()
{
    reset();
}

void Board::reset()
{
    char num = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = num++;
        }
    }
}

void Board::display() const
{
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j];
            if (j < 2)
            {
                cout << " |";
            }
        }
        cout << endl;
        if (i < 2)
        {
            cout << "---|---|---" << endl;
        }
    }
    cout << endl;
}

bool Board::isWin(char player) const
{
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }

    return false;
}

bool Board::isDraw() const
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }
    return true;
}

bool Board::makeMove(char player, int move)
{
    if (move < 1 || move > 9)
    {
        return false;
    }

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        return false;
    }
    else
    {
        board[row][col] = player;
        return true;
    }
}

int Board::getRandomMove()
{
    int availableMoves[9];
    int count = 0;

    for (int i = 1; i <= 9; ++i)
    {
        int row = (i - 1) / 3;
        int col = (i - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O')
        {
            availableMoves[count++] = i;
        }
    }

    if (count > 0)
    {
        return availableMoves[rand() % count];
    }
    return -1;
}
