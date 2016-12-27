#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle
{
    public:
        //member data
        int state[9];
        int path_cost;
        Puzzle * parent;
        //member functions
        Puzzle();//constructor
        int actions();
        
};


#endif