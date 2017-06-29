/*
*  Square_test.cpp
*  Author: Yuding Ai
*  Date:  Apr 2
*  Lab 9, CS 223
*/
#include <cassert>
#include "Square.h"
#include <iostream>
#include <sstream>

using namespace std;

void test_basic_functionality()
{
	//*&*&*&*&*&*&*&* test with default constructor *&*&*&*&*&*&*&*&*&*//
	Square s1;

	//***** test getters *****//
	// check prev and test getPrev()
	assert(s1.getPrev() == NULL);
	assert(s1.getStatus() == 0);
	assert(s1.getRow()== 0);
	assert(s1.getCol()== 0);

	//***** test setter *****//

	//test edge case of setStatus
	s1.setStatus(4);// since status is 0 here, is should not change;
	assert(s1.getStatus() == 0);

	//test edge case of reset
	s1.reset(); // since status is 0 here, is should not change;
	assert(s1.getStatus() == 0);


	//*&*&*&*&*&*&*&* test with regular constructor *&*&*&*&*&*&*&*&*&*//
	Square s2 = Square(3,3,4);

	//***** test getters *****//
	assert(s2.getPrev() == NULL);
	assert(s2.getStatus() == 3);
	assert(s2.getRow()== 3);
	assert(s2.getCol()== 4);

	//***** test setter *****//
	//test set prev;
	Square * temp;
	temp = &s1; // temp pointer point to s1;
	s2.setPrev(temp);// now my *s2.getPrev() should be s1;
	assert((*s2.getPrev()).getPrev() == NULL);
	assert((*s2.getPrev()).getStatus() == 0);
	assert((*s2.getPrev()).getRow()== 0);
	assert((*s2.getPrev()).getCol()== 0);

    // test setStatus;
	s2.setStatus(4);// since s2's original status is unvisited, it will change
					// to 4: WORK_LIST;
	assert(s2.getStatus() == 4);

	// test reset;
	s2.reset();// now my status of s2 should reset to 3: unvisited from 4:WORK_LIST
	assert(s2.getStatus() == 3);

}

void test_other_functionality()
{
	Square s1;
	assert(s1.getStatusChar()=='#');// check the status and test getStatusChar;
	assert(s1.isExit() == false);  // test isExit;
	assert(s1.isPlainSquare() == false); //test isPlainSquare;
	assert(s1.isStart() == false); // test isStart;
	assert(s1.toString() == "[0,0]"); // test tostring


	Square s2 = Square(2,3,4);
	assert(s2.getStatusChar()=='E'); // check the status and test getStatusChar;
	assert(s2.isExit());  // test isExit;
	assert(s2.isPlainSquare() == false); //test isPlainSquare;
	assert(s2.isStart() == false); // test is Start;
	assert(s2.toString() == "[3,4]");// test tostring

	Square s0 = Square(1,3,7);
	assert(s0.getStatusChar()=='S'); // check the status and test getStatusChar;
	assert(s0.isExit() == false);  // test isExit;
	assert(s0.isPlainSquare() == false); //test isPlainSquare;
	assert(s0.isStart()); // test is Start;
	assert(s0.toString() == "[3,7]");// test tostring

	Square s3 = Square(3,3,4);
	assert(s3.getStatusChar()=='_');// check the status and test getStatusChar;
	assert(s3.isExit() == false);  // test isExit;
	assert(s3.isPlainSquare()); //test isPlainSquare;
	assert(s3.isStart() == false); // test is Start;
	assert(s3.toString() == "[3,4]");// test tostring

	s3.setStatus(4);
	assert(s3.getStatusChar()=='@');// check the status and test getStatusChar;
	assert(s3.isPlainSquare()); //test isPlainSquare with status = 4;
	s3.setStatus(5);
	assert(s3.getStatusChar()=='.');// check the status and test getStatusChar;
	assert(s3.isPlainSquare()); //test isPlainSquare with status = 5;
	s3.setStatus(6);
	assert(s3.getStatusChar()=='X');// check the status and test getStatusChar;
	assert(s3.isPlainSquare()); //test isPlainSquare with status = 6;



}




int main()
{
	test_basic_functionality();
	cout << "basic_functionality passed!"<<endl;

	test_other_functionality();
	cout << "other_functionality passed!"<<endl;

	return 0;
}