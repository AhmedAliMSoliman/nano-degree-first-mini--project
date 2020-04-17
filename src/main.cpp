#include <iostream>
#include <string>
#include <vector>


#include "../include/declare.h"
// #include "../include/test.cpp"
#include "../include/test_heuristic.cpp"
#include "../include/test_addtoopen.cpp"
#include "../include/test_compare.cpp"
#include "../include/test_search.cpp"

//Tests
void Tests()
{
	TestHeuristic();
	TestAddToOpen();
	TestCompare();
	TestSearch();
}

main() 
{
	//Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
  	int init[2] {0 , 0};
  	int goal[2] {4 , 5};
	
	auto board = ReadBoardFile("../include/1.board.txt");
	auto solution = Search(board, init, goal);

	PrintBoard(solution);

	
	Tests();
}

// int main()
// {
// 	std::vector<std::vector<State>> board = ReadBoardFile("../include/1.board.txt");
// 	PrintBoard(board);
// }