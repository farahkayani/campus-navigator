#ifndef CONSTANTS_H
#define CONSTANTS_H

/* ============================================================
   GLOBAL CONSTANTS - shared across every module
   ============================================================ */
const int MAX_LOC     = 20;   // max campus locations the catalog can hold
const int MAX_VISITS  = 50;   // max entries kept in the visit-log stack
const int MAX_QUEUE   = 30;   // max people the resource queue can hold
const int NO_PARENT   = -1;   // sentinel used by BFS parent[] array

#endif
