#include <iostream>
#include "SearchBST.h"
#include "Location.h"
#include "VisitStack.h"
using namespace std;

BSTNode* idRoot   = nullptr;
BSTNode* nameRoot = nullptr;

BSTNode* insertById(BSTNode* root, int idx) {
    if (root == nullptr) return new BSTNode(idx);
    if (locations[idx].id < locations[root->locIndex].id)
        root->left = insertById(root->left, idx);
    else
        root->right = insertById(root->right, idx);
    return root;
}

BSTNode* insertByName(BSTNode* root, int idx) {
    if (root == nullptr) return new BSTNode(idx);
    if (locations[idx].name < locations[root->locIndex].name)
        root->left = insertByName(root->left, idx);
    else
        root->right = insertByName(root->right, idx);
    return root;
}

void buildSearchTrees() {
    idRoot = nullptr;
    nameRoot = nullptr;
    for (int i = 0; i < locCount; i++) {
        idRoot   = insertById(idRoot, i);
        nameRoot = insertByName(nameRoot, i);
    }
}

BSTNode* searchById(BSTNode* root, int id, int &comparisons) {
    if (root == nullptr) return nullptr;
    comparisons++;
    if (locations[root->locIndex].id == id) return root;
    if (id < locations[root->locIndex].id) return searchById(root->left, id, comparisons);
    return searchById(root->right, id, comparisons);
}

BSTNode* searchByName(BSTNode* root, const string &name, int &comparisons) {
    if (root == nullptr) return nullptr;
    comparisons++;
    if (locations[root->locIndex].name == name) return root;
    if (name < locations[root->locIndex].name) return searchByName(root->left, name, comparisons);
    return searchByName(root->right, name, comparisons);
}

/* Task 6: Search a location by ID or name */
void searchMenu() {
    int ch;
    cout << "\nSearch by:\n1. ID\n2. Name\nChoice: ";
    cin >> ch;
    int comparisons = 0;
    if (ch == 1) {
        int id;
        cout << "Enter location ID: ";
        cin >> id;
        BSTNode* found = searchById(idRoot, id, comparisons);
        if (found) {
            cout << "\nLocation FOUND (in " << comparisons << " comparisons):\n";
            printLocation(locations[found->locIndex]);
            pushVisit(found->locIndex);
        } else {
            cout << "No location with ID " << id << " found.\n";
        }
    } else if (ch == 2) {
        string name;
        cout << "Enter location name (exact, case-sensitive): ";
        cin.ignore();
        getline(cin, name);
        BSTNode* found = searchByName(nameRoot, name, comparisons);
        if (found) {
            cout << "\nLocation FOUND (in " << comparisons << " comparisons):\n";
            printLocation(locations[found->locIndex]);
            pushVisit(found->locIndex);
        } else {
            cout << "No location named \"" << name << "\" found.\n";
        }
    } else {
        cout << "Invalid choice.\n";
    }
}
