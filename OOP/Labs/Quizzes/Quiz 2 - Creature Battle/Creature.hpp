#ifndef CREATURE_HPP
#define CREATURE_HPP

class Creature {
private:
    char name[50];
    int health;
    char type[10];
    Move primaryAttack;
    Move secondaryAttack;
    int boostCounter;

public:
    Creature(const char n[], int h, const char t[], Move p, Move s);

    char* GetName();
    int GetHealth();
    char* GetType();

    void SetBoost();

    int GetBoost();

    void TakeDamage(int damage);

    void Attack(Creature &opponent);

    void Attack(Creature &opponent, int boostDamage);
};