#include <iostream>
#include "SortingAlgorithms.h"
#include "Location.h"
#include "Constants.h"
using namespace std;

void initIndexArray(int idxArr[]) {
    for (int i = 0; i < locCount; i++) idxArr[i] = i;
}

void printSorted(int idxArr[], const string &title) {
    cout << "\n---------------- " << title << " ----------------\n";
    for (int i = 0; i < locCount; i++)
        printLocation(locations[idxArr[i]]);
    cout << "-------------------------------------------------------\n";
}

/* --- Bubble Sort: alphabetically by name (A-Z) --- */
void bubbleSortByName(int idxArr[]) {
    for (int i = 0; i < locCount - 1; i++)
        for (int j = 0; j < locCount - 1 - i; j++)
            if (locations[idxArr[j]].name > locations[idxArr[j + 1]].name) {
                int t = idxArr[j]; idxArr[j] = idxArr[j + 1]; idxArr[j + 1] = t;
            }
}

/* --- Selection Sort: alphabetically by name (Z-A) --- */
void selectionSortByNameDesc(int idxArr[]) {
    for (int i = 0; i < locCount - 1; i++) {
        int maxPos = i;
        for (int j = i + 1; j < locCount; j++)
            if (locations[idxArr[j]].name > locations[idxArr[maxPos]].name)
                maxPos = j;
        int t = idxArr[i]; idxArr[i] = idxArr[maxPos]; idxArr[maxPos] = t;
    }
}

/* --- Insertion Sort: numeric by distance (ascending, nearest first) --- */
void insertionSortByDistance(int idxArr[]) {
    for (int i = 1; i < locCount; i++) {
        int key = idxArr[i];
        double keyDist = locations[key].distance;
        int j = i - 1;
        while (j >= 0 && locations[idxArr[j]].distance > keyDist) {
            idxArr[j + 1] = idxArr[j];
            j--;
        }
        idxArr[j + 1] = key;
    }
}

/* --- Merge Sort: numeric by rating (descending, best rated first) --- */
static void mergeByRating(int idxArr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[MAX_LOC], R[MAX_LOC];
    for (int i = 0; i < n1; i++) L[i] = idxArr[l + i];
    for (int j = 0; j < n2; j++) R[j] = idxArr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (locations[L[i]].rating >= locations[R[j]].rating)
            idxArr[k++] = L[i++];
        else
            idxArr[k++] = R[j++];
    }
    while (i < n1) idxArr[k++] = L[i++];
    while (j < n2) idxArr[k++] = R[j++];
}

void mergeSortByRating(int idxArr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortByRating(idxArr, l, m);
    mergeSortByRating(idxArr, m + 1, r);
    mergeByRating(idxArr, l, m, r);
}

/* Tasks 8 & 9: Sort locations alphabetically / numerically */
void sortingMenu() {
    int ch;
    int idxArr[MAX_LOC];
    cout << "\n===================== SORT LOCATIONS =====================\n";
    cout << "1. Alphabetical (Bubble Sort, A-Z)\n";
    cout << "2. Alphabetical (Selection Sort, Z-A)\n";
    cout << "3. By Distance  (Insertion Sort, nearest first)\n";
    cout << "4. By Rating    (Merge Sort, best rated first)\n";
    cout << "Choice: ";
    cin >> ch;

    initIndexArray(idxArr);
    switch (ch) {
        case 1:
            bubbleSortByName(idxArr);
            printSorted(idxArr, "ALPHABETICAL A-Z (Bubble Sort)");
            break;
        case 2:
            selectionSortByNameDesc(idxArr);
            printSorted(idxArr, "ALPHABETICAL Z-A (Selection Sort)");
            break;
        case 3:
            insertionSortByDistance(idxArr);
            printSorted(idxArr, "NEAREST FIRST (Insertion Sort - by Distance)");
            break;
        case 4:
            mergeSortByRating(idxArr, 0, locCount - 1);
            printSorted(idxArr, "BEST RATED FIRST (Merge Sort - by Rating)");
            break;
        default:
            cout << "Invalid choice.\n";
    }
}
