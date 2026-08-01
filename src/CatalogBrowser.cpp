#include <iostream>
#include <cctype>
#include "CatalogBrowser.h"
#include "Location.h"
#include "VisitStack.h"
using namespace std;

int browseIndex = 0;

void browseShow() {
    cout << "\n------------------------- CATALOG BROWSER --------------------------\n";
    cout << "[" << (browseIndex + 1) << " of " << locCount << "]\n";
    printLocation(locations[browseIndex]);
    cout << "----------------------------------------------------------------------\n";
}

/* Task 4: Browse full catalog forward/backward like a menu */
void browseCatalog() {
    char choice;
    browseShow();
    do {
        cout << "\n(n) Next  (p) Previous  (v) Mark as Visited  (q) Quit Browsing : ";
        cin >> choice;
        choice = tolower(choice);
        if (choice == 'n') {
            if (browseIndex < locCount - 1) browseIndex++;
            else cout << "Already at the last location.\n";
            browseShow();
        } else if (choice == 'p') {
            if (browseIndex > 0) browseIndex--;
            else cout << "Already at the first location.\n";
            browseShow();
        } else if (choice == 'v') {
            pushVisit(browseIndex);
        } else if (choice != 'q') {
            cout << "Invalid option.\n";
        }
    } while (choice != 'q');
}
