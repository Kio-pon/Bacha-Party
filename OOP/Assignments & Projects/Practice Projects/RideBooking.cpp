#include <iostream>
#include <string>

using namespace std;

// Constants
const int MAX_RIDES = 100;
const int MAX_DRIVERS = 50;
const int START_RIDE_ID = 100001;

// Struct Definition
struct Ride {
    string riderName;
    int rideID;
    string driverName;
    string pickupLocation;
    string dropoffLocation;
    double fare;
    string status; // "Ongoing", "Completed", "Cancelled"
};

// Global Variables
Ride rideDetails[MAX_RIDES];
int rideCount = 0; // Keeps track of total rides
string Drivers[MAX_DRIVERS]
int driverCount = 0 // Keeps track of total drivers

// ================= Function Definitions =================

int IsAvailable(string driverName, Ride rides[]){
    // TODO: Searches through the array 
    //       Checks if the given driverName has an Ongoing ride
    //       If the given driverName has an Ongoing ride returns 1, otherwise returns 0
}

int GetFare(int distance){
    //TODO: Calculate and return the fare based on the given scheme
    //      Distance < 2KM : 50 + (50 * distance)
    //      2KM < Distance < 5KM : 150 + (80 * (distance - 2)) 
    //      Distance > 5KM : 390 + (100 * (distance - 5))
}

// Prompts user for ride details and returns a Ride struct
Ride BookRide(string name) {
    // TODO: Prompt user for pickup, drop-off, distance
    //       Displays all available drivers. Hint use the IsAvailable function and the Drivers array.
    //       Prompts the user to select a driver
    //       Calculates the fare by calling the GetFare function.
    //       Set ride status to "Ongoing" and generate Ride ID
    //       If there is no driver avaliable then output an error message, generate a Ride ID, set ride status to "Cancelled" and driverName to ""
    Ride newRide;
    return newRide;
}

// Displays rides that match the given name (rider or driver)
void ViewRides(string name, Ride rides[], string status = "") {
    // TODO: Loop through the array and print rides where name matches riderName or driverName
    //       Displays all rides for that name regardless of status if status is ""
    //       Displays rides for that name and status if a status value was passed
}

// Displays ongoing rides for the user, prompts for Ride ID, and returns it
int ChangeStatus(string name, Ride rides[], int count) {
    // TODO: Show ongoing rides for the name. Hint: Call ViewRides and use the third parameter 
    //       Ask user to enter the Ride ID to update
    //       Return the Ride ID so status can be updated in main
    return -1; // Placeholder
}

// Sums up the fare of all rides assigned to a driver
double CalculateTotal(string driverName, Ride rides[]) {
    // TODO: Add up fares of rides where driverName matches and status is "Completed"
    return 0.0;
}

// ================= Main Function =================

int main() {
    // TODO:
    // - Display main menu
    // - Ask the user if they are a Rider (1) or Driver (2)
    // - Prompt for name
    // - If the user is a Driver and the name is not in the Drivers list add it to the list
    // - Based on role, display the appropriate menu
    // - Use the provided functions to implement menu options
    // - Ensure ride count does not exceed MAX_RIDES
    // - Validate menu inputs

    return 0;
}
