#include <iostream>
#include <string>
#include <vector>


#include "../include/declare.h"


int main() 
{
	//Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
  	int init[2] {0 , 0};
  	int goal[2] {4 , 5};
	
	auto board1 = ReadBoardFile("../include/1.board.txt");
	auto solution = Search(board1, init, goal);

	auto board2 = ReadBoardFile("../include/2.board.txt");
	auto solution2 = Search(board2, init, goal);

	PrintBoard(solution);
	std::cout << "-----------\n";
	PrintBoard(solution2);

}

// int main()
// {
// 	std::vector<std::vector<State>> board = ReadBoardFile("../include/1.board.txt");
// 	PrintBoard(board);
// }
