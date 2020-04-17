

void TestExpandNeighbors() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "ExpandNeighbors Function Test: ";
  vector<int> current{4, 2, 7, 3};
  int goal[2] {4, 5};
  vector<vector<int>> open{{4, 2, 7, 3}};
  vector<vector<int>> solution_open = open;
  solution_open.push_back(vector<int>{3, 2, 8, 4});
  solution_open.push_back(vector<int>{4, 3, 8, 2});
  vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kClosed, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};
  vector<vector<State>> solution_grid = grid;
  solution_grid[3][2] = State::kClosed;
  solution_grid[4][3] = State::kClosed;
  ExpandNeighbors(current, goal, open, grid);
  CellSort(&open);
  CellSort(&solution_open);
  if (open != solution_open) {
    cout << "failed" << "\n";
    cout << "\n";
    cout << "Your open list is: " << "\n";
    PrintVectorOfVectors(open);
    cout << "Solution open list is: " << "\n";
    PrintVectorOfVectors(solution_open);
    cout << "\n";
  } else if (grid != solution_grid) {
    cout << "failed" << "\n";
    cout << "\n";
    cout << "Your grid is: " << "\n";
    PrintVectorOfVectors(grid);
    cout << "\n";
    cout << "Solution grid is: " << "\n";
    PrintVectorOfVectors(solution_grid);
    cout << "\n";
  } else {
  	cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
  return;
}