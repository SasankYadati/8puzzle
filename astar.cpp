#include<cmath>
#include<iostream>
#include<cstddef>
#include"puzzle.h"
#include"problem.h"
#include<cstdlib>
using namespace std;

Puzzle * frontier = new Puzzle[1000000];
long int top = -1;

int explored[1000000][9];
long int top_exp = -1;

void insertFrontier(Puzzle *a_node)
{
    
    if(top==-1)
    {
        frontier[0] = *a_node;
    }
    else
    {
        long int i=0,j=0;

        while(i<=top && frontier[i].path_cost + heuristic(&frontier[i]) <= a_node->path_cost + heuristic(a_node))
            i++;
        for(j=top;j>=i; --j)
            frontier[j+1] = frontier[j];
        frontier[i] = *a_node;
    }    
    top++;
}

Puzzle * popFrontier()
{
    Puzzle * popped = new Puzzle;
    if(top==-1)
        return NULL;
    else
    {
        for(int i=0; i<9; ++i)
            popped->state[i] = frontier[0].state[i];
        popped->parent = frontier[0].parent;
        popped->path_cost = frontier[0].path_cost;
        for(long int i=0; i<top; ++i)
            frontier[i] = frontier[i+1];
        top--;
        return popped;
    }
}

void insertExplored(int * state)
{
    top_exp++;
    for(int i=0; i<9; ++i)
        explored[top_exp][i] = state[i]; 
}

int isExplored(int * state)
{
    int cnt = 0;
    for(long int i=0; i<=top_exp; ++i)
    {
        cnt = 0;
        for(int j=0; j<9; ++j)
        {
            if(explored[i][j] == state[j])
            {
                cnt++;
            }
        }
        if(cnt==9)
            return 1;
    }
    return 0;
}

void astar(Puzzle initial_node)
{
    
    Puzzle * initial = new Puzzle;
    initial = &initial_node;

    Puzzle * temp, * gen_node;
    int actions;
    int possible_actions[4];

    insertFrontier(initial);

    while(true)
    {
        if(top==-1)
        {
            cout<<"failure"<<endl;
            cout<<"no solution found!"<<endl;
            return;
        }
        temp = popFrontier();
        insertExplored(temp->state);
        if(goalTest(temp))
        {
            cout<<"success"<<endl;
            while(temp)
            {
                for(int i=0; i<9; ++i)
                    cout<<temp->state[i]<<" ";
                cout<<endl;
                temp = temp->parent;
            }
            return;
        }

        actions = temp->actions();
        switch(actions)
        {
            case 3:possible_actions[0]=1;possible_actions[1]=1;possible_actions[2]=0;possible_actions[3]=0;break;
            case 9:possible_actions[0]=1;possible_actions[3]=1;possible_actions[2]=0;possible_actions[1]=0;break;
            case 6:possible_actions[1]=1;possible_actions[2]=1;possible_actions[0]=0;possible_actions[3]=0;break;
            case 12:possible_actions[2]=1;possible_actions[3]=1;possible_actions[1]=0;possible_actions[0]=0;break;
            case 7:possible_actions[0]=1;possible_actions[1]=1;possible_actions[2]=0;possible_actions[3]=0;break;
            case 11:possible_actions[0]=1;possible_actions[1]=1;possible_actions[3]=1;possible_actions[2]=0;break;
            case 13:possible_actions[0]=1;possible_actions[3]=1;possible_actions[2]=1;possible_actions[1]=0;break;
            case 14:possible_actions[3]=1;possible_actions[1]=1;possible_actions[2]=1;possible_actions[0]=0;break;
            case 15:possible_actions[0]=1;possible_actions[1]=1;possible_actions[2]=1;possible_actions[3]=1;break;
        }

        for(int i=0; i<4; ++i)
        {
            if(possible_actions[i]==1)
            {
                gen_node = transition(temp,pow(2,i));
                if(isExplored(gen_node->state) == 0)
                    insertFrontier(gen_node);
            }
        }

    }
    
}

