#include <iostream>
#include "CampusGraph.h"
#include "Location.h"
using namespace std;

bool adjMatrix[MAX_LOC][MAX_LOC];

void addEdge(int idA, int idB) {
    int a = findIndexById(idA);
    int b = findIndexById(idB);
    if (a == -1 || b == -1) return;
    adjMatrix[a][b] = true;
    adjMatrix[b][a] = true;   // undirected: walkways connect both ways
}

void buildCampusGraph() {
    for (int i = 0; i < MAX_LOC; i++)
        for (int j = 0; j < MAX_LOC; j++)
            adjMatrix[i][j] = false;

    // Define walkway connections between buildings (by ID)
    // Based on the real BUIC campus guide map layout
    addEdge(202, 201); // Main Library - Bahria Business School
    addEdge(202, 203); // Main Library - Fatima Girls Hostel
    addEdge(201, 204); // Bahria Business School - Innovation Center
    addEdge(204, 205); // Innovation Center - Cafeteria (Pool Side)
    addEdge(205, 206); // Cafeteria (Pool Side) - Iqbal Block
    addEdge(203, 206); // Fatima Girls Hostel - Iqbal Block
    addEdge(206, 207); // Iqbal Block - Jahangir Khan Gymnasium
    addEdge(207, 208); // Gymnasium - Cafeteria (Parking Side)
    addEdge(208, 219); // Cafeteria (Parking Side) - Parking Plaza
    addEdge(207, 219); // Gymnasium - Parking Plaza
    addEdge(204, 209); // Innovation Center - Well Being Center
    addEdge(209, 211); // Well Being Center - Student Support Center
    addEdge(209, 210); // Well Being Center - Ibne Khuldun Auditorium
    addEdge(210, 215); // Auditorium - Sir Syed Block
    addEdge(215, 212); // Sir Syed Block - Bank Islami
    addEdge(212, 213); // Bank Islami - ATM
    addEdge(215, 214); // Sir Syed Block - Bank Alfalah
    addEdge(215, 207); // Sir Syed Block - Gymnasium
    addEdge(215, 216); // Sir Syed Block - Mosque Dar-ul-Ilm
    addEdge(216, 217); // Mosque Dar-ul-Ilm - Quaid Block
    addEdge(217, 218); // Quaid Block - Bahria University Head Office
    addEdge(217, 219); // Quaid Block - Parking Plaza
    addEdge(218, 219); // BUHO - Parking Plaza
}

/* Task 7: Model building connections and check reachability (BFS) */
void checkReachability(int startId, int endId) {
    int start = findIndexById(startId);
    int end   = findIndexById(endId);
    if (start == -1 || end == -1) {
        cout << "Invalid location ID(s).\n";
        return;
    }

    bool visited[MAX_LOC] = {false};
    int  parent[MAX_LOC];
    for (int i = 0; i < MAX_LOC; i++) parent[i] = NO_PARENT;

    int bfsQueue[MAX_LOC];
    int front = 0, rear = -1, count = 0;

    bfsQueue[++rear] = start; count++;
    visited[start] = true;

    while (count > 0) {
        int cur = bfsQueue[front];
        front = (front + 1) % MAX_LOC; count--;

        if (cur == end) break;

        for (int nxt = 0; nxt < locCount; nxt++) {
            if (adjMatrix[cur][nxt] && !visited[nxt]) {
                visited[nxt] = true;
                parent[nxt] = cur;
                bfsQueue[++rear] = nxt; count++;
                if (rear == MAX_LOC - 1) rear = -1; // wrap safeguard
            }
        }
    }

    if (!visited[end]) {
        cout << "\nResult: NO path exists between \"" << locations[start].name
             << "\" and \"" << locations[end].name << "\".\n";
        return;
    }

    // reconstruct path by walking the parent chain backwards
    int path[MAX_LOC], plen = 0;
    for (int v = end; v != NO_PARENT; v = parent[v])
        path[plen++] = v;

    cout << "\nResult: Path EXISTS between \"" << locations[start].name
         << "\" and \"" << locations[end].name << "\".\n";
    cout << "Path (" << plen << " stops): ";
    for (int i = plen - 1; i >= 0; i--) {
        cout << locations[path[i]].name;
        if (i > 0) cout << " -> ";
    }
    cout << "\n";
}

void reachabilityMenu() {
    int a, b;
    displayAllLocations();
    cout << "Enter starting location ID: ";
    cin >> a;
    cout << "Enter destination location ID: ";
    cin >> b;
    checkReachability(a, b);
}
