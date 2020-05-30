#include <iostream>
#include <stdlib.h>
using namespace std;

string board[9];
string player = "X";

void createBoard();
void printBoard();
void turn();
bool winner();
int cpu();
int moves = 0;
int cpuMove;

int main()
{
    int location;
    createBoard();
    cout << "Welcome, to tic tac toe! Player X will start first" << endl;
    while (!winner()) {
        cout << "It's humans turn. Choose location (1-9) ";
        cin >> location;
        if (location > 0 && location < 10 && board[location - 1] == " ") {
            board[location - 1] = player;
            moves++;
        }
        else {
            cout << "This location is not accepted. " << endl;
            continue;
        }
        printBoard();
        turn();
        cout << "It's computers turn. " << endl;
        while (true) {
            location = cpu();
            if (board[location - 1] == " ") {
                cout << "Cpu debug location " << location << endl;
                board[location - 1] = player;
                printBoard();
                turn();
                break;
            }
            else {
                continue;
            }
        }
        
    }

    system("pause");
}

void createBoard() {
    for (int i = 0; i < 9; i++) {
        board[i] = " ";
    }
}

void printBoard() {
    cout << "|" + board[0] + "|" + board[1] + "|" + board[2] + "|" << endl;
    cout << "|" + board[3] + "|" + board[4] + "|" + board[5] + "|" << endl;
    cout << "|" + board[6] + "|" + board[7] + "|" + board[8] + "|" << endl;
}

void turn() {
    if (player == "X") {
        player = "O";
    }
    else if (player == "O") {
        player = "X";
    }
}

bool winner() {
    for (int i = 0; i < 9; i++) {
        string line = "";
        switch (i) {
        case 0:
            line = board[0] + board[1] + board[2];
            break;
        case 1:
            line = board[3] + board[4] + board[5];
            break;
        case 2:
            line = board[6] + board[7] + board[8];
            break;
        case 3:
            line = board[0] + board[3] + board[6];
            break;
        case 4:
            line = board[1] + board[4] + board[7];
            break;
        case 5:
            line = board[2] + board[5] + board[8];
            break;
        case 6:
            line = board[0] + board[4] + board[8];
            break;
        case 7:
            line = board[2] + board[4] + board[6];
            break;
        default:
            break;
        }
        if (line == "XXX") {
            cout << "X wins!" << endl;
            return true;
        }
        else if (line == "OOO") {
            cout << "O wins!" << endl;
            return true;
        }
        else if (moves == 9) {
            cout << "Its a draw!" << endl;
            return true;
        }
        
    }
    return false;
}

int cpu() {
    cpuMove = rand() % 10;
    return cpuMove;
}