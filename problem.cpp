#include<iostream>
#include"puzzle.h"
#include"problem.h"
using namespace std;

int goalTest(Puzzle * curr_node)
{
    int goal_state[9] = {8,0,1,2,3,4,5,6,7};
    for(int i=0; i<9; ++i)
    {
        if(curr_node->state[i] != goal_state[i])
            return 0;
    }
    return 1;
}

int heuristic(Puzzle * curr_node)
{
    //heuristic is the number of the misplaced tiles in the state.
    int goal_state[9] = {8,0,1,2,3,4,5,6,7};
    int heuristic = 0;
    for(int i=0; i<9; ++i)
    {
        if(curr_node->state[i] != goal_state[i])
        {
            heuristic++;
        }
    }
    return heuristic;
}

Puzzle* transition(Puzzle *curr_node, int action)
{
    Puzzle *next_node = new Puzzle;

    int blank_pos = curr_node->state[0];
    int tile;

    if(action==1)//up action
    {
        tile = blank_pos - 3;
        for(int i=1;i<9;++i)
        {
            if(curr_node->state[i]==tile)
 
            {    
                next_node->state[0] = tile;
                next_node->state[i] = blank_pos;
            }
            else
            {
                next_node->state[i] = curr_node->state[i];
  
            }
        }

    }

    else if(action==2)//left action
    {
        tile = blank_pos-1;

        for(int i=0;i<9;++i)
        {
            if(curr_node->state[i]==blank_pos-1)
 
            {    
                next_node->state[0] = tile;
                next_node->state[i] = blank_pos;
            }
            else
            {
                next_node->state[i] = curr_node->state[i];
            }
        }

    }

    else if(action==4)//down action
    {
        tile = blank_pos+3;

        for(int i=0;i<9;++i)
        {
            if(curr_node->state[i]==blank_pos+3)
 
            {    
                next_node->state[0] = tile;
                next_node->state[i] = blank_pos;
            }
            else
            {
                next_node->state[i] = curr_node->state[i];
            }
        }

    }

    else//right action
    {
        tile = blank_pos+1;

        for(int i=0;i<9;++i)
        {
            if(curr_node->state[i]==blank_pos+1)
 
            {    
                next_node->state[0] = tile;
                next_node->state[i] = blank_pos;
            }
            else
            {
                next_node->state[i] = curr_node->state[i];
            }
        }

    }

    next_node->parent = curr_node;
    next_node->path_cost = curr_node->path_cost + 1;
    
    return next_node;
}