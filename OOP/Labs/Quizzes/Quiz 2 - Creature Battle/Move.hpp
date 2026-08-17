#ifndef CREATURE_HPP
#define CREATURE_HPP

class Move {
private:
    char name[50];
    char type[10];
    int baseDamage;
    char effect[100];

public:

    Move(const char n[], const char t[], int dmg, const char e[]);

    int getBaseDamage();
    char* getType();

    void DisplayName();

    void DisplayEffect();

    char* getName();
};