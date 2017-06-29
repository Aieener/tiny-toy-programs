/*
*  Square.cpp
*  Author: Yuding Ai
*  Date:  Apr 2
*  Lab 9, CS 223
*/

#include <iostream>
#include <sstream>
#include <string>
#include "Square.h"
using namespace std;
#include <cstdlib>


/*!
*  Constructor with 3 parameters
*  @param      int s - status code, should be one of:
*              0 (WALL), 1 (START), 2 (EXIT), 3 (UNVISITED plain square)
*  @param      int r - row index
*  @param      int c - column index
*
*  Note:  initialize `prev` to NULL
*  Note:  if status code s is less than 0 or more than 3, set
*         status to equal WALL
*/
Square::Square(int s, int r, int c)
{
	if(s < 0 || s > 3)
	{
		status = WALL;
	}
	else
	{
		status = s;
	}

	row = r;
	col = c;
	prev = NULL;
}

// *** Setters *** //
/*
*  @function         setStatus
*  @param            int newStatus - an int in the range 3 to 6
*  @postcondition    plain square status is set to newStatus
*  @postcondition    WALL, START, EXIT square status is unchanged
*/
void Square::setStatus(int newStatus)
{
	if(status == UNVISITED || status == WORK_LIST || status == EXPLORED
		|| status == SOLUTION_PATH)
	{
		status = newStatus;
	}
}

/*
*  @function         setPrev
*  @param            Square * ptr - a pointer to a square
*  @postcondition    prev is set to ptr
*/
void Square::setPrev(Square * ptr)
{
	prev = ptr;
}

/*
*  @function         reset
*  @postcondition    plain square status is reset to UNVISITED
*  @postcondition    WALL, START, EXIT square status is unchanged
*/
void Square::reset()
{
	if (status == WORK_LIST || status == EXPLORED
	|| status == SOLUTION_PATH)
	{
		status = UNVISITED;
	}
}

// *** Getters *** //
int Square::getStatus() const
{
	return status;
}
int Square::getRow() const
{
	return row;
}
int Square::getCol() const
{
	return col;
}

Square * Square::getPrev() const
{
	return prev;
}


// *** Other Functionality *** //

/*
*  @function      isStart
*  @return        bool - return true iff this is a Start square
*/
bool Square::isStart() const
{
	if(status == START)
	{
		return true;
	}
	return false;
}

/*
*  @function      isExit
*  @return        bool - return true iff this is an Exit square
*/
bool Square::isExit() const
{
	if(status == EXIT)
	{
		return true;
	}
	return false;
}

/*
*  @function      isPlainSquare
*  @return        bool - return true iff this is a "plain square",
*                 that is, status is UNVISITED, WORK_LIST,
*                 EXPLORED, or SOLUTION_PATH
*/
bool Square::isPlainSquare() const
{
	if(status == UNVISITED || status == WORK_LIST || status == EXPLORED
		|| status == SOLUTION_PATH)
	{
		return true;
	}
	return false;
}

/*
*  @function      getStatusChar
*  @return        char - return the char corresponding to the status, for
*                 printing the maze (WALL = '#', START = 'S', etc.)
*
*  Hint:  Use a switch statement and the class constants (WALL, START,
*         EXIT, etc.) to implement this method.
*/
char Square::getStatusChar() const
{
	char sout = ' ';

	switch(status)
	{
		case 0:
		sout = '#';
		break;
		case 1:
		sout = 'S';
		break;
		case 2:
		sout = 'E';
		break;
		case 3:
		sout = '_';
		break;
		case 4:
		sout = '@';
		break;
		case 5:
		sout = '.';
		break;
		case 6:
		sout = 'X';
	}
	return sout;
}

/*
*  @function      toString
*  @return        string - return a string for reporting the coordinates
*                 of the square
*
*  Example: if the square is in row 5 and column 3, return "[5,3]"
*/

string Square::toString() const
{

	stringstream rs, cs;
	rs << row;
	cs << col;
	string rows = rs.str();
	string cols = cs.str();


	return "[" + rows + "," + cols + "]";
}



















