/*
    ============================================================
     CAMPUS NAVIGATOR - Console Based DSA Project
    ============================================================
    Data Structures Used:
      1. Arrays              -> master location catalog      (Location.h/.cpp)
      2. Stack (array based) -> recent visits log + undo      (VisitStack.h/.cpp)
      3. Array index pointer -> catalog browser (next/prev)   (CatalogBrowser.h/.cpp)
      4. Queue (array based) -> busy resource FCFS simulation (ResourceQueue.h/.cpp)
      5. Binary Search Tree  -> fast search by ID and by Name (SearchBST.h/.cpp)
      6. Graph (adjacency matrix) + BFS -> reachability/path  (CampusGraph.h/.cpp)
      7. Sorting Algorithms  -> Bubble, Selection, Insertion,
                                 Merge Sort                    (SortingAlgorithms.h/.cpp)
      8. Menu-driven interface tying it all together           (Menu.h/.cpp)

    Language : C++ (no STL containers - arrays only, as required)
    Build    : see Makefile ("make" then "./campus_navigator")
    ============================================================
*/

#include <iostream>
#include "Location.h"
#include "SearchBST.h"
#include "CampusGraph.h"
#include "Menu.h"
using namespace std;

int main() {
    loadSampleData();      // Task 1: load starter catalog into the array
    buildSearchTrees();    // Task 6: build ID & Name BSTs from the catalog
    buildCampusGraph();    // Task 7: build the walkway adjacency matrix

    cout << "Welcome to CAMPUS NAVIGATOR - your console guide to campus!\n";

    runMainMenu();          // Task 10: hand control to the main menu loop

    return 0;
}
