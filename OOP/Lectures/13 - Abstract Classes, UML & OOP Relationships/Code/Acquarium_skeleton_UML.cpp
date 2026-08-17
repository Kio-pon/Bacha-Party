#include <string>
#include <vector>
using namespace std;

// -------------------- Exhibit --------------------
class Exhibit {
    string name;
    int capacity;
};

// -------------------- Animal Hierarchy --------------------
class Animal {
protected:
    string name;
    int age;
};

class Fish : public Animal {};
class Mammal : public Animal {};

// -------------------- Show --------------------
class Show {
    string title;
    vector<Animal*> animals; // Aggregation: uses existing Animals
public:
    void addAnimal(Animal* a);
};

// -------------------- Zone --------------------
class Zone {
    string theme;
    vector<Exhibit> exhibits; // Composition: Zone owns Exhibits
    vector<Show*> shows;      // Aggregation: Zone references existing Shows
public:
    void addExhibit(const Exhibit& e);
    void addShow(Show* s);
};

// -------------------- Visitor --------------------
class Visitor {
    string name;
    string contact;
    vector<Show*> bookedShows; // Association: Visitor books Shows
public:
    void bookShow(Show* s);        // Persistent association
    void viewShow(Show& s);        // Temporary association
};

// -------------------- KioskSystem --------------------
class KioskSystem {
    double totalRevenue;
    vector<Visitor*> visitors; // Association: interacts with Visitors
public:
    void registerVisitor(Visitor* v);
    void sellTicket(Visitor& v, Show& s);
};

// -------------------- Aquarium --------------------
class Aquarium {
    string name;
    vector<Zone> zones;  // Composition: Aquarium owns Zones
    KioskSystem kiosk;   // Composition: Aquarium owns KioskSystem
public:
    void addZone(const Zone& z);
    KioskSystem& getKiosk();
};
