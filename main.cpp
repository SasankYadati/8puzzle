#include<iostream>
#include"puzzle.h"
#include"astar.h"

using namespace std;

int main()
{
    Puzzle initial;
    int pos;
    
    //cout<<"Welcome!"<<endl;
    //cout<<"Enter the positions of the tiles!"<<endl;
    
    for(int i=0; i<9; ++i)
    {
        cin>>pos;
        initial.state[i] = pos; 
    }
    
    astar(initial);
    return 0;
}
