
#include <iostream>
#include <vector>
#include <algorithm>

#include "../include/declare.h"


// To Complete This Exercise:
// Write a std::vector<vector<State>> Search function stub which takes a board grid and two length 2 int arrays as arguments. The int arrays will represent
// the start and goal coordinates for the search. The function should print ""No path found!" and return an empty std::vector<vector<State>>. The function 
// will later return the board with a path from the start to the goal.
// In main(), call Search with a start of {0, 0} and a goal of {4, 5}. Store the results in the variable solution.
// Pass solution to PrintBoard.

// std::vector<std::vector<State>> Search(std::vector<std::vector<State>> grid, int init[2], int goal[2])
// {
//     std::cout << "No path found for now_-_" << "\n";
//     return std::vector<std::vector<State>> {};
// }

//Update the search function ! ===============
// To Complete This Exercise:
// Complete all of the TODOs in the pseudocode below. These are also marked directly in the exercise code.

  // TODO: while open vector is non empty {
    // TODO: Sort the open list using `CellSort`, and get the current node.

    // TODO: Get the x and y values from the current node,
    // and set grid[x][y] to kPath.

    // TODO: Check if you've reached the goal. If so, return grid.


    // If we're not done, expand search to current node's neighbors. This step will be completed in a later quiz.
    // ExpandNeighbors

  //} // TODO: End while loop
std::vector<std::vector<State>> Search(std::vector<std::vector<State>> grid, int init[2], int goal[2])
{
	// Create the vector of open nodes.
	std::vector<std::vector<int>> open{};

	// Initialize the starting node.
	int x = init[0];
	int y = init[1];
	int g = 0;
	int h = Heuristic(x , y , goal[0] , goal[1]);
	AddToOpen(x , y , g , h , open, grid);

	while(open.size() > 0)
	{
		// Get the next node
     	CellSort(&open);
    	auto current = open.back();
    	open.pop_back();
    	x = current[0];
    	y = current[1];
    	grid[x][y] = State::kPath;

		// Check if we're done.
    	if (x == goal[0] && y == goal[1]) 
		{
      	return grid;
    	}

		// If we're not done, expand search to current node's neighbors.
    	// ExpandNeighbors()
	}

	// We've run out of new nodes to explore and haven't found a path.
  	std::cout << "No path found!" << "\n";
  	return std::vector<std::vector<State>>{};
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


/** 
 * Add a node to the open list and mark it as open. 
 */
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



/**
 * Compare the F values of two cells.
 */
// To Complete This Exercise:
// Write a function bool Compare that accepts two nodes of type vector<int> as arguments. It should return a boolean true if the f-value of the first argument is 
// greater than the f-value of the second, and it should return false otherwise. Recall that the f-value is the sum of the cost and heuristic: f = g + h.
bool Compare(const std::vector<int> a , const std::vector<int> b)
{
	int f1 = a[2] + a[3];
  	int f2 = b[2] + b[3];
  	return f1 > f2; 
}


/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(std::vector<std::vector<int>> *v) 
{
  	std::sort(v->begin(), v->end(), Compare);
}


// To Complete This Exercise:
// Write a function bool CheckValidCell that accepts two ints for the x and y coordinates and a reference to the grid. The function should do two things:
// 1. Check that the (x, y) coordinate pair is on the grid.
// Check that the grid at (x, y) is kEmpty (this is the default case if the grid cell is not kClosed or a kObstacle). If both of these conditions are true, then CheckValidCell should return true. Otherwise, it should return false.
bool CheckValidCell(int x , int y, std::vector<std::vector<State>>& grid)
{
	bool on_grid_x = (x >= 0 && x < grid.size());
  	bool on_grid_y = (y >= 0 && y < grid[0].size());
  	if (on_grid_x && on_grid_y)
    	return grid[x][y] == State::kEmpty;
  	return false;
}