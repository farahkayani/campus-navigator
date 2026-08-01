#ifndef VISIT_STACK_H
#define VISIT_STACK_H

#include "Constants.h"

/* ============================================================
   2 & 3. RECENT VISITS LOG (ARRAY BASED STACK) + UNDO
   ============================================================ */
extern int visitStack[MAX_VISITS];  // stores an index into locations[]
extern int visitTop;                // stack pointer, -1 = empty

void pushVisit(int locIndex);   // Task 2: log a visit (most recent on top)
void showRecentVisits();        // Task 2: print log, most recent first
void undoLastVisit();           // Task 3: pop the last visited location

#endif
