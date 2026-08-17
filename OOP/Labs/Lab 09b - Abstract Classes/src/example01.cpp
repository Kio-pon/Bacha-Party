#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract base class
class TradingCard {
protected:
    string name;
    int hp; // Hit Points

public:
    TradingCard(string n, int h) : name(n), hp(h) {}

    // Pure virtual function
    virtual void attack() = 0;

    // Common function for all cards
    void showInfo() {
        cout << "Card: " << name << " | HP: " << hp << endl;
    }

    // Virtual destructor (important for polymorphism)
    virtual ~TradingCard() = default;
};

// Derived class 1 — Pokémon card
class PokemonCard : public TradingCard {
public:
    PokemonCard(string n, int h) : TradingCard(n, h) {}

    void attack() override {
        cout << name << " used Thunderbolt!" << endl;
    }
};

// Derived class 2 — Yu-Gi-Oh! card
class YugiohCard : public TradingCard {
public:
    YugiohCard(string n, int h) : TradingCard(n, h) {}

    void attack() override {
        cout << name << " attacks with Dark Magic!" << endl;
    }
};

// Derived class 3 — Custom card
class CustomCard : public TradingCard {
public:
    CustomCard(string n, int h) : TradingCard(n, h) {}

    void attack() override {
        cout << name << " performs Code Slash!" << endl;
    }
};

int main() {
    // Create a vector of pointers to TradingCard (The Base Class)
    vector<TradingCard*> deck;

    // Dynamically add cards to the vector
    deck.push_back(new PokemonCard("Pikachu", 90));
    deck.push_back(new YugiohCard("Dark Magician", 2500));
    deck.push_back(new CustomCard("Code Knight", 1800));

    // Iterate through the vector and use polymorphism
    for (auto* card : deck) {
        card->showInfo();
        card->attack();
        cout << endl;
    }

    // Clean up dynamically allocated memory
    for (auto* card : deck) {
        delete card;
    }

    return 0;
}

