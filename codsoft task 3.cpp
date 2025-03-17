#include <iostream>
using namespace std;

// Function to print the game board
void printBoard(char board[3][3]) {
    cout << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  // Check row
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { // Check column
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {  // If there's any empty cell, it's not a draw
                return false;
            }
        }
    }
    return true;  // All cells are filled and no winner
}

// Function to check if the move is valid
bool isValidMove(char board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Main function to run the game
void playGame() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int row, col;
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);
        cout << "Player " << currentPlayer << "'s turn." << endl;

        // Get player input
        cout << "Enter row (0, 1, 2): ";
        cin >> row;
        cout << "Enter column (0, 1, 2): ";
        cin >> col;

        if (isValidMove(board, row, col)) {
            board[row][col] = currentPlayer;
        } else {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        }
        // Check if the game is a draw
        else if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            gameOver = true;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        playGame();  // Restart the game
    } else {
        cout << "Thanks for playing!" << endl;
    }
}

int main() {
    playGame();  // Start the game
    return 0;
}
