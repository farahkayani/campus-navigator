#include <iostream>
#include "VisitStack.h"
#include "Location.h"
using namespace std;

int visitStack[MAX_VISITS];
int visitTop = -1;

void pushVisit(int locIndex) {
    if (visitTop >= MAX_VISITS - 1) {
        // stack full - drop the oldest entry to make room (shift down)
        for (int i = 0; i < MAX_VISITS - 1; i++)
            visitStack[i] = visitStack[i + 1];
        visitTop--;
    }
    visitStack[++visitTop] = locIndex;
    cout << "Visited: " << locations[locIndex].name << " (logged)\n";
}

void showRecentVisits() {
    cout << "\n---------------- RECENT VISITS (most recent first) ----------------\n";
    if (visitTop == -1) {
        cout << "No visits logged yet.\n";
        return;
    }
    for (int i = visitTop; i >= 0; i--) {
        cout << (visitTop - i + 1) << ". ";
        printLocation(locations[visitStack[i]]);
    }
    cout << "---------------------------------------------------------------------\n";
}

void undoLastVisit() {
    if (visitTop == -1) {
        cout << "Nothing to undo - visit log is empty.\n";
        return;
    }
    cout << "Undo: removed \"" << locations[visitStack[visitTop]].name
         << "\" from the recent-visits log.\n";
    visitTop--;
}
