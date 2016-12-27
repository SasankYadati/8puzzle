#ifndef ASTAR_H
#define ASTAR_H



void insertFrontier(Puzzle * frontier, long int * top,Puzzle a_node);
Puzzle* popFrontier(Puzzle * frontier, int * top);

int isExplored(int * state);
void insertExplored(int * state);
void astar(Puzzle initial_node);



#endif
