#ifndef CAMPUS_GRAPH_H
#define CAMPUS_GRAPH_H

#include "Constants.h"

/* ============================================================
   7. GRAPH (ADJACENCY MATRIX) + BFS REACHABILITY
   ============================================================ */
extern bool adjMatrix[MAX_LOC][MAX_LOC];

void addEdge(int idA, int idB);         // add an undirected walkway edge
void buildCampusGraph();                // define all campus walkways
void checkReachability(int startId, int endId); // BFS + path reconstruction
void reachabilityMenu();                // Task 7: interactive prompt

#endif
