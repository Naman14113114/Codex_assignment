#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>


struct TicTacToe {
    char grid[3][3];
};

bool checkWin(const TicTacToe &game) {
    for (int i = 0; i < 3; i++) {
        if (game.grid[i][0] != ' ' && game.grid[i][0] == game.grid[i][1] && game.grid[i][1] == game.grid[i][2])
            return true;
        if (game.grid[0][i] != ' ' && game.grid[0][i] == game.grid[1][i] && game.grid[1][i] == game.grid[2][i])
            return true;
    }
    if (game.grid[0][0] != ' ' && game.grid[0][0] == game.grid[1][1] && game.grid[1][1] == game.grid[2][2])
        return true;
    if (game.grid[0][2] != ' ' && game.grid[0][2] == game.grid[1][1] && game.grid[1][1] == game.grid[2][0])
        return true;
    return false;
}

bool checkDraw(const TicTacToe &game) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (game.grid[i][j] == ' ')
                return false;
    return true;
}

void display(const TicTacToe &game) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            std::cout << game.grid[i][j] << ' ';
        std::cout << std::endl;
    }
}

bool update(TicTacToe &game, int move, char symbol) {
    if (move < 1 || move > 9)
        return false;
    move--;
    int row = move / 3;
    int col = move % 3;
    if (game.grid[row][col] != ' ')
        return false;
    game.grid[row][col] = symbol;
    return true;
}

int main() {
    TicTacToe game;
    char currentSymbol = 'X';
    srand(time(NULL));
    currentSymbol = rand() % 2 == 0 ? 'X' : 'O';
    bool isWon = false;
    bool isDraw = false;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            game.grid[i][j] = ' ';

    // Your main game loop should be here.

    return 0;
}

