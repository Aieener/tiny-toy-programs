/*
*  Maze.cpp
*  Author: Yuding Ai
*  Date:  Apr 3
*  Lab 9, CS 223
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Maze.h"
#include <cstdlib>
using namespace std;
extern const string EXC_INVALID_DESC = "Not a valid description of a maze!";

/*
*  Constructor builds a maze from an input stream
*  @param      istream &in - input stream of tokens separated by
*              whitespace and ending with whitespace, as described above.
*
*  Note: After reading the number of rows and number of columns, any
*  token other than 0, 1, 2, or 3 is interpreted as a wall.
*
*  Note:  Once R*C digits have been read and interpreted, the rest of
*  the stream is ignored.
*
*  @exception  throws exception EXC_INVALID_DESC if str is not a valid
*              description of a maze
*/
Maze::Maze(std::istream &in)
{
	string mg;
	in >> mg; // instream the first token as the Row number
	numRows = atoi(mg.c_str());
	in >> mg; // instream the second token as the Col number
	numCols = atoi(mg.c_str());
	start = NULL;
	exit = NULL;

	if (numRows < 0 || numCols < 0 || numRows*numCols == 1)
	{
		throw EXC_INVALID_DESC;
	}

	//Allocate memory
	arr = new Square*[numRows];
	for(int i = 0; i < numRows; i++)
	{
		arr [i] = new Square[numCols];
	}
		
	for(int j = 0 ; j<numRows*numCols; j++)
	{
		int ri, ci; // declare rowindex ri and colindex ci;
		ri = j/numCols;
	    ci = j%numCols;

		in>>mg;     // get status info for the current Square;
		int st = atoi(mg.c_str());  // assign it to the status code 'st';


		if (st == 4 || st == 5 || st == 6)
		{
			st = 3;
		}

		// Assign values
		Square temp = Square(st,ri,ci);
		arr[ri][ci] = temp;

		if(st == 1)
		{
		    // set the start pointer to the address of the 'start' Square
			start = &arr[ri][ci];
            
		}

		else if(st == 2)
		{
		    // set the exit pointer to the address of the 'exit' Square
			exit = &arr[ri][ci];
           
		}
	}

	if(start == NULL || exit == NULL)
	{
		throw EXC_INVALID_DESC;
	}
}


/*
*  Destructor
*/
Maze::~Maze()
{
	for (int i = 0; i < numRows; ++i)
	{
		delete [] arr[i];
	}    
    delete [] arr;
}


// *** Getters *** //
Square * Maze::getStart() const
{	
	return start;
}

Square * Maze::getExit() const
{
	return exit;
}

int Maze::getNumRows() const
{
	return numRows;
}
int Maze::getNumCols() const
{
	return numCols;
}


// *** Other Functionality *** //
/*
*  @function      getSquare
*  @param         int i - row index, in range 0 through numRows - 1
*  @param         int j - column index, in range 0 through numCols - 1
*  @return        Square& - return a reference to the (i,j)-Square stored
*                 in this maze
*/
Square& Maze::getSquare(int i, int j) const
{
	return arr[i][j];
}

/*
*  @function      neighbors
*  @param         Square sq
*  @return        vector <Square *>, a vector of pointers to the Squares
*                 in this maze which are neighbors of `sq`
*
*  Note:  Fill the vector in this order:  North (up one), East (right one),
*  South (down one), and West (left one).
*
*  Note:  If there is NO neighbor in a given direction, the vector will
*  have size < 4.  Corner squares have just two neighbors, and side
*  squares have three neihbors.
*/
vector <Square *> Maze::neighbors(Square sq) const
{
	vector<Square *> v1; // declare vector of pointers to the Squares.

	if (sq.getRow() > 0 && sq.getRow() < numRows-1)
	{
		if(sq.getCol() > 0 && sq.getCol() < numCols-1)
		{
		    // in this situation, the square has 4 neighbors:	

            // find and assign value to the 4 Square pointers;
            Square * up = &arr[sq.getRow()-1][sq.getCol()];
			Square * right =  &arr[sq.getRow()][sq.getCol()+1];
			Square * down =  &arr[sq.getRow()+1][sq.getCol()];
			Square * left =  &arr[sq.getRow()][sq.getCol()-1];

			//push those square pointers to the vector;			
			v1.push_back(up);
			v1.push_back(right);
			v1.push_back(down);
			v1.push_back(left);
			
		}

		else if(sq.getCol() == 0)
		{
			// in this situation, the square has no left neighbors

			// find and assign value to the 3 Square pointers ;
			Square * up = &arr[sq.getRow()-1][sq.getCol()];
			Square * right = &arr[sq.getRow()][sq.getCol()+1];
			Square * down = &arr[sq.getRow()+1][sq.getCol()];

			//push those square pointers to the vector;			
			v1.push_back(up);
			v1.push_back(right);
			v1.push_back(down);
		}

		else if(sq.getCol() == numCols-1)
		{
			// in this situation, the square has no right neighbors

			// find and assign value to the 3 Square pointers;
			Square * up = &arr[sq.getRow()-1][sq.getCol()];
			Square * down = &arr[sq.getRow()+1][sq.getCol()];
			Square * left = &arr[sq.getRow()][sq.getCol()-1];
			//push those square pointers to the vector;			
			v1.push_back(up);
			v1.push_back(down);
			v1.push_back(left);
		}

	}

	else if (sq.getRow()== 0)
	{
		if(sq.getCol() > 0 && sq.getCol() < numCols-1)
		{
			// in this situation, the square has no up neighbors

            // find and assign value to the 3 Square pointers;
			Square * right = &arr[sq.getRow()][sq.getCol()+1];
			Square * down = &arr[sq.getRow()+1][sq.getCol()];
			Square * left = &arr[sq.getRow()][sq.getCol()-1];

			//push those square pointers to the vector;			
			v1.push_back(right);
			v1.push_back(down);
			v1.push_back(left);
		}

		else if(sq.getCol() == 0)
		{
			// in this situation, the square has no up and left neighbors

			Square * right =  &arr[sq.getRow()][sq.getCol()+1];
			Square * down = &arr[sq.getRow()+1][sq.getCol()];
			v1.push_back(right);
			v1.push_back(down);
		}

		else if(sq.getCol() == numCols-1)
		{
			// in this situation, the square has no up and right neighbors

			Square * down = &arr[sq.getRow()+1][sq.getCol()];
			Square * left = &arr[sq.getRow()][sq.getCol()-1];

			v1.push_back(down);
			v1.push_back(left);
		}
	}

	else if (sq.getRow()== numRows-1)
	{
		if(sq.getCol() > 0 && sq.getCol() < numCols-1)
		{
			// in this situation, the square has no down neighbors

            // find and assign value to  the 3 Square pointers;
			Square * up = &arr[sq.getRow()-1][sq.getCol()];
			Square * right = &arr[sq.getRow()][sq.getCol()+1];
			Square * left = &arr[sq.getRow()][sq.getCol()-1];

			//push those square pointers to the vector;			
			v1.push_back(up);
			v1.push_back(right);
			v1.push_back(left);
		}

		else if(sq.getCol() == 0)
		{
			// in this situation, the square has no down and left neighbors

			Square * up = &arr[sq.getRow()-1][sq.getCol()];
			Square * right = &arr[sq.getRow()][sq.getCol()+1]; 

			v1.push_back(up);
			v1.push_back(right);						
		}

		else if(sq.getCol() == numCols-1)
		{
			// in this situation, the square has no down and right neighbors

			Square * up = &arr[sq.getRow()-1][sq.getCol()];
			Square * left = &arr[sq.getRow()][sq.getCol()-1];

			//push those square pointers to the vector;			
			v1.push_back(up);
			v1.push_back(left);

		}
	}
	
	return v1;
}

/* @function         reset - erase all "markings" on maze squares but keep
*                    the same layout
*  @postcondition    all squares in maze have status WALL, START, EXIT,
*                    or UNVISITED
*/
void Maze::reset()
{
	for(int i = 0; i < numRows; i++)
	{
		for(int j = 0; j < numCols; j++)
		{
			if (getSquare(i,j).isPlainSquare())
			{
				getSquare(i,j).setStatus(3);
			}
		}
	}
}

/*
*  @function      toString
*  @return        a string for printing the "text" version of the maze
*
*  For example, the text version might look like
*        _ _ _ _
*        S # # _
*        # E _ _
*  when printed, which would correspond to the string
*  "\n_ _ _ _ \nS # # _ \n# E _ _ \n"
*
*  Insert a newline at the very front (so the maze will start in column 0),
*  insert a space (" ") after each statusChar, and insert a newline ("\n")
*  at the end of each row.
*/
string Maze::toString() const
{
	stringstream in;
	string temp;
	string mg ="\n";
	for(int i = 0; i < numRows; i++)
	{
		for(int j = 0; j < numCols; j++)
		{
			char sta = getSquare(i,j).getStatusChar();
			mg = mg + sta + " ";
		}
		mg = mg + "\n";
	}

	return mg;

}


/*
*  output stream operator, for printing the "text" version of the maze
*
*  Hint:  Call toString() on the given maze and put that result into the
*  output stream.
*/
std::ostream& operator<< (std::ostream &out, const Maze &maze)
{
	out<< maze.toString();
	return out;
}















