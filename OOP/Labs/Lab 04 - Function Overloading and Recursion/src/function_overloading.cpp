#include <iostream>

// Attack with just the weapon
void attack(const char* weapon) {
    std::cout << "Hornet strikes swiftly with her " << weapon << "!"
              << std::endl;
}

// Attack with weapon and special move
void attack(const char* weapon, const char* move) {
    std::cout << "Hornet uses " << move << " with her " << weapon << "!"
              << std::endl;
}

// Attack with weapon and power level
void attack(const char* weapon, int power) {
    std::cout << "Hornet performs a mighty strike with her " << weapon
              << " and deals " << power << " damage!" << std::endl;
}

int main() {
    attack("Needle");               // calls attack(const char*)
    attack("Needle", "Silk Bind");  // calls attack(const char*, const char*)
    attack("Needle", 5);            // calls attack(const char*, int)

    return 0;
}
