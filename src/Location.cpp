#include <iostream>
#include "Location.h"
using namespace std;

Location locations[MAX_LOC];
int      locCount = 0;

/* Starter data taken from the real BUIC campus guide map (Entrance-1,
   Entrance-2 and BUHO signboard). distance/rating are illustrative
   placeholder values for the demo - swap in measured figures for a
   production deployment. */
void loadSampleData() {
    Location data[] = {
        {201, "Bahria Business School",       180.0, 4.5},
        {202, "Main Library",                 140.0, 4.8},
        {203, "Fatima Girls Hostel",          220.0, 4.2},
        {204, "Bahria Innovation Center",     200.0, 4.6},
        {205, "Cafeteria (Pool Side)",        260.0, 4.4},
        {206, "Iqbal Block",                  250.0, 4.3},
        {207, "Jahangir Khan Gymnasium",      340.0, 4.7},
        {208, "Cafeteria (Parking Side)",     420.0, 4.1},
        {209, "Well Being Center",             90.0, 4.0},
        {210, "Ibne Khuldun Auditorium",      160.0, 4.5},
        {211, "Student Support Center",        60.0, 4.2},
        {212, "Bank Islami",                  300.0, 3.9},
        {213, "ATM",                          310.0, 3.8},
        {214, "Bank Alfalah",                 320.0, 3.9},
        {215, "Sir Syed Block",               280.0, 4.6},
        {216, "Mosque Dar-ul-Ilm",            380.0, 4.9},
        {217, "Quaid Block",                  430.0, 4.1},
        {218, "Bahria University Head Office",460.0, 4.3},
        {219, "Parking Plaza",                400.0, 3.7}
    };
    locCount = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < locCount; i++)
        locations[i] = data[i];
}

void printLocation(const Location &l) {
    cout << l.id << "\t" << l.name;
    // pad to a minimum column width, but always leave at least one
    // space so long names never collide with the distance value
    int padTo = 32;
    int pad = padTo - (int)l.name.length();
    for (int i = 0; i < (pad > 1 ? pad : 1); i++) cout << " ";
    cout << l.distance << "m\t" << l.rating << "/5\n";
}

/* Task 1: Printed location list */
void displayAllLocations() {
    cout << "\n==================== CAMPUS LOCATION CATALOG ====================\n";
    cout << "ID\tName                      Distance\tRating\n";
    cout << "-------------------------------------------------------------------\n";
    for (int i = 0; i < locCount; i++)
        printLocation(locations[i]);
    cout << "=====================================================================\n";
}

int findIndexById(int id) {
    for (int i = 0; i < locCount; i++)
        if (locations[i].id == id) return i;
    return -1;
}
