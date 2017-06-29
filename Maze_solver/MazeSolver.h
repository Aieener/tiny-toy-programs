/*
*  MazeSolver.h
*  MazeSolver header file for lab 9, CS 223.
*
*  Barb Wahl & Theresa Wilson,
*  3-24-15
*
*  DO NOT CHANGE THIS FILE
*
*  A MazeSolver has a worklist for managing the exploration of a maze, and a
*  specific maze to solve.  MazeSolver returns a path from Start to Exit if
*  such a path exists, or reports that the maze is unsolvable.
*
*  ************************** MazeSolver Worklist **************************
*
*  The MazerSolver worklist contains pointers to squares in the maze that 
*  the solver knows about but has not yet explored.  Squares are always 
*  removed from the front of the worklist.  However, whether a square is 
*  added to the front or the back of the worklist depends on whether the 
*  worklist is acting as a stack or a queue.  When acting as a stack, squares 
*  are added to the front of the worklist.  When acting as a queue, squares 
*  are added to the back.  Treating the worklist as a stack results in a
*  depth-first search (DFS) of the maze.  Treating the worklist as a queue 
*  gives a breadth-first search (BFS) of the maze.
*
*  To get both stack and queue functionality out of the worklist, the worklist
*  is implemented as a deque (pronounced "deck" == double-ended-queue).  Deques 
*  allow elements to be added and removed (efficiently) from both the front and
*  the back of the data structure.  
*
*    HELPFUL DEQUE METHODS: see http://www.cplusplus.com/reference/deque/deque/
*     - void push_front (for adding to a stack / DFS)
*     - void push_back (for adding to a queue / BFS)
*     - <element type> front (for accessing the front-most element - "top")
*     - void pop_front (for removing from a stack or queue - "pop")
*     - int size
*     - bool empty
*     - void clear
*
*  In addition, the "solve" and "step" methods take a boolean parameter,
*  `withBFS`. If withBFS is true, MazeSolver performs breadth-first search;  
*  otherwise, MazeSolver performs depth-first search. 
*
*  *********************** Maze Exploration Algorithm ***********************
*
*  At the start:
*
*  Create an empty worklist of locations to explore, and add the Start
*  square to the worklist.
*
*  Each step thereafter:
*
*  1. Is the worklist empty? If so, the exit is unreachable; terminate the
*     algorithm.
*  2. Otherwise, grab the "next" square to explore from the worklist.  Call
*     this the "current" square.
*  3. Does the current square correspond to the Exit square? If so, terminate
*     the algorithm and print the path you found.  
*  4. Otherwise, current square is a reachable non-Exit square that we haven't
*     explored yet. Explore it as follows:
*     - for each neighboring square `NS` which is not outside the maze (!) and
*       is not a wall, if `NS` has never been on the worklist then update the
*       `prev` and `status` fields for `NS` and add it to the worklist.
*  5. Update the status field for current square to indicate it has been explored.
*
*  Note:  The neighbors themselves are not "explored" until they are REMOVED
*  from the worklist and checked for their neighbors.
*
*  Square class constants -- status codes must be updated when a square (other
*  than Start or Exit) is:
*      - added to the worklist
*      - removed from the worklist
*      - added to the solution path
*
*     static const int WALL = 0;  // char for printing is: #
*     static const int START = 1; //                       S
*     static const int EXIT = 2;  //                       E
*     static const int UNVISITED = 3; //                   _
*     static const int WORK_LIST = 4; //                   @
*     static const int EXPLORED = 5; //                    .
*     static const int SOLUTION_PATH = 6; //               X
*/

#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include "Maze.h"
#include <deque>

class MazeSolver
{
   private:
      // data members
      Maze * maze;    // pointer to a maze to be solved
      std::deque <Square *> worklist;  // http://www.cplusplus.com/reference/deque/deque/

      // private methods for solving the maze

      /*
      *  @function        step
      *  @param           bool withBFS - if true, treat the worklist as a queue,
      *                   resulting in breadth-first search; otherwise, treat the
      *                   worklist as a stack, resulting in depth-first search
      *  @return          Square * - pointer to the square that was just explored,
      *                   or NULL if no square was explored on this step
      *  @postcondition   status updated for any squares removed/added to the 
      *                   worklist
      *
      *  Note:  Perform one iteration of the maze exploration algorithm given
      *         above (i.e., steps 1 through 5).
      *
      *  Note:  The withBFS parameter defaults to false (DFS)
      *
      *  Note:  If the worklist is empty, just return NULL.
      */
      Square * step(bool withBFS = false);

      /*
      *  @function        backtrace
      *  @return          string - return a string description of the path from
      *                   a given square back to Start as a comma-separated list
      *                   of coordinates [i,j]
      *
      *  @exception       if no such path exists, throw EXC_NO_PATH_TO_START
      *
      *  Example: If Start is at [2,3] and the given square is at [4,1],
      *  the path back to the start might be represented by this string:
      *  "[2,3],[2,2],[3,2],[4,2],[4,1]" (no spaces)
      *
      *  Note: Can be used for debugging.
      */
      std::string backTrace(Square * sq);

      /*
      *  @function        getPathString
      *  @precondition    a path has been found from Start to Exit and can be
      *                   followed in reverse via the `prev` pointers
      *  @return          string - return a string suitable for printing the
      *                   solution path.  For example, if the maze looks like:
      *                   _ _ _ _
      *                   S # # _
      *                   # E _ _
      *                   the the path string is:
      *                   "[1,0],[0,0],[0,1],[0,2],[0,3],[1,3],[2,3],[2,2],[2,1]"
      *                   (no spaces)
      *  @postcondition   each Square on the solution path (except Start and Exit)
      *                   has status == Square::SOLUTION_PATH
      */
      std::string getPathString();

   public:

      /*
      *  Constructor with 1 parameter
      *  
      *  @param		  istream in - input stream containing the symbols 
      *                   representing a maze
      *
      *  @postcondition	  maze is created using the given input stream
      *  @postcondition	  starting square has been added to the worklist
      */
      MazeSolver(std::istream &in);

      /*
      *  Destructor
      */
      ~MazeSolver();

      /*
      *  @function      solve
      *  @param         bool printMaze - if true, print the final state of the
      *                 maze (cout << *maze) before returning
      *  @param         bool withBFS - if true, treat the worklist as a queue,
      *                 resulting in breadth-first search; otherwise, treat the
      *                 worklist as a stack, resulting in depth-first search
      *  @return        string - the path string from Start to Exit or "unsolvable!"
      *                 if no such path was found (maze is unsolvable)
      *
      *  Note:  The withBFS parameter defaults to false (DFS)
      */
      std::string solve(bool printMaze, bool withBFS = false);
      
      /*
      *  @function        reset
      *  @postcondition   maze has been reset
      *  @postcondition   worklist contains only the Start square
      */
      void reset();

};

#endif /* MAZESOLVER_H */

