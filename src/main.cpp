#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

// Parse Lines from the File
// To Complete This Exercise:
// Write a vector<int> ParseLine function which accepts a string as an argument. Use std::istringstream to parse the line by comma chars, and store
// the ints in a vector<int>. ParseLine should return the vector after parsing.
std::vector<int> ParseLine(std::string line) 
{
    std::istringstream sline(line);
    int n;
    char c;
    std::vector<int> row;
  
    while (sline >> n >> c && c == ',') 
	{
      row.push_back(n);
    }
    return row;
}

// Reading the board from file 
// To Complete This Exercise:
// Write a function void ReadBoardFile which reads lines from a file. Write each line to cout, followed by a newline character "\n". The 
// function should accept a string argument, which represents the path to the file. For now, since ReadBoardFile does not need to return 
//anything, you can use a void return type.
//Call ReadBoardFile from main using the argument "1.board".
void ReadBoardFile(std::string path)
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

#include "../include/test.cpp"

int main() 
{
	ReadBoardFile("../include/1.board.txt");
	TestParseLine();
}