#include <iostream>
#include <vector>
using namespace std;

// Lab Exercise 3: Hotel Rooms. HotelRoom stores bedroom/bathroom counts and
// prices at 50/bedroom + 100/bathroom. HotelApartment derives from
// HotelRoom and costs an extra 100.
class HotelRoom
{
private:
    int bathRooms, bedRooms;

public:
    HotelRoom(int bed = 0, int bath = 0) : bathRooms(bath), bedRooms(bed) {}
    virtual int get_price()
    {
        // TODO: return 50 * bedRooms + 100 * bathRooms
        return 0;
    }
};
class HotelApartment : public HotelRoom
{
public:
    HotelApartment(int bth, int bdr) : HotelRoom(bth, bdr) {}
    int get_price() override
    {
        // TODO: return HotelRoom::get_price() + 100
        return 0;
    }
};

// You can compile this file to test the Hotel Rooms question
int main()
{
    int n;
    cin >> n;
    vector<HotelRoom *> rooms;
    for (int i = 0; i < n; ++i)
    {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard")
        {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        }
        else
        {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }
    int total_profit = 0;
    for (auto room : rooms)
    {
        total_profit += room->get_price();
    }
    cout << total_profit << endl;
    for (auto room : rooms)
    {
        delete room;
    }
    rooms.clear();
    return 0;
}
