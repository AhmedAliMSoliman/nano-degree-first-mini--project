
#include <iostream>
#include <vector>

#include "../include/declare.h"


// To Complete This Exercise:
// Write a std::vector<vector<State>> Search function stub which takes a board grid and two length 2 int arrays as arguments. The int arrays will represent
// the start and goal coordinates for the search. The function should print ""No path found!" and return an empty std::vector<vector<State>>. The function 
// will later return the board with a path from the start to the goal.
// In main(), call Search with a start of {0, 0} and a goal of {4, 5}. Store the results in the variable solution.
// Pass solution to PrintBoard.
std::vector<std::vector<State>> Search(std::vector<std::vector<State>> grid, int init[2], int goal[2])
{
    std::cout << "No path found for now_-_" << "\n";
    return std::vector<std::vector<State>> {};
}

// To Complete This Exercise:
// Write an int Heuristic function which takes four ints as arguments. The ints represent two pairs of 2D coordinates: (x1, y1, x2, y2).  The function 
// should return an int which is the Manhattan Distance from one coordinate to the other: |x2 - x1| + |y2 - y1|
int Heuristic(int x1, int y1, int x2, int y2)
{
	int manhattan;
	manhattan = abs(x2 - x1) + abs(y2 - y1);
	return manhattan;
}

// To Complete This Exercise:
// 1. Write a void AddToOpen function which accepts the following arguments:
// * Four ints, one for each of the x, y, g, and h values.
// * References to one vector<vector<int>> for the vector of open nodes.
// Reference to one std::vector<std::vector<State>> for the grid.
// 2. The AddToOpen function should do two things:
// Create a vector<int> node with the form {x, y, g, h} and push the node to the back of the open vector.
// Set the grid value for the x and y coordinates to the enum value kClosed. We have added kClosed to the set of enum values
void AddToOpen(int x , int y , int g , int h, std::vector<std::vector<int>>& openlist, std::vector<std::vector<State>>& grid)
{
	openlist.push_back(std::vector<int>{x, y, g, h});
	grid[x][y] = State::kClosed;
}