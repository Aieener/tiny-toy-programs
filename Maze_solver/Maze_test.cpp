/*
*  Maze_test.cpp
*  Author: Yuding Ai
*  Date:  Apr 3
*  Lab 9, CS 223
*/

#include <cassert>
#include "Maze.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
extern string EXC_INVALID_DESC;

void test_basicfunctionality()
{
	stringstream in1;
	string mg;
	mg = "3 4	3 3 1 0 4 3 4 5 3	3 2\n0";
	//**********************
	//*     _ _ S #        *
	//*     _ _ _ _        *
	//*     _ _ E #		   *
	//**********************

	in1<< mg;
	// test Maze constructor;
	Maze m1(in1);

	//*****test Getters*****//

	// test getNumRows & getNumCols: this is a 3 x 4 matrix;
	assert(m1.getNumRows()==3);
	assert(m1.getNumCols()==4);

	//test getStart & getExit;
	assert(m1.getStart()->getStatus()==1); // test status of start: 1 stands for start;
	assert(m1.getStart()->isStart());       // check if it's agreed with Square
	assert(m1.getStart()->toString()=="[0,2]"); // check index of my start;

	assert(m1.getExit()->getStatus()==2); // test status of exit: 2 stands for exit;
	assert(m1.getExit()->isExit());       // check if it's agreed with Square
	assert(m1.getExit()->toString()=="[2,2]"); // check index of my exit;

}

void test_otherfunctionality()
{
	// create a maze;
	stringstream in1;
	string mg;
	mg = "3 4	3 3 1 0 4 3 4 5 3	3 2\n0"; 
	//**********************
	//*     _ _ S #        *
	//*     _ _ _ _        *
	//*     _ _ E #		   *
	//**********************

	in1<< mg;
	Maze m1(in1);


	//***** test getSquare *****//
	assert(m1.getSquare(2,3).getStatus()==0);
	assert(m1.getSquare(0,2).getStatus()==1);
	assert(m1.getSquare(0,0).getStatus()==3);

	//***** test neighbors *****//

	// we will have 9 cases in total;

	// Case 1: normal case that the Square have 4 neighbors;
	vector<Square *> v1 = m1.neighbors(m1.getSquare(1,2));
	assert(v1.size()==4);
	// it's a '_' that will have 4 neighbors: 'S';'_';'E';'_'; and the index of them are the following:
	// up:[0,2]; right:[1,3]; down:[2,2]; left:[1,1];

	// assert(v1[0]->toString()=="[0,2]");
	assert(v1[0]->getStatus()==1);

	assert(v1[1]->toString()=="[1,3]");
	assert(v1[1]->getStatus()==3);

	assert(v1[2]->toString()=="[2,2]");
	assert(v1[2]->getStatus()==2);

	assert(v1[3]->toString()=="[1,1]");
	assert(v1[3]->getStatus()==3);

	// Case 2:edge case,when Square has no left neighbor; 3 neighbors;
	vector<Square *> v2 = m1.neighbors(m1.getSquare(1,0));
	assert(v2.size()==3);
	// it's a '_' that will have 3 neighbors: '_';'_';'_'; and the index of them are the following:
	// up:[0,0]; right:[1,1]; down:[2,0];

	assert(v2[0]->toString()=="[0,0]");
	assert(v2[0]->getStatus()==3);

	assert(v2[1]->toString()=="[1,1]");
	assert(v2[1]->getStatus()==3);

	assert(v2[2]->toString()=="[2,0]");
	assert(v2[2]->getStatus()==3);



	// Case 3:edge case,when Square has no up neighbor; 4 neighbors;
	vector<Square *> v3 = m1.neighbors(m1.getSquare(0,2));
	assert(v3.size()==3);
	// it's a 'S' that will have 3 neighbors: '#';'_';'_'; and the index of them are the following:
	// right:[0,3]; down:[1,2]; left:[0,1];

	assert(v3[0]->toString()=="[0,3]");
	assert(v3[0]->getStatus()==0);

	assert(v3[1]->toString()=="[1,2]");
	assert(v3[1]->getStatus()==3);

	assert(v3[2]->toString()=="[0,1]");
	assert(v3[2]->getStatus()==3);

	// Case 4:edge case,when Square has no right neighbor; 3 neighbors;
	vector<Square *> v4 = m1.neighbors(m1.getSquare(1,3));
	assert(v4.size()==3);
	// it's a '_' that will have 3 neighbors: '#';'#';'_'; and the index of them are the following:
	// up:[0,3]; down:[2,3]; left:[1,2];

	assert(v4[0]->toString()=="[0,3]");
	assert(v4[0]->getStatus()==0);

	assert(v4[1]->toString()=="[2,3]");
	assert(v4[1]->getStatus()==0);

	assert(v4[2]->toString()=="[1,2]");
	assert(v4[2]->getStatus()==3);

	// Case 5:edge case,when Square has no down neighbor; 4 neighbors;
	vector<Square *> v5 = m1.neighbors(m1.getSquare(2,2));
	assert(v5.size()==3);
	// it's a 'E' that will have 3 neighbors: '_';'#';'_'; and the index of them are the following:
	// up:[1,2]; right:[2,3]; left:[2,1];

	assert(v5[0]->toString()=="[1,2]");
	assert(v5[0]->getStatus()==3);

	assert(v5[1]->toString()=="[2,3]");
	assert(v5[1]->getStatus()==0);

	assert(v5[2]->toString()=="[2,1]");
	assert(v5[2]->getStatus()==3);

    // for further reference:
	//**********************
	//*     _ _ S #        *
	//*     _ _ _ _        *
	//*     _ _ E #		   *
	//**********************

	// Case 6:edge case,when Square has no up and left neighbor; 2 neighbors;
	vector<Square *> v6 = m1.neighbors(m1.getSquare(0,0));
	assert(v6.size()==2);
	// it's a '_' that will have 2 neighbors: '_';'_'; and the index of them are the following:
	// right:[0,1]; down:[1,0]; 

	assert(v6[0]->toString()=="[0,1]");
	assert(v6[0]->getStatus()==3);

	assert(v6[1]->toString()=="[1,0]");
	assert(v6[1]->getStatus()==3);

	// Case 7:edge case,when Square has no up and right neighbor; 2 neighbors;
	vector<Square *> v7 = m1.neighbors(m1.getSquare(0,3));
	assert(v7.size()==2);
	// it's a '#' that will have 2 neighbors: '_';'S'; and the index of them are the following:
	// down:[1,3]; left:[0,2]; 

	assert(v7[0]->toString()=="[1,3]");
	assert(v7[0]->getStatus()==3);

	assert(v7[1]->toString()=="[0,2]");
	assert(v7[1]->getStatus()==1);

	// Case 8:edge case,when Square has no down and right neighbor; 2 neighbors;
	vector<Square *> v8 = m1.neighbors(m1.getSquare(2,3));
	assert(v8.size()==2);
	// it's a '#' that will have 2 neighbors: '_';'E'; and the index of them are the following:
	// up:[1,3]; left:[2,2]; 

	assert(v8[0]->toString()=="[1,3]");
	assert(v8[0]->getStatus()==3);

	assert(v8[1]->toString()=="[2,2]");
	assert(v8[1]->getStatus()==2);

	// Case 9:edge case,when Square has no down and left neighbor; 2 neighbors;
	vector<Square *> v9 = m1.neighbors(m1.getSquare(2,0));
	assert(v9.size()==2);
	// it's a '_' that will have 2 neighbors: '_';'_'; and the index of them are the following:
	// up:[1,0]; right:[2,1]; 

	assert(v9[0]->toString()=="[1,0]");
	assert(v9[0]->getStatus()==3);

	assert(v9[1]->toString()=="[2,1]");
	assert(v9[1]->getStatus()==3);

	//***** test toString *****//
	//**********************
	//*     _ _ S #        *
	//*     _ _ _ _        *
	//*     _ _ E #		   *
	//**********************

	string mesg = "\n_ _ S # \n_ _ _ _ \n_ _ E # \n";

	assert(m1.toString() == mesg);

	//***** test output stream *****//
	stringstream out;
	out << m1;
	assert(out.str() == mesg);
	
	//***** test exception *****//
	//test wrong matrix
	stringstream in2;
	string mg2;
	mg2 = "-1 4	3 3 1 0 4 3 4 5 3	3 2\n0";

	in2<< mg2;
	try
	{
	  Maze m2(in2);
	  assert(false);
	}
	catch(string e)
	{
	  assert(e == EXC_INVALID_DESC);
	}

	stringstream in21;
	string mg21;
	mg21 = "1 1	3 3 1 0 4 3 4 5 3	3 2\n0";

	in21<< mg21;
	try
	{
	  Maze m21(in21);
	  assert(false);
	}
	catch(string e)
	{
	  assert(e == EXC_INVALID_DESC);
	}

	//test  no start
	stringstream in3;
	string mg3; 
	mg2 = "3 4	3 3 2 0 4 3 4 5 3	3 2\n0"; 

	in3<< mg3;
	
	try
	{
	  Maze m3(in3);
	  assert(false);
	}
	catch(string e)
	{
	  assert(e == EXC_INVALID_DESC);
	}

	//test no exit
	stringstream in4;
	string mg4;
	mg4 = "3 4	3 3 1 0 4 3 4 5 3	3 3\n0"; 

	in4<< mg4;
	try
	{
	  Maze m4(in4);
	  assert(false);
	}
	catch(string e)
	{
	  assert(e == EXC_INVALID_DESC);
	}
}


int main()
{
	test_basicfunctionality();
	cout << "basicfunctionality Passed! "<<endl;
	test_otherfunctionality();
	cout << "otherfunctionality Passed! "<<endl;
	return 0;
}
