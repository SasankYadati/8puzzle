# 8puzzle
A sliding block puzzle, whose solution is found using A* Search.


author	  : happystick <br>
mail-id	  : sai.sasank.yadati@gmail.com <br>
last mod. : 27/12/2016 <br>

Note : The distinction between a state and a node is crucial to the understanding of A* Search, which is used to solve 8 Puzzle in this project. However, the terms node & state are used interchangebly in this document. In fact, it is important to understand any AI search algorithm.

# a.Problem Definition :
 
In this puzzle, we have a 3x3 grid containing 9 squares containing 8 tiles and 1 blank. The 8 tiles are numbered 1 to 8. The blank can move up, down, left or right depending on it's position. 

Given an arbitrary initial configuration of the grid, the problem solving agent needs to find an optimal sequence of actions that lead to the goal state, if there is one. 

The intial state can be any possible configuration of the 3x3 grid. On the other hand, the goal state has a definite order that is discussed later.

# b.Problem Formulation :

1.State Description<br>
2.Initial State & Goal State<br>
3.Actions as function of states<br>
4.Transition Model<br>
5.Goal Test<br>
6.Step Costs & Path Costs<br>

# b.1 State Description : 

A state is described by the positions of the tiles and blank in a state array.

                                        [0]   [1]   [2]
                                        [3]   [4]   [5]    
                                        [6]   [7]   [8]
                  Fig. All the squares in the grid are indicated by the positions shown above.

Basic terminolgy :<br>
    
  square x  - location in the grid, x ϵ [0,8]<br>
  tile x    - a square occupied by the number x ϵ [1,8]<br>
  blank     - unoccupied square.<br>

Clearly, there are finite no. of states in this problem.
    
# b.2 Initial State & Goal State :

Initial state is taken as an input. It can be any possible configuration of the grid i.e., any possible state of the problem.

Goal state for 8-Puzzle is defined differently by various authors. We will consider the following state as the goal state.

                                        1   2   3 
                                        4   5   6           
                                        7   8   
                                     Fig. Goal state.

# b.3 Actions as function of States :

Set of all possible actions in the 8 puzzle problem : 
				{ UP, LEFT, DOWN, RIGHT }

All of them represent the possible physical movements of the blank in the grid.

We need a function ACTIONS that takes in state of the problem as an argument and returns all the possible actions that are valid in the given state.

For example, consider the following state : 

                                        2   4   1
                                        3   5                   
                                        6   7   8
                                   Fig. A state instance. 

When ACTIONS is called on the above state, it returns UP,LEFT & DOWN.  

To make the representation much simpler, let us quantify the actions.

UP : 1<br>
LEFT : 2<br>
DOWN : 4<br>
RIGHT : 8<br>

Now, if ACTIONS is called on the same state, it returns 1+2+4, i.e., 7.  

# b.4 Transition Model :

We need a transition model that describes how the grid evolves with different actions taken by the agent.

    2   4   1                                           2   4   1
    3   5                on applying LEFT               3       5
    6   7   8                                           6   7   8

The transition function takes current state and an action as arguments and returns the resulting state.

# b.5 Goal Test :

This function GOALTEST takes in a state as an argument and returns a boolean by checking if the state is the goal or not.

    

                                        1   2   3
                                        4   5   6       
                                        7   8
                                  Fig. A goal state instance.

The goal test function returns True for the above state.

# b.6 Step Costs & Path Costs :

Every action is associated with some cost. Here, we consider step cost to be 1 for each action. Path cost is the sum of all the step costs in the path(sequence of states).

Whenever there is a transition, we find the path cost recursively.

Consider a transition from state a to state b:<br>
    <i>path-cost(b) = path-cost(a) + step-cost(a,b)</i>
    
Path cost for the initial state is taken as zero. 

# c. Implementation details :

1. Algorithm    <br>
2. Heuristics<br>
3. Structure of node<br>

# c.1 Algorithm :

We use A* Search to find an optimal sequence of actions that lead to the goal state.

A* Search is a well known informed search algorithm. An informed search algorithm has additional knowledge given to it, that is not provided by the problem description itself. This additional knowledge is known as heuristics.

Check out the following link to know more about A* Search.<br>
http://web.mit.edu/eranki/www/tutorials/search/

# c.2 Heuristics :

Given a state, heuristics of that state indicates an estimated cost to reach the goal state.

A good heuristic function is admissible and consistent.

Check out the following link to know more about heurisitcs.<br>
http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html

For a node n,
<i>h(n) = #misplaced tiles and blank in the grid</i>

The above heuristic is both admissible and consistent.

# c.3 Structure of node :

We define a node as a structure that holds following information.
    
<i>state</i><br>
holds state description<br>

<i>actions()</i><br>
member function, returns a set of actions as a number <br>

<i>parent</i><br>
a pointer to the parent node    <br>

<i>path-cost</i><br>
the cost of the path to the current node.<br>


