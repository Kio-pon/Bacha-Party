#include <iostream>
using namespace std;

/*
    Design patterns are not really prescriptive - but they do often appear naturally when engineering solutions to 
    common problems. They are more useful as a vocabulary for describing solutions rather than being the solutions in 
    and of themselves

    1. this is a way to increase the level of abstraction when discussing solutions among humans 
    (any senior engineer should be familiar with the most commons ones)
    

    2. this is a way to document code by naming classes or functions (if your class has "visitor" as 
    part of its name, I have a strong hint of what I can expect it to do)

    3. usually, each language will have its own implementation of a design pattern (the singleton (anti-)pattern is 
    coded differently in Java and in modern C++).

    4. this is software engineering, not dogma (your implementation may vary depending on your needs, and you should not 
    feel constrained to copy/paste the exact implementation of a design pattern)

    So, having solutions in Java is actually "smart", as most programmers can read simple Java code, 
understand how it works, and translate them into their language of choice.
*/


/*
    Types:
    1. Creational Patterns
    2. Structural Patterns
    3. Behavioral Patterns

*/

// Creational Patterns

/*
    Singleton is nothing more than:
    1. A class that only ever has one instance
    2. Globally accessible
    3. Instance is created exactly once (lazily or eagerly)

    It’s essentially a controlled global variable wrapped in a class.

    Singleton is acceptable when you truly need exactly one instance.
    It’s bad when used as a lazy shortcut for global state.
*/

class AdmissionOffice {
private:
    std::string admitted[100];
    int count = 0;

    AdmissionOffice() {}  // private constructor

    AdmissionOffice(const AdmissionOffice&) = delete;
    AdmissionOffice& operator=(const AdmissionOffice&) = delete;

public:
    static AdmissionOffice& getInstance() {
        static AdmissionOffice office;
        return office;
    }

    void admit(const std::string& name) {
        if (count < 100) {
            admitted[count++] = name;
            std::cout << name << " admitted.\n";
        } else {
            std::cout << "No more seats.\n";
        }
    }

    void viewAll() {
        for (int i = 0; i < count; i++)
            std::cout << admitted[i] << "\n";
    }
}; 

/*
    static Logger inst; inside a function is guaranteed thread-safe in C++11 and later.
    You don't control destruction — the compiler destroys it on exit.
    No heap allocation.
    No manual memory management.

    7. When You Should Avoid Singleton
    - When it’s just lazy dependency injection
    - When you need multiple instances for testing
    - When you need polymorphism (Singleton breaks that)
    - When object lifetime matters

    8. Quick Mental Model
    Singleton = Global variable with armor.
*/


/*
    Builder:
    This pattern becomes obvious when:
    1. You have 10+ parameters
    2. Some parameters are optional
    3. Some parameters depend on others
    4. Construction requires multiple steps
    5. Object must be immutable
    6. You want to hide details of construction
    7. You want readable, named configuration
*/

class Window {
private:
    int width;
    int height;
    string title;
    bool resizable;
    bool fullscreen;

    // Private ctor – only Builder can create Window
    Window(int w, int h, const std::string& t, bool r, bool f)
        : width(w), height(h), title(t), resizable(r), fullscreen(f) {}

public:
    void show() const {
        std::cout << "Window: " << title
                << " (" << width << "x" << height << ")"
                << " resizable=" << resizable
                << " fullscreen=" << fullscreen
                << std::endl;
    }

    class Builder {
    private:
        int width = 800;
        int height = 600;
        string title = "Untitled";
        bool resizable = false;
        bool fullscreen = false;

    public:
        Builder& setWidth(int w) { width = w; return *this; }
        Builder& setHeight(int h) { height = h; return *this; }
        Builder& setTitle(const std::string& t) { title = t; return *this; }
        Builder& setResizable(bool r) { resizable = r; return *this; }
        Builder& setFullscreen(bool f) { fullscreen = f; return *this; }

        Window build() const {
            return Window(width, height, title, resizable, fullscreen);
        }
    };
};

/*
    Why not just keep build logic inside Window?
    Because then you end up with a “half-configured” Window object:

        Window w;
        w.setWidth(800);
        w.setHeight(600);
        w.setTitle("Game");
        w.setOpacity(0.5);

    This is a partially valid object until fully built.
    A Window should be fully valid the moment it exists.
    Builder keeps all the intermediate sloppy state OUTSIDE the actual object.
*/

/*
    Prototype:
        Clone Objects without constructing from scratch
        1. The usecase becomes obvious when you are required to do polymorphic copying
        2. Client doesn't need to know the exact type

        “Instead of creating objects using new DerivedNode(...) or constructors,
            you clone an existing object polymorphically.”

        
*/

class Node {
public:
    Node* next;

    Node() : text(""), next(nullptr) {}
    Node(string x) : text(x), next(nullptr) {}

    virtual void display() {
        cout << "Node Details: " << text << endl;
    }

    virtual Node* clone() const {
        return new Node(*this);
    }

    virtual ~Node() {} //no need for destructor

protected:
    string text;
};

// DerivedNode class
class DerivedNode : public Node {
private:
    int Number;

public:
    DerivedNode() : Node(), Number(0) {}
    DerivedNode(string x, int n) : Node(x), Number(n) {}

    void display() override {
        cout << "DerivedNode Details: " << text << ", Number: " << Number << endl;
    }

    Node* clone() const override {
        return new DerivedNode(*this);
    }
};

class CircularLinkedList {
public:
    CircularLinkedList() : head(nullptr) {}

    // Copy constructor
    CircularLinkedList(const CircularLinkedList& other) : head(nullptr) {
        if (other.head == nullptr)
            return;

        Node* temp = other.head;
        do {
            Node* newNode = temp->clone(); 
            addNode(newNode);
            temp = temp->next;
        } while (temp != other.head);
    }

    // Destructor
    ~CircularLinkedList() {
        if (!head)
            return;

        Node* curr = head->next;
        while (curr != head) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }

        delete head;
        head = nullptr;
    }

    // addNode
    void addNode(Node* newNode) {
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
        }
    };

    // Display
    void displayList() const {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            temp->display();
            temp = temp->next;
        } while (temp != head);
    }

private:
    Node* head;
};

/*
    Factory Method:
    “I want to create an object, but I don’t want the client code to know the exact class being instantiated.”

    It solves two problems:
    1. Hides the constructor details.
    2. Lets you change which concrete class is created without touching the client code.
*/

class Button {
public:
    virtual void click() = 0;
    virtual ~Button() {}
};

// Concrete products
class WindowsButton : public Button {
public:
    void click() override { cout << "Windows Button clicked\n"; }
};

class LinuxButton : public Button {
public:
    void click() override { cout << "Linux Button clicked\n"; }
};

// Factory
class ButtonFactory {
public:
    static Button* createButton(const string& os) {
        if (os == "Windows") return new WindowsButton();
        else if (os == "Linux") return new LinuxButton();
        else return nullptr;
    }
};

/*
    Abstract Factory Pattern
*/

// Products
class Checkbox {
public:
    virtual void check() = 0;
    virtual ~Checkbox() {}
};

// Windows family
// Windows Button defined before
class WindowsCheckbox : public Checkbox {
public:
    void check() override { cout << "Windows Checkbox checked\n"; }
};

// Linux family
// Linux button defined before

class LinuxCheckbox : public Checkbox {
public:
    void check() override { cout << "Linux Checkbox checked\n"; }
};

// Abstract factory
class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
    virtual ~GUIFactory() {}
};

// Concrete factories
class WindowsFactory : public GUIFactory {
public:
    Button* createButton() override { return new WindowsButton(); }
    Checkbox* createCheckbox() override { return new WindowsCheckbox(); }
};

class LinuxFactory : public GUIFactory {
public:
    Button* createButton() override { return new LinuxButton(); }
    Checkbox* createCheckbox() override { return new LinuxCheckbox(); }
};

// Client code
void renderUI(GUIFactory* factory) {
    Button* btn = factory->createButton();
    Checkbox* cb = factory->createCheckbox();
    btn->click();
    cb->check();
    delete btn;
    delete cb;
}


int main(){
    AdmissionOffice::getInstance().admit("Ali");
    AdmissionOffice::getInstance().admit("Sara");

    AdmissionOffice::getInstance().viewAll();

    Window w = Window::Builder()
        .setWidth(1024)
        .setTitle("Editor")
        .setResizable(true)
        .build();

    w.show();

    /////
    
    string OS = "Linux";
    Button* btn = ButtonFactory::createButton(OS);
    btn->click();
    delete btn;

    /////

    GUIFactory* factory = new WindowsFactory();
    renderUI(factory);
    delete factory;
}