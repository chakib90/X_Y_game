#include <iostream>
#include <vector>

using namespace std;

// Function to draw the game board
void draw_board(vector<char> board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
}

// Function to check if the game has been won
bool check_win(vector<char> board, char player) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player && board[i+1] == player && board[i+2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i+3] == player && board[i+6] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }
    return false;
}

// Function to check if the game is a tie
bool check_tie(vector<char> board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}

// Function to get the player's move
int get_move(vector<char> board, char player) {
    int move;
    cout << "Player " << player << "'s turn. Enter your move (1-9): ";
    cin >> move;
    while (board[move-1] != ' ') {
        cout << "That space is already taken. Enter your move (1-9): ";
        cin >> move;
    }
    return move - 1;
}

// Main function
int main() {
    vector<char> board(9, ' ');
    char player = 'X';
    bool game_over = false;
    while (!game_over) {
        // Draw the board
        draw_board(board);
        // Get the player's move
        int move = get_move(board, player);
        // Update the board
        board[move] = player;
        // Check if the game has been won
        if (check_win(board, player)) {
            cout << "Player " << player << " wins!" << endl;
            game_over = true;
        } else if (check_tie(board)) {
            cout << "The game is a tie." << endl;
            game_over = true;
        } else {
            // Switch to the other player
            player = (player == 'X') ? 'O' : 'X';
        }
    }
    // Draw the final board
    draw_board(board);
    return 0;
}
