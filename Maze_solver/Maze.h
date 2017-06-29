/*
*  Maze.h
*  Maze header file for Lab 9, CS 223.
*
*  Barb Wahl & Theresa Wilson,
*  3-21-15
*
*  DO NOT CHANGE THIS FILE
*
*  A maze is represented by a 2-dimensional dynamic array of Squares.
*
*  Every maze has one start square and one exit square.
*  Some mazes are impossible to solve.
*  Some mazes have a unique solution path.
*  Some mazes have two or more solution paths.
*
*  A maze is read from an input stream of the following format:
*      - The tokens are separated by any kind of whitespace characters (spaces,
*        tabs, newlines).
*      - The first token is a positive integer representing the number of 
*        rows R in the maze.
*      - The second token is a positive integer representing the number of
*        columns C in the maze.
*      - The rest of the file is a sequence of digits, separated by whitespace,
*        in the range 0 through 3.  These digits describe the maze squares,
*        from left to right and top to bottom:
*           > The first C numbers correspond to the top row, left to right.
*           > The next C numbers correspond to the second row, left to right,
*             and so on.
*           > Each digit in the sequence is interpreted as a type of square:
*                 0 => wall (#)
*                 1 => start (S)
*                 2 => exit (E)
*                 3 => plain square, unvisited (_)
*             Notice that these interpretations match the Square class constants
*             (Square::WALL == 0, Square::START == 1, Square::EXIT == 2, etc.)
*      - If the sequence of tokens following the values for R and C is longer
*        than R*C, the excess values are simply ignored.
*      - There will be at least one whitespace character after the last token.
*
*  For example, if the stream contents are as follows:
*  3 4   3 3 3   3 1 0  \n 0 3 0 2 3 3 \n
*
*  then the maze will have 3 rows, 4 columns, and look as follows when printed:
*        _ _ _ _
*        S # # _
*        # E _ _
*/

#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "Square.h"

class Maze
{
   private:
      Square ** arr;  // pointer to a 2-dimensional dynamic array of Squares
      int numRows;    // number of rows in the maze
      int numCols;    // number of cols in the maze
      Square * start; // pointer to the start Square
      Square * exit;  // pointer to the exit Square

      // disabled copy constructor (not needed, don't implement)
      Maze(const Maze &other);

      // disabled assignment operator (not needed, don't implement)
      Maze& operator=(const Maze &other);

   public:
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
      Maze(std::istream &in);

      /*
      *  Destructor
      */
      ~Maze();

      // *** Getters *** //
      Square * getStart() const;
      Square * getExit() const;
      int getNumRows() const;
      int getNumCols() const;

      // *** Other Functionality *** //



      /*
      *  @function      getSquare
      *  @param         int i - row index, in range 0 through numRows - 1
      *  @param         int j - column index, in range 0 through numCols - 1
      *  @return        Square& - return a reference to the (i,j)-Square stored
      *                 in this maze
      */
      Square& getSquare(int i, int j) const;

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
      std::vector <Square *> neighbors(Square sq) const;

      /* @function         reset - erase all "markings" on maze squares but keep
      *                    the same layout
      *  @postcondition    all squares in maze have status WALL, START, EXIT,
      *                    or UNVISITED
      */
      void reset();

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
      std::string toString() const;

   };

   /*
   *  output stream operator, for printing the "text" version of the maze
   *
   *  Hint:  Call toString() on the given maze and put that result into the
   *  output stream.
   */
   std::ostream& operator<< (std::ostream &out, const Maze &maze);

#endif /* MAZE_H */

