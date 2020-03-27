#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

enum class State {kEmpty, kObstacle};


// Parse Lines from the File
// To Complete This Exercise:
// Write a vector<int> ParseLine function which accepts a string as an argument. Use std::istringstream to parse the line by comma chars, and store
// the ints in a vector<int>. ParseLine should return the vector after parsing.
std::vector<State> ParseLine(std::string line) 
{
    std::istringstream sline(line);
    int n;
    char c;
    std::vector<State> row;
  
    while (sline >> n >> c && c == ',') 
	{
      if(n == 0)
	  {
		  row.push_back(State::kEmpty);
	  }
	  else
	  {
		  row.push_back(State::kObstacle);
	  }
    }

    return row;
}

// Reading the board from file 
// To Complete This Exercise:
// Write a function void ReadBoardFile which reads lines from a file. Write each line to cout, followed by a newline character "\n". The 
// function should accept a string argument, which represents the path to the file. For now, since ReadBoardFile does not need to return 
//anything, you can use a void return type.
//Call ReadBoardFile from main using the argument "1.board".
//Before updation:

void ReadBoardFileOLD(std::string path)
{
	std::ifstream myIfstreamObject(path);
	if (myIfstreamObject)
	{
		std::string line;
		while (getline(myIfstreamObject, line))
		{
			std::cout << line << std::endl;
		}
	}
}

// To Complete This Exercise:
// Update ReadBoardFile to use ParseLine and return the board as a vector<vector<int>>. You can read the TODO comments in the code for step by 
//step instructions.
// Update the main function to pass the results of ReadBoardFile to the PrintBoard function.

// After updatoon: use Parse function
std::vector<std::vector<State>> ReadBoardFile(std::string path)
{
	std::ifstream myIfstreamObject(path);
	std::vector<std::vector<State>> board{};
	if (myIfstreamObject)
	{
		std::string line;
		while (getline(myIfstreamObject, line))
		{
			std::vector<State> row = ParseLine(line);
			board.push_back(row);
		}
	}
	return board;
}


std::string CellString(State cell) 
{
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   "; 
  }
}



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

// #include "../include/test.cpp"

int main() 
{
	std::vector<std::vector<State>> board = ReadBoardFile("../include/1.board.txt");
	PrintBoard(board);
}