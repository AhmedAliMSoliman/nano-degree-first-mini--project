#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "../include/declare.h"

// std::string CellString(State cell) 
// {
//   switch(cell) {
//     case State::kObstacle: return "⛰️   ";
//     default: return "0   "; 
//   }
// }

void PrintBoard(const std::vector<std::vector<State>> board) 
{
  for (int i = 0; i < board.size(); i++) 
  {
    for (int j = 0; j < board[i].size(); j++) 
	{
      std::cout << CellString(board[i][j]);
    }
    std::cout << "\n";
  }
}