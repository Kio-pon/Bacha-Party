#include <iostream>
#include <limits> // for numeric_limits

#define ROWS 3
#define COLS 3

using namespace std;

char BOARD[ROWS][COLS]{};

int getInt(const string& prompt); // a good example for taking in input the right way
void print_board();
bool legality(int row, int col);
bool win_check(char symbol);

int main(){
    int input;
    cout << "Welcome to tic-tac-toe!!!" << endl;
    cout << "Menu" << endl;
    cout << "Press 1 to Play" << endl;
    cout << "Press 2 to Exit (any input)" << endl;

    bool flag = true;
    while(flag){
        switch(input){
            case 2:
                cout << "Bye!" << endl;
                return 0;
            case 1:
                cout << "Game on!" << endl;
                break;
            default:
                cout << "Not valid" << endl;
                flag = false;
            }
    }
    
    bool turn = false;
    char symbols[2] = {'X', 'O'};
    while(true){
        cout << "---------------------------" << endl;
        cout << symbols[turn] << "'s turn!" << endl;
        cout << "---------------------------" << endl;
        print_board();
        cout << "---------------------------" << endl;
        int row = getInt("ROW: ") - 1; //cout << "ROW: "; cin >> row;
        int col = getInt("COL: ") - 1; //cout << "COL: "; cin >> col;

        if (legality(row, col)){
            BOARD[row][col] = symbols[turn];
            if(win_check(symbols[turn])){
                print_board();
                cout << symbols[turn] << "'s wins!!!" << endl;
                break;
            }
            turn = not(turn);
        }
    }
}

// Special input function that controls for
int getInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) { // this line checks if you have mistakenly taken wrong input (maybe a string)
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter an integer." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear extra characters
            return value;
        }
    }
}

void print_board(){
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            cout << BOARD[r][c] << " ";
        }
        cout << endl;
    }
}

bool legality(int row, int col){
    if(row > ROWS || col > ROWS){
        cout << "Outside of range!" << endl;
        return false;
    }
    if(row < 0 || col < 0){
        cout << "Outside of range!" << endl;
        return false;
    }
    if(BOARD[row][col] != '.'){
        cout << "Already taken!" << endl;
        return false;
    }
    return true;
}

bool win_check(char symbol){
    // Check rows and columns
    for (int i = 0; i < ROWS; i++) {
        if (BOARD[i][0] == symbol && BOARD[i][1] == symbol && BOARD[i][2] == symbol) return true;
        if (BOARD[0][i] == symbol && BOARD[1][i] == symbol && BOARD[2][i] == symbol) return true;
    }
    // Check diagonals
    if (BOARD[0][0] == symbol && BOARD[1][1] == symbol && BOARD[2][2] == symbol) return true;
    if (BOARD[0][2] == symbol && BOARD[1][1] == symbol && BOARD[2][0] == symbol) return true;
    return false;
}