#ifndef PROBLEM_H
#define PROBLEM_H

int goalTest(Puzzle *);
int heuristic(Puzzle *);
Puzzle * transition(Puzzle *curr_node,int action);


#endif