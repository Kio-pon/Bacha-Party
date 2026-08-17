#include "src/q3_hotel.h"
#include <iostream>
#include <vector>

using namespace std;


// You can compile this file to test the Numbers (const corretness) question
// Compile using the following command:
// g++ q3_test.cpp src/q3_hotel.h -o q3
int main() {
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i) 
    {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") 
        {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else 
        {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        total_profit += room->get_price();
    }
    cout << total_profit << endl;

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();

    return 0;
}