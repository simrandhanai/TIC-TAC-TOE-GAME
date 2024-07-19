#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char marker;
int player;

void displayBoard() {
    cout << "________________\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n________________\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = marker;
        return true;
    } 
    else {
        return false;
    }
}

int winner() {
    //row
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return player;
        }
    }
    //column
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return player;
        }
    }
   //diagnal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return player;
    }
    return 0;
}

void swap() {
    if (marker == 'X') marker = 'O';
    else marker = 'X';

    if (player == 1) player = 2;
    else player = 1;
}

void game() {
    cout << "Player 1, enter your marker(O): ";
    char marker_p1;
    cin >> marker_p1;

    player = 1;
    marker = marker_p1;

    displayBoard();

    int playerwon;

    for (int i = 0; i < 9; i++) {
        cout<<"player "<< player << " Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot.! Try again.!!\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot occupied! Try again.!!\n";
            i--;
            continue;
        }

        displayBoard();

        playerwon = winner();

        if (playerwon == 1) {
            cout << "CONGRATS.!! Player 1 won!!\n";
            break;
        }
        if (playerwon == 2) {
            cout << "CONGRATS.!! Player 2 won!!\n";
            break;
        }

        swap();
    }

    if (playerwon == 0) {
        cout << "DRAW.!!";
    }
}

int main() {
    game();
    return 0;
}
