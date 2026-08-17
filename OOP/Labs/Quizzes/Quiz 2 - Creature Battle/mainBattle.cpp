#include <iostream>
#include <cstring>
using namespace std;

#include "Move.hpp"
#inlcude "Creature.hpp"

int main() {
    // Create moves
    Move move1("Chainsaw", "Fire", 50, "It engulfs the arena in flames!");
    Move move2("BOOM!!", "Fire", 60, "It creates a colorful explosion!");
    Move move3("Beam", "Water", 40, "It shoots a stream of water!");
    Move move4("Spark", "Water", 45, "Electric sparks fly across the battlefield!");

    // Create creatures
    Creature denji("Denji", 100, "Water", move1, move3);
    Creature reze("Reze", 120, "Fire", move2, move4);

    cout << "Battle Start!" << endl;

    // Battle loop
    while (denji.GetHealth() > 0 && reze.GetHealth() > 0) {
        // Denji's turn
        if (denji.GetBoost() == 3) {
            denji.Attack(reze, 5);
            denji.SetBoost();
        } else {
            denji.Attack(reze);
            denji.SetBoost();
        }
        if (reze.GetHealth() <= 0) {
            cout << "Winner: " << denji.GetName() << " (Remaining Health: " 
                 << denji.GetHealth() << ")" << endl;
            break;
        }

        // Reze's turn
        if (reze.GetBoost() == 3) {
            reze.Attack(denji, 5);
            reze.SetBoost();
        } else {
            reze.Attack(denji);
            reze.SetBoost();
        }
        if (denji.GetHealth() <= 0) {
            cout << "Winner: " << reze.GetName() << " (Remaining Health: " 
                 << reze.GetHealth() << ")" << endl;
            break;
        }
    }
    return 0;
}
