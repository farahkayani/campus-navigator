#ifndef SEARCH_BST_H
#define SEARCH_BST_H

#include <string>
using namespace std;

/* ============================================================
   6. BINARY SEARCH TREE - SEARCH BY ID AND BY NAME
   ============================================================ */
struct BSTNode {
    int locIndex;
    BSTNode *left, *right;
    BSTNode(int idx) : locIndex(idx), left(nullptr), right(nullptr) {}
};

extern BSTNode* idRoot;    // tree keyed by location ID
extern BSTNode* nameRoot;  // tree keyed by location Name

BSTNode* insertById(BSTNode* root, int idx);
BSTNode* insertByName(BSTNode* root, int idx);
void     buildSearchTrees();   // build both trees from locations[]

BSTNode* searchById(BSTNode* root, int id, int &comparisons);
BSTNode* searchByName(BSTNode* root, const string &name, int &comparisons);

void searchMenu();   // Task 6: interactive search by ID or Name

#endif
