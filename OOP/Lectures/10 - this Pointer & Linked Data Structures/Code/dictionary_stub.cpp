#include <iostream>
using namespace std;

// TODO: Create class template KeyValue
// template <typename K, typename V>

class KeyValue {
    // your code here
};

int main() {
    KeyValue<int, string> kv1(1, "Apple");
    kv1.display();

    KeyValue<string, double> kv2("PI", 3.14159);
    kv2.display();

    return 0;
}