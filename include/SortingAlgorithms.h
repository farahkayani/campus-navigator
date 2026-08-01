#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <string>
using namespace std;

/* ============================================================
   8 & 9. SORTING ALGORITHMS
   All functions sort an array of INDICES into locations[], so the
   master catalog (and therefore the BST/graph, which reference it
   by index) is never disturbed.
   ============================================================ */
void initIndexArray(int idxArr[]);
void printSorted(int idxArr[], const string &title);

void bubbleSortByName(int idxArr[]);              // alphabetical A-Z
void selectionSortByNameDesc(int idxArr[]);        // alphabetical Z-A
void insertionSortByDistance(int idxArr[]);        // numeric, nearest first
void mergeSortByRating(int idxArr[], int l, int r);// numeric, best rated first

void sortingMenu();   // Tasks 8 & 9: interactive sort selector

#endif
