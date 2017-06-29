/*
*  Square.h
*  Square header file for Lab 9, CS 223.
*
*  Barb Wahl & Theresa Wilson
*  3-21-15
*
*  DO NOT CHANGE THIS FILE
*
*  An instance of the Square class represents a single square in the maze.
*
*  Instance variables are as follows:
*     - int `status`:
*           0 -- wall
*           1 -- start
*           2 -- exit
*           3 -- plain square, unvisited
*           4 -- plain square, on solver worklist
*           5 -- plain square, already explored, NOT on final solution path
*           6 -- plain square, already explored, ON final solution path
*
*     - int `row`: indicates the row in which the Square resides in the maze.
*       0 is the topmost row number of the maze.
*
*     - int `col`: indicates the column in which the Square resides in the maze.
*       0 is the leftmost column number of the maze.
*
*     - Square * `prev`: anwers the question, "Which Square was being explored
*       when this Square was added to the worklist?"
*/

#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <string>

class Square
{
   private:

      // instance variables
      int status;
      int row;
      int col;
      Square * prev;

   public:

      /*
      *  STYLE TIP:  Use class constants THROUGHOUT your code for Lab 9, in place
      *  of literal integers, to create readable code.  For example, to ask if the
      *  Square named `sq` is a wall square, you would write
      *        if (sq.getStatus() == Square::WALL)
      *  rather than
      *        if (sq.getStatus() == 0)
      */

      // class constants
         static const int WALL = 0;  // char for printing is: #
         static const int START = 1; //                       S
         static const int EXIT = 2;  //                       E
         static const int UNVISITED = 3; //                   _
         static const int WORK_LIST = 4; //                   @
         static const int EXPLORED = 5; //                    .
         static const int SOLUTION_PATH = 6; //               X

      /*!
      *  Default constructor -- ALREADY IMPLEMENTED right here
      */
      Square() { status = row = col = 0; prev = NULL; }

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
      Square(int s, int r, int c);

      // *** Setters *** //

      /*
      *  @function         setStatus
      *  @param            int newStatus - an int in the range 3 to 6
      *  @postcondition    plain square status is set to newStatus
      *  @postcondition    WALL, START, EXIT square status is unchanged
      */
      void setStatus(int newStatus);

      /*
      *  @function         setPrev
      *  @param            Square * ptr - a pointer to a square 
      *  @postcondition    prev is set to ptr
      */
      void setPrev(Square * ptr);

      /*
      *  @function         reset
      *  @postcondition    plain square status is reset to UNVISITED
      *  @postcondition    WALL, START, EXIT square status is unchanged
      */
      void reset();

      // *** Getters *** //

      int getStatus() const;
      int getRow() const;
      int getCol() const;
      Square * getPrev() const;

      // *** Other Functionality *** //

      /*
      *  @function      isStart
      *  @return        bool - return true iff this is a Start square
      */
      bool isStart() const;

      /*
      *  @function      isExit
      *  @return        bool - return true iff this is an Exit square
      */
      bool isExit() const;

      /*
      *  @function      isPlainSquare
      *  @return        bool - return true iff this is a "plain square",
      *                 that is, status is UNVISITED, WORK_LIST,
      *                 EXPLORED, or SOLUTION_PATH
      */
      bool isPlainSquare() const;

      /*
      *  @function      getStatusChar
      *  @return        char - return the char corresponding to the status, for
      *                 printing the maze (WALL = '#', START = 'S', etc.)
      *
      *  Hint:  Use a switch statement and the class constants (WALL, START,
      *         EXIT, etc.) to implement this method.
      */
      char getStatusChar() const;

      /*
      *  @function      toString
      *  @return        string - return a string for reporting the coordinates
      *                 of the square
      *
      *  Example: if the square is in row 5 and column 3, return "[5,3]"
      */
      std::string toString() const;
};

   /*
   *  operator<<
   *  put a single char, representing the Square status, into the output stream
   */
   std::ostream& operator<< (std::ostream &out, const Square &sq);


#endif /* SQUARE_H */
