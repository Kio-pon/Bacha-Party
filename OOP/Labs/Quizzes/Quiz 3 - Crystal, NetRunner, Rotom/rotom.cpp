int main() {
    // Fan 
    Fan fan1(500, 10, true, "medium");
    cout << "Fan Energy: " << fan1.CalculateEnergy() << endl;
    // Expected Output: 500/10 + 75 = 50 + 75 = 125

    // Heater
    Heater heater1(1000, 20, true, 4);
    cout << "Heater Energy: " << heater1.CalculateEnergy() << endl;
    // Expected Output: (1000/20) + (4 * 30) = 50 + 120 = 170

    // Refrigerator (door closed)
    Refrigerator fridge1(1200, 60, true, 3.5, false);
    cout << "Refrigerator Energy (door closed): " << fridge1.CalculateEnergy() << endl;
    // Expected Output: 1200/60 = 20

    // Refrigerator (door opened)
    fridge1.ToggleDoor();
    cout << "Refrigerator Energy (door open): " << fridge1.CalculateEnergy() << endl;
    // Expected Output: 1200/60 + 20 = 20 + 20 = 40

    // Fan turned off
    fan1.ToggleSwitch();
    cout << "Fan Energy (after turning off): " << fan1.CalculateEnergy() << endl;
    // Expected Output: 0

    return 0;
}