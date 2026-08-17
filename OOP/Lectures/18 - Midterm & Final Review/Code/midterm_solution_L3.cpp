#include <iostream>
#include <cmath>    // for ceil()
using namespace std;

class SolarUnit {
private:
    double panelArea;
    double efficiency;
    double sunlightHours;
    double costPerUnit;

public:
    // Function to take input
    void input() {
        cout << "Enter panel area (meter square), efficiency (0 - 1), sunlight hours, and cost per unit (Rs): ";
        cin >> panelArea >> efficiency >> sunlightHours >> costPerUnit;
    }

    // Optional: function to update efficiency only
    void setEfficiency() {
        cout << "Please enter efficiency again (0 - 1): ";
        cin >> efficiency;
    }

    // Function to calculate daily energy
    double getDailyEnergy() const {
        // Energy = panelArea × sunlightHours × efficiency × 1000
        return panelArea * sunlightHours * efficiency * 1000;
    }

    // Function to print details
    void print(double energyPerUnit, int unitsRequired, double totalCost) const {
        cout << "\nSolar Unit Details:\n";
        cout << "Panel Area: " << panelArea << " meter square" << endl;
        cout << "Efficiency: " << efficiency << endl;
        cout << "Sunlight Hours: " << sunlightHours << endl;
        cout << "Energy per Unit per Day: " << energyPerUnit << " Wh" << endl;
        cout << "Units Required: " << unitsRequired << endl;
        cout << "Total Installation Cost: Rs " << totalCost << endl;
    }

    // Getter for efficiency (to check validation)
    double getEfficiency() const { return efficiency; }
    double getCostPerUnit() const { return costPerUnit; }
};

int main() {
    double requiredEnergy;
    cout << "Enter total household energy requirement (in Wh): ";
    cin >> requiredEnergy;

    SolarUnit su;
    su.input();

    // Validate efficiency
    while (su.getEfficiency() <= 0 || su.getEfficiency() > 1) {
        cout << "Error: Efficiency must be between 0 and 1.\n";
        su.setEfficiency();  // only re-enter efficiency instead of all inputs again
    }

    double energyPerUnit = su.getDailyEnergy();
    int unitsRequired = ceil(requiredEnergy / energyPerUnit);
    double totalCost = unitsRequired * su.getCostPerUnit();

    su.print(energyPerUnit, unitsRequired, totalCost);

    return 0;
}
