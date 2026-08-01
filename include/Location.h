#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include "Constants.h"
using namespace std;

/* ============================================================
   1. LOCATION DATA (ARRAY BASED CATALOG)
   ============================================================ */
struct Location {
    int    id;
    string name;
    double distance;   // distance from main gate (in meters)
    double rating;     // popularity / rating out of 5.0
};

// The master catalog - a single fixed-size array shared by every
// other module (stack, queue, BST, graph, sorting all reference
// locations by INDEX into this array, never by copy).
extern Location locations[MAX_LOC];
extern int      locCount;

void   loadSampleData();                 // Task 1: populate starter data
void   printLocation(const Location &l); // print one formatted row
void   displayAllLocations();            // Task 1: printed location list
int    findIndexById(int id);            // linear helper used by graph/menu

#endif
