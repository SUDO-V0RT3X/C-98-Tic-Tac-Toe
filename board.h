#include <iostream>
#include <cstdlib>

using namespace std;

class Board
{
private:
    char board[3][3];

public:
    Board();
    void reset();
    void display() const;
    bool isWin(char player) const;
    bool isDraw() const;
    bool makeMove(char player, int move);
    int getRandomMove();
};