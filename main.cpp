#include "board.h"

using namespace std;

int main() {
    char userChoice;
    do {
        Board gameBoard;
        char userPlayer, computerPlayer;

        cout << ".......... Welcome to Tic Tac Toe! ..........\n\n";
        cout << "Do you want to be X or O? : ";
        cin >> userPlayer;

        while (userPlayer != 'X' && userPlayer != 'O') {
            cout << "You can only choose X or O: ";
            cin >> userPlayer;
        }

        computerPlayer = (userPlayer == 'X') ? 'O' : 'X';
        char currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            gameBoard.display();

            if (currentPlayer == userPlayer) {
                int move;
                cout << "Your turn. Enter the number of the cell where you want to place your mark: ";
                cin >> move;

                while (!gameBoard.makeMove(currentPlayer, move)) {
                    cout << "Please enter an empty cell number: ";
                    cin >> move;
                }
            } else {
                cout << "Computer's turn.\n";
                int move = gameBoard.getRandomMove();
                gameBoard.makeMove(currentPlayer, move);
            }

            if (gameBoard.isWin(currentPlayer)) {
                gameBoard.display();
                if (currentPlayer == userPlayer) {
                    cout << "You win!\n";
                } else {
                    cout << "I win!\n";
                }
                gameOver = true;
            } else if (gameBoard.isDraw()) {
                gameBoard.display();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Do you want to play another game? (Y / N): ";
        cin >> userChoice;

    } while (userChoice == 'y' || userChoice == 'Y');

    cout << ".......... Thank you for playing! Goodbye!..........\n\n";
    return 0;
}
