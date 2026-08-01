#include <iostream>
#include "ResourceQueue.h"
using namespace std;

Person resQueue[MAX_QUEUE];
int qFront = 0, qRear = -1, qCount = 0;
int totalServed = 0;

void enqueuePerson(const string &name) {
    if (qCount >= MAX_QUEUE) {
        cout << "Queue is full! Cannot add more people right now.\n";
        return;
    }
    qRear = (qRear + 1) % MAX_QUEUE;
    resQueue[qRear].name = name;
    qCount++;
    cout << name << " joined the queue. (Position: " << qCount << ")\n";
}

void servePerson() {
    if (qCount == 0) {
        cout << "Queue is empty - no one to serve.\n";
        return;
    }
    cout << "Serving: " << resQueue[qFront].name << " ... done.\n";
    qFront = (qFront + 1) % MAX_QUEUE;
    qCount--;
    totalServed++;
}

void showQueueStatus() {
    cout << "\n------------------- RESOURCE QUEUE STATUS -------------------\n";
    cout << "People waiting : " << qCount << "\n";
    cout << "Total served   : " << totalServed << "\n";
    if (qCount == 0) {
        cout << "(queue is currently empty)\n";
    } else {
        int idx = qFront;
        for (int i = 0; i < qCount; i++) {
            cout << (i + 1) << ". " << resQueue[idx].name << "\n";
            idx = (idx + 1) % MAX_QUEUE;
        }
    }
    cout << "----------------------------------------------------------------\n";
}

/* Task 5: Simulate people waiting at a busy resource (e.g. library desk) */
void queueSimulationMenu() {
    int ch;
    string resourceName = "Library Front Desk";
    do {
        cout << "\n=== BUSY RESOURCE QUEUE SIMULATION: " << resourceName << " ===\n";
        cout << "1. Enqueue a person (join queue)\n";
        cout << "2. Serve next person (FCFS)\n";
        cout << "3. Show queue status\n";
        cout << "4. Back to main menu\n";
        cout << "Choice: ";
        cin >> ch;
        if (ch == 1) {
            string name;
            cout << "Enter person's name: ";
            cin >> name;
            enqueuePerson(name);
        } else if (ch == 2) {
            servePerson();
        } else if (ch == 3) {
            showQueueStatus();
        } else if (ch != 4) {
            cout << "Invalid choice.\n";
        }
    } while (ch != 4);
}
