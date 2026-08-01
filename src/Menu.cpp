#include <iostream>
#include "Menu.h"
#include "Location.h"
#include "VisitStack.h"
#include "CatalogBrowser.h"
#include "ResourceQueue.h"
#include "SearchBST.h"
#include "CampusGraph.h"
#include "SortingAlgorithms.h"
using namespace std;

void printMainMenu() {
    cout << "\n=========================================================\n";
    cout << "            CAMPUS NAVIGATOR - MAIN MENU\n";
    cout << "=========================================================\n";
    cout << " 1. Display all campus locations\n";
    cout << " 2. Visit a location by ID (adds to recent-visits log)\n";
    cout << " 3. Show recent visits log\n";
    cout << " 4. Undo last visit\n";
    cout << " 5. Browse full catalog (Next/Previous)\n";
    cout << " 6. Busy resource queue simulation\n";
    cout << " 7. Search a location (by ID or Name - BST)\n";
    cout << " 8. Check reachability between two locations (Graph/BFS)\n";
    cout << " 9. Sort locations (4 algorithms)\n";
    cout << "10. Exit\n";
    cout << "=========================================================\n";
    cout << "Enter choice: ";
}

/* Task 10: Menu-driven interface tying everything together */
void runMainMenu() {
    int choice;
    do {
        printMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllLocations();
                break;
            case 2: {
                int id;
                displayAllLocations();
                cout << "Enter location ID to visit: ";
                cin >> id;
                int idx = findIndexById(id);
                if (idx == -1) cout << "Invalid ID.\n";
                else pushVisit(idx);
                break;
            }
            case 3:
                showRecentVisits();
                break;
            case 4:
                undoLastVisit();
                break;
            case 5:
                browseCatalog();
                break;
            case 6:
                queueSimulationMenu();
                break;
            case 7:
                searchMenu();
                break;
            case 8:
                reachabilityMenu();
                break;
            case 9:
                sortingMenu();
                break;
            case 10:
                cout << "Thank you for using Campus Navigator. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 10);
}
