/*
*  MazeSolver.cpp
*  Author: Yuding Ai
*  Date:  Apr 6 2015
*  Lab 9, CS 223
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MazeSolver.h"
#include <cstdlib>
#include <deque>
using namespace std;

extern const string EXC_NO_PATH_TO_START = "No-path-to-start exception!";

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
Square * MazeSolver::step(bool withBFS)
{

     if (withBFS == true) // perform as BFS -->queue;
     {
		// grab the "next" square to explore;
		Square * curr = worklist.front();

		// check if the curr Square is Exit;
		if(curr->getStatus() == 2)
		{
			//terminate it;
			return curr;
		}

		else // current square is a reachable non-Exit square, we explore it now;
		{
			// pop the current Square and store it's value;
			// Update the status field for current square to indicate it has been explored.
            curr->setStatus(5);

			// pop the explored Square pointer
			worklist.pop_front();

			// find the "neignbor" Square;
			vector<Square *> v = maze->neighbors(*curr);

			// grab them into the worklist;
			int s = v.size();
			for(int i = 0; i < s; i++)
			{
				// add neighbor to the stack:
				// we don't push "WALL" into the worklist and
				// we don't push Square pointer if it's already on the list or explored
				if (v[i]->getStatus()== 3 || v[i]->getStatus()== 2)
				{

					//push the neighbor Square pointers into worklist;

					worklist.push_back(v[i]);

					// update prev codes;
					v[i]->setPrev(curr);
					// updated status codes;
					v[i]->setStatus(4);
				}
			}
			// check if it is empty
			if (worklist.empty())
			{
				//the exit is unreachable, terminate it.
				return NULL;
			}
			// return the pointer to the square that was just explored
			return curr;
		}

	}

	else  //perform as DFS -->stack;
	{
		// grab the "next" square to explore;
		Square * curr = worklist.front();

		// check if the curr Square is Exit;
		if(curr->getStatus() == 2)
		{
			//terminate it;
			return curr;
		}

		else // current square is a reachable non-Exit square, we explore it now;
		{
			// pop the current Square and store it's value;
			// Update the status field for current square to indicate it has been explored.
            curr->setStatus(5);

			// pop the explored Square pointer
			worklist.pop_front();

			// find the "neignbor" Square;
			vector<Square *> v = maze->neighbors(*curr);
			int s = v.size();

			// grab them into the worklist;
			for(int i = 0; i < s; i++)
			{
				// add neighbor to the stack:
				// we don't push "WALL" into the worklist and
				// we don't push Square pointer if it's already on the list or explored
				if (v[i]->getStatus()== 3 || v[i]->getStatus()== 2)
				{
					//push the neighbor Square pointers into worklist;
					worklist.push_front(v[i]);
					// update prev codes;
					v[i]->setPrev(curr);
					// updated status codes;
					v[i]->setStatus(4);
					// cout << v[i]->getPrev()->toString()<<endl;
				}
			}

			if (worklist.empty())
			{
				//the exit is unreachable, terminate it.
				return NULL;
			}
			// return the pointer to the square that was just explored
			return curr;
		}
	}
}

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
std::string MazeSolver::backTrace(Square * sq)
{
	// temp pointer point to sq;
	Square * temp = sq;
	// initialize the path to the index of sq;
	string path= temp->toString();
	// update temp;
	temp = temp->getPrev();

	while(temp->getStatus() != 1)
	{
		// create accumulator;
		string acc = temp->toString();
		path = path + "," + acc;
		// update status of Square temp pointing to to SOLUTION_PATH;
		temp->setStatus(6);
		// update temp;
		temp = temp->getPrev();
	}
	path =  path +"," + maze->getStart()->toString();

	return path;
}

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
std::string MazeSolver::getPathString()
{
	// temp pointer point to the exit;
	Square * temp = maze->getExit();
	// initialize the path to the index of exit;
	string path= temp->toString();
	// update temp;
	temp = temp->getPrev();

	while(temp->getStatus() != 1)
	{
		// create accumulator;
		string acc = temp->toString();
		path = acc +"," + path;
		// update status to SOLUTION_PATH;
		temp->setStatus(6);
		// update temp;
		temp = temp->getPrev();
	}
	path = temp->toString() +"," + path;

	return path;
}

/*
*  Constructor with 1 parameter
*
*  @param		  istream in - input stream containing the symbols
*                   representing a maze
*
*  @postcondition	  maze is created using the given input stream
*  @postcondition	  starting square has been added to the worklist
*/
MazeSolver::MazeSolver(std::istream &in)
{
	// create Maze;
	maze = new Maze(in);
	// create a curr pointer point to the start point;
	Square * curr = maze->getStart();
	// add the start Square pointer into the worklist;
	worklist.push_front(curr);
}

/*
*  Destructor
*/
MazeSolver::~MazeSolver()
{
	delete maze;
}

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
std::string MazeSolver::solve(bool printMaze, bool withBFS)
{

	while(worklist.front()->getStatus() != 2)
	{
		if (step(withBFS) == NULL)
		{
			return "unsolvable!";
		}
	}

	string out = getPathString();

	if(printMaze)
	{
		cout << *maze;
	}

	return out;
}


/*
*  @function        reset
*  @postcondition   maze has been reset
*  @postcondition   worklist contains only the Start square
*/
void MazeSolver::reset()
{
	maze->reset();
	worklist.clear();

	Square * curr = maze->getStart();
	// add the start Square pointer into the worklist;
	worklist.push_back(curr);
}


