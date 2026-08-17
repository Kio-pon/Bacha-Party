#include <iostream>
#include <string>
#include <vector>
using namespace std;

// -------------------- Exhibit --------------------
class Exhibit {
    string name;
    int capacity;
public:
    void setExhibit(string n, int c) { name = n; capacity = c; }
    void display() { cout << "Exhibit: " << name << " (Capacity: " << capacity << ")\n"; }
};

// -------------------- Animal Hierarchy --------------------
class Animal {
protected:
    string name;
    int age;
public:
    void setAnimal(string n, int a) { name = n; age = a; }
    virtual void display() { cout << "Animal: " << name << ", Age: " << age << endl; }
};

class Fish : public Animal {
public:
    void display() override { cout << "Fish: " << name << ", Age: " << age << endl; }
};

class Mammal : public Animal {
public:
    void display() override { cout << "Mammal: " << name << ", Age: " << age << endl; }
};

// -------------------- Show --------------------
class Show {
    string title;
    vector<Animal*> animals;  // Aggregation: Show uses existing animals
public:
    void setShow(string t) { title = t; }
    void addAnimal(Animal* a) { animals.push_back(a); }

    string getTitle() const { return title; }

    void display() {
        cout << "Show: " << title << "\nAnimals performing:\n";
        for (auto a : animals) a->display();
    }
};

// -------------------- Zone --------------------
class Zone {
    string theme;
    vector<Exhibit> exhibits; // Composition: Zone owns Exhibits
    vector<Show*> shows;      // Aggregation: Zone references existing Shows
public:
    void setZone(string t) { theme = t; }

    void addExhibit(const Exhibit& e) { exhibits.push_back(e); }
    void addShow(Show* s) { shows.push_back(s); }

    void display() {
        cout << "\nZone: " << theme << "\n";
        cout << " Exhibits:\n";
        for (auto& e : exhibits) e.display();
        cout << " Shows:\n";
        for (auto s : shows) cout << "  - " << s->getTitle() << endl;
    }
};

// -------------------- Visitor --------------------
class Visitor {
    string name;
    string contact;
    vector<Show*> bookedShows; // Association: persistent link (Visitor remembers Shows)
public:
    void setVisitor(string n, string c) { name = n; contact = c; }

    // Persistent association (stores reference)
    void bookShow(Show* s) { bookedShows.push_back(s); }

    // Temporary association (interaction without storage)
    void viewShow(Show& s) {
        cout << name << " is currently watching " << s.getTitle() << endl;
    }

    void display() {
        cout << "\nVisitor: " << name << "\nContact: " << contact << "\nBooked Shows:\n";
        for (auto s : bookedShows)
            cout << "  - " << s->getTitle() << endl;
    }
};

// -------------------- KioskSystem --------------------
class KioskSystem {
    double totalRevenue = 0.0;
    vector<Visitor*> visitors; // Association: interacts with Visitors
public:
    void registerVisitor(Visitor* v) { visitors.push_back(v); }

    void sellTicket(Visitor& v, Show& s) {
        totalRevenue += 50.0; // example price
        v.bookShow(&s);
        cout << "Ticket sold to " << " for show " << s.getTitle() << endl;
    }

    void display() {
        cout << "\nKiosk System: Total Revenue $" << totalRevenue << endl;
    }
};

// -------------------- Aquarium --------------------
class Aquarium {
    string name;
    vector<Zone> zones;  // Composition: Aquarium owns Zones
    KioskSystem kiosk;   // Composition: Aquarium owns KioskSystem
public:
    void setAquarium(string n) { name = n; }

    void addZone(const Zone& z) { zones.push_back(z); }

    KioskSystem& getKiosk() { return kiosk; }

    void display() {
        cout << "\n=== Aquarium: " << name << " ===\n";
        for (auto& z : zones) z.display();
        kiosk.display();
    }
};

// -------------------- Main Function (Demo) --------------------
int main() {
    // Aquarium setup
    Aquarium aq;
    aq.setAquarium("AquaRealm Interactive Park");

    // Zones
    Zone predatorBay;
    predatorBay.setZone("Predator Bay");

    Exhibit sharkTunnel;
    sharkTunnel.setExhibit("Shark Tunnel", 200);
    predatorBay.addExhibit(sharkTunnel);

    // Animals
    Fish shark;
    shark.setAnimal("Great White Shark", 8);

    Mammal dolphin;
    dolphin.setAnimal("Bottlenose Dolphin", 5);

    // Shows
    Show sharkShow;
    sharkShow.setShow("Shark Feeding Show");
    sharkShow.addAnimal(&shark);

    Show dolphinShow;
    dolphinShow.setShow("Dolphin Splash Show");
    dolphinShow.addAnimal(&dolphin);

    predatorBay.addShow(&sharkShow);
    predatorBay.addShow(&dolphinShow);

    aq.addZone(predatorBay);

    // Visitors
    Visitor v1, v2;
    v1.setVisitor("Alice", "alice@email.com");
    v2.setVisitor("Bob", "bob@email.com");

    // Kiosk interactions
    KioskSystem& kiosk = aq.getKiosk();
    kiosk.registerVisitor(&v1);
    kiosk.registerVisitor(&v2);

    // Association examples
    kiosk.sellTicket(v1, sharkShow);
    v2.viewShow(dolphinShow);  // temporary association (not stored)

    // Display everything
    aq.display();
    v1.display();
    v2.display();

    return 0;
}







