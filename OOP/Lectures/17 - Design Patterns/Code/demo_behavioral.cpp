#include <iostream>
#include <vector>
using namespace std;

// Behavioral Patterns

/*
    Strategy Pattern
    Encapsulate algorithms as separate classes and make them interchangeable at runtime.

    - When you have multiple algorithms that should be interchangeable
    - When you want to change behavior at runtime
    - When you want to test algorithms independently
    - When you want to eliminate giant conditionals
*/

class DiscountStrategy {
public:
    virtual double apply(double price) = 0;
    virtual ~DiscountStrategy() {}
};

class NoDiscount : public DiscountStrategy {
public:
    double apply(double price) override {
        return price;
    }
};

class TenPercentDiscount : public DiscountStrategy {
public:
    double apply(double price) override {
        return price * 0.9;
    }
};

class HalfOffDiscount : public DiscountStrategy {
public:
    double apply(double price) override {
        return price * 0.5;
    }
};

class Checkout {
private:
    DiscountStrategy* strategy;

public:
    Checkout(DiscountStrategy* s) : strategy(s) {}

    void setStrategy(DiscountStrategy* s) {
        strategy = s;
    }

    double calculate(double price) {
        return strategy->apply(price);
    }
};

/*
    Observer
    A way for one object (Subject) to automatically notify multiple other objects (Observers) 
    when something changes — without hard-coding dependencies.
*/

class Observer {
public:
    virtual void update(float temp) = 0;
    virtual ~Observer() {}
};

class Subject {
public:
    virtual void addObserver(Observer* o) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};


class WeatherStation : public Subject {
private:
    float temperature;
    vector<Observer*> observers;

public:
    void addObserver(Observer* o) override {
        observers.push_back(o);
    }

    void setTemperature(float t) {
        temperature = t;
        notifyObservers();
    }

    void notifyObservers() override {
        for (auto o : observers)
            o->update(temperature);
    }
};


class PhoneDisplay : public Observer {
public:
    void update(float temp) override {
        cout << "[Phone] New Temp: " << temp << endl;
    }
};

class LEDDisplay : public Observer {
public:
    void update(float temp) override {
        cout << "[LED] New Temp: " << temp << endl;
    }
};



int main() {
    Checkout cart(new TenPercentDiscount());

    cout << cart.calculate(100) << endl;  // 90

    cart.setStrategy(new HalfOffDiscount());
    cout << cart.calculate(100) << endl;  // 50

    // Observer
    WeatherStation ws;
    PhoneDisplay phone; // observer
    LEDDisplay led;     // observer

    ws.addObserver(&phone);
    ws.addObserver(&led);

    ws.setTemperature(32.5);

}
