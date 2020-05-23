#include <iostream>
#include <string>
#include <vector>


#include "../include/declare.h"


int main() 
{
	//Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
  	int init[2] {0 , 0};
  	int goal[2] {4 , 5};
	
	auto board = ReadBoardFile("../include/1.board.txt");
	auto solution = Search(board, init, goal);

	PrintBoard(solution);

}

// int main()
// {
// 	std::vector<std::vector<State>> board = ReadBoardFile("../include/1.board.txt");
// 	PrintBoard(board);
// }
