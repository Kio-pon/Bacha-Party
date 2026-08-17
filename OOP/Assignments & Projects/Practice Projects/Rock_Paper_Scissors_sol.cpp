#include <iostream>
#include <random>
#include <string>
using namespace std;

enum sign {ROCK, PAPER, SCISSOR, UNKNOWN};
enum outcome {DRAW, WIN, LOSS, NORESULT};

outcome result(sign user, sign comp){
    if (user == UNKNOWN) return NORESULT;
    else if (user == comp) return DRAW;
    else if ((user == ROCK && comp == SCISSOR) ||
            (user == PAPER && comp == ROCK) ||
            (user == SCISSOR && comp == PAPER)) return WIN;
    else return LOSS;
}

sign string_to_sign(const string& move){
    if (move == "r")        return ROCK;
    else if (move == "p")   return PAPER;
    else if (move == "s")   return SCISSOR;
    else                    return UNKNOWN;
}

string sign_to_string(sign move){
    switch (move) {
        case ROCK:      return "r"; 
        case PAPER:     return "p";
        case SCISSOR:   return "s";
        default:        return "?";
    }
}

void interface(sign user, sign comp, outcome final){
    cout << "You: " << sign_to_string(user);
    cout << " | Computer: " << sign_to_string(comp);
    cout << " --> ";
    switch (final){
    case DRAW:
        cout << "Draw!" << endl;
        break;
    case WIN:
        cout << "You win!" << endl;
        break;
    case LOSS:
        cout << "You lose!" << endl;
        break;
    default:
        cout << "Wrong input!" << endl;
        break;
    }
}



int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " r p s ..." << endl;
        return 1; // Notice its not return 0, its not a typo. Can you find out why it 1 instead of 0;
    }

    // Random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 2);

    for (int i = 1; i < argc; i++) {
        // User
        string move = argv[i];
        sign user = string_to_sign(move);

        // Computer
        int random = dist(gen); 
        sign comp = static_cast<sign>(random);

        // find outcome
        outcome final = result(user, comp);
        interface(user, comp, final);
    }
    return 0;
}
