#ifndef RESOURCE_QUEUE_H
#define RESOURCE_QUEUE_H

#include <string>
#include "Constants.h"
using namespace std;

/* ============================================================
   5. BUSY RESOURCE QUEUE SIMULATION (ARRAY BASED FCFS QUEUE)
   ============================================================ */
struct Person {
    string name;
};

extern Person resQueue[MAX_QUEUE];
extern int qFront, qRear, qCount;
extern int totalServed;

void enqueuePerson(const string &name);  // join the back of the queue
void servePerson();                      // serve/remove the front of the queue
void showQueueStatus();                  // print current waiting list
void queueSimulationMenu();              // Task 5: interactive sub-menu

#endif
