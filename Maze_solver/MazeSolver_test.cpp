/*
*  MazeSolver_test.cpp
*  
*  Thersea Wilson
*  3/27/15
*/

#include <string>
#include <cassert>
#include <iostream>
#include <fstream>
#include "MazeSolver.h"

using namespace std;

void mazetest1()
{
    string solution, solverout;

    cout << "Testing maze: maze_b1.txt" << endl;
    ifstream mazefile1("maze_b1.txt");
    MazeSolver solver(mazefile1);
    mazefile1.close();

    cout << "  DFS....." << flush;
    solution = "[1,0],[0,0],[0,1],[0,2],[0,3],[1,3],[2,3],[2,2],[2,1]";
    solverout = solver.solve(false);
    assert(solution == solverout);
    cout << "PASSED" << endl;

    cout << "  BFS....." << flush;
    solver.reset();
    solution = "[1,0],[0,0],[0,1],[0,2],[0,3],[1,3],[2,3],[2,2],[2,1]";
    solverout = solver.solve(false,true);
    assert(solution == solverout);
    cout << "PASSED" << endl;
}

void mazetest2()
{
    string solution, solverout;

    cout << "Testing maze: maze_b2.txt" << endl;
    ifstream mazefile1("maze_b2.txt");
    MazeSolver solver(mazefile1);
    mazefile1.close();

    cout << "  DFS....." << flush;
    solution = "[3,7],[3,6],[2,6],[1,6],[1,5],[1,4],[1,3],[2,3],[3,3],[3,2],[3,1],[4,1],[5,1],[5,2],[5,3],[5,4],[5,5],[6,5],[7,5],[7,4],[7,3],[7,2]";
    solverout = solver.solve(false);
    assert(solution == solverout);
    cout << "PASSED" << endl;

    cout << "  BFS....." << flush;
    solver.reset();
    solution = "[3,7],[3,6],[2,6],[1,6],[1,5],[1,4],[1,3],[2,3],[3,3],[3,2],[3,1],[4,1],[5,1],[5,2],[5,3],[5,4],[5,5],[6,5],[7,5],[7,4],[7,3],[7,2]";
    solverout = solver.solve(false,true);
    assert(solution == solverout);
    cout << "PASSED" << endl;
}

void mazetest3()
{
    string solution, solverout;

    cout << "Testing maze: maze_t1.txt" << endl;
    ifstream mazefile1("maze_t1.txt");
    MazeSolver solver(mazefile1);
    mazefile1.close();

    cout << "  DFS....." << flush;
    solution = "[0,1],[1,1],[1,0],[2,0]";
    solverout = solver.solve(false);
    assert(solution == solverout);
    cout << "PASSED" << endl;

    cout << "  BFS....." << flush;
    solver.reset();
    solution = "[0,1],[1,1],[1,0],[2,0]";
    solverout = solver.solve(false,true);
    assert(solution == solverout);
    cout << "PASSED" << endl;
}

void mazetest4()
{
    string solution, solverout;

    cout << "Testing maze: maze_t2.txt" << endl;
    ifstream mazefile1("maze_t2.txt");
    MazeSolver solver(mazefile1);
    mazefile1.close();

    cout << "  DFS....." << flush;
    solution = "[0,1],[0,0],[1,0],[1,1]";
    solverout = solver.solve(false);
    assert(solution == solverout);
    cout << "PASSED" << endl;

    cout << "  BFS....." << flush;
    solver.reset();
    solution = "[0,1],[1,1]";
    solverout = solver.solve(false,true);
    assert(solution == solverout);
    cout << "PASSED" << endl;
}

void mazetest5()
{
    string solution, solverout;

    cout << "Testing maze: maze_t3.txt" << endl;
    ifstream mazefile1("maze_t3.txt");
    MazeSolver solver(mazefile1);
    mazefile1.close();

    cout << "  DFS....." << flush;
    solution = "unsolvable!";
    solverout = solver.solve(false);
    assert(solution == solverout);
    cout << "PASSED" << endl;

    cout << "  BFS....." << flush;
    solver.reset();
    solution = "unsolvable!";
    solverout = solver.solve(false,true);
    assert(solution == solverout);
    cout << "PASSED" << endl;
}

//******************************* plug in more tests! *************************//
void mazetest6()  // for b3
{
    string solution, solverout;

    cout << "Testing maze: maze_b3.txt" << endl;
    ifstream mazefile1("maze_b3.txt");
    MazeSolver solver(mazefile1);
    mazefile1.close();

    cout << "  DFS....." << flush;
    solution = "[24,1],[24,0],[23,0],[22,0],[21,0],[20,0],[20,1],[20,2],[20,3],[20,4],[21,4],[21,5],[21,6],[20,6],[20,7],[20,8],[20,9],[19,9],[19,10],[19,11],[18,11],[17,11],[16,11],[15,11],[15,10],[15,9],[15,8],[14,8],[13,8],[13,9],[12,9],[11,9],[11,8],[11,7],[11,6],[11,5],[10,5],[10,4],[10,3],[10,2],[9,2],[8,2],[7,2],[7,1],[6,1],[5,1],[5,2],[5,3],[4,3],[4,4],[4,5],[5,5],[5,6],[5,7],[6,7],[6,8],[6,9],[6,10],[5,10],[4,10],[4,9],[3,9],[2,9],[2,10],[2,11],[2,12],[3,12],[4,12],[4,13],[4,14],[4,15],[5,15],[6,15],[6,16],[6,17],[5,17],[4,17],[3,17],[3,18],[3,19],[2,19],[1,19],[1,20],[1,21],[2,21],[2,22],[3,22],[3,23],[3,24],[3,25],[4,25],[5,25],[6,25],[7,25],[8,25],[9,25],[9,24],[9,23],[9,22],[9,21],[9,20],[9,19],[10,19],[11,19],[12,19],[13,19],[14,19],[14,20],[14,21],[14,22],[14,23],[14,24],[15,24],[15,25],[16,25],[17,25],[18,25],[19,25],[20,25],[21,25],[22,25],[23,25],[24,25],[25,25],[26,25],[26,26]";
    solverout = solver.solve(true);
    assert(solution == solverout);
    cout << "PASSED" << endl;

    cout << "  BFS....." << flush;
    solver.reset();
    solution = "[24,1],[25,1],[25,2],[25,3],[25,4],[25,5],[26,5],[26,6],[26,7],[26,8],[26,9],[26,10],[26,11],[26,12],[26,13],[26,14],[26,15],[26,16],[26,17],[26,18],[26,19],[26,20],[26,21],[26,22],[26,23],[26,24],[26,25],[26,26]";
    solverout = solver.solve(true,true);
    assert(solution == solverout);
    cout << "PASSED" << endl;
}

void mazetest7() // for b4
{
    string solution, solverout;

    cout << "Testing maze: maze_b4.txt" << endl;
    ifstream mazefile1("maze_b4.txt");
    MazeSolver solver(mazefile1);
    mazefile1.close();

    cout << "  DFS....." << flush;
    solution = "[0,0],[1,0],[2,0],[3,0],[3,1],[3,2],[2,2],[1,2],[0,2]";
    solverout = solver.solve(false);
    assert(solution == solverout);
    cout << "PASSED" << endl;

    cout << "  BFS....." << flush;
    solver.reset();
    solution = "[0,0],[0,1],[0,2]";
    solverout = solver.solve(false,true);
    assert(solution == solverout);
    cout << "PASSED" << endl;
}

void mazetest8() // for maze_hv1.txt
{
    string solution, solverout;

    cout << "Testing maze: maze_hv1.txt" << endl;
    ifstream mazefile1("maze_hv1.txt");
    MazeSolver solver(mazefile1);
    mazefile1.close();

    cout << "  DFS....." << flush;
    solution = "[0,0],[1,0],[2,0],[3,0],[4,0],[4,1],[5,1],[6,1],[7,1],[8,1],[9,1],[9,2],[9,3],[9,4],[9,5],[9,6],[9,7],[9,8],[9,9],[8,9]";
    solverout = solver.solve(false);
    assert(solution == solverout);
    cout << "PASSED" << endl;

    cout << "  BFS....." << flush;
    solver.reset();
    solution = "[0,0],[1,0],[2,0],[3,0],[4,0],[4,1],[5,1],[6,1],[7,1],[8,1],[9,1],[9,2],[9,3],[9,4],[9,5],[9,6],[9,7],[9,8],[9,9],[8,9]";
    solverout = solver.solve(false,true);
    assert(solution == solverout);
    cout << "PASSED" << endl;
}

void mazetest9() // for maze_hv2.txt
{
    string solution, solverout;

    cout << "Testing maze: maze_hv2.txt" << endl;
    ifstream mazefile1("maze_hv2.txt");
    MazeSolver solver(mazefile1);
    mazefile1.close();

    cout << "  DFS....." << flush;
    solution = "unsolvable!";
    solverout = solver.solve(false);
    assert(solution == solverout);
    cout << "PASSED" << endl;

    cout << "  BFS....." << flush;
    solver.reset();
    solution = "unsolvable!";
    solverout = solver.solve(false,true);
    assert(solution == solverout);
    cout << "PASSED" << endl;
}

void mazetest10() //  for maze_t4.txt
{
    string solution, solverout;

    cout << "Testing maze: maze_t4.txt" << endl;
    ifstream mazefile1("maze_t4.txt");
    MazeSolver solver(mazefile1);
    mazefile1.close();

    cout << "  DFS....." << flush;
    solution = "[1,7],[1,6],[1,5],[1,4],[1,3],[1,2],[1,1],[1,0],[2,0],[3,0],[4,0],[4,1],[4,2],[4,3],[4,4],[4,5],[4,6],[4,7],[3,7]";
    solverout = solver.solve(false);
    assert(solution == solverout);
    cout << "PASSED" << endl;

    cout << "  BFS....." << flush;
    solver.reset();
    solverout = solver.solve(false,true);
    solution = "[1,7],[1,6],[2,6],[3,6],[3,7]";
    assert(solution == solverout);
    cout << "PASSED" << endl;
}

void mazetest11() //  for maze_t5.txt
{
    string solution, solverout;

    cout << "Testing maze: maze_t5.txt" << endl;
    ifstream mazefile1("maze_t5.txt");
    MazeSolver solver(mazefile1);
    mazefile1.close();

    cout << "  DFS....." << flush;
    solution = "[7,7],[7,8],[7,9],[8,9],[9,9],[9,8],[9,7],[9,6],[9,5],[9,4],[9,3],[8,3],[7,3],[6,3],[5,3],[4,3],[3,3],[3,4],[3,5],[3,6],[3,7],[3,8],[3,9],[3,10],[3,11],[3,12],[3,13],[4,13],[5,13],[6,13],[7,13],[8,13],[9,13],[10,13],[11,13],[12,13],[13,13],[13,12],[13,11],[13,10],[13,9],[13,8],[13,7],[13,6],[13,5],[13,4],[13,3],[13,2],[13,1],[13,0]";
    solverout = solver.solve(false);
    assert(solution == solverout);
    cout << "PASSED" << endl;

    cout << "  BFS....." << flush;
    solver.reset();
    solverout = solver.solve(false,true);
    solution = "[7,7],[7,8],[7,9],[8,9],[9,9],[9,8],[9,7],[9,6],[9,5],[9,4],[9,3],[8,3],[7,3],[6,3],[5,3],[4,3],[3,3],[3,4],[3,5],[3,6],[3,7],[3,8],[3,9],[3,10],[3,11],[3,12],[3,13],[4,13],[5,13],[6,13],[7,13],[8,13],[9,13],[10,13],[11,13],[12,13],[13,13],[13,12],[13,11],[13,10],[13,9],[13,8],[13,7],[13,6],[13,5],[13,4],[13,3],[13,2],[13,1],[13,0]";
    assert(solution == solverout);
    cout << "PASSED" << endl;
}


int main()
{
    cout << "Testing MazeSolver" << endl;
    cout << "------------------" << endl;

    mazetest1();
    mazetest2();
    mazetest3();
    mazetest4();
    mazetest5();
    mazetest6();
    mazetest7();
    mazetest8();
    mazetest9();
    mazetest10();
    mazetest11();

    cout << "----------------------------------" << endl;
    cout << "Congratulations! All tests passed!" << endl;

}
