
void TestSearch() {
  std::cout << "----------------------------------------------------------" << "\n";
  std::cout << "Search Function Test (Partial): ";
  int goal[2]{4, 5};
  auto board = ReadBoardFile("1.board");
  
  std::cout.setstate(std::ios_base::failbit); // Disable std::cout
  auto output = Search(board, goal, goal);
  std::cout.clear(); // Enable std::cout

  std::vector<std::vector<State>> solution{{State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty, State::kObstacle, State::kPath}};

  if (output != solution) {
    std::cout << "failed" << "\n";
    std::cout << "Search(board, {4,5}, {4,5})" << "\n";
    std::cout << "Solution board: " << "\n";
    PrintVectorOfVectors(solution);
    std::cout << "Your board: " << "\n";
    PrintVectorOfVectors(output);
    std::cout << "\n";
  } else {
    std::cout << "passed" << "\n";
  }
  std::cout << "----------------------------------------------------------" << "\n";
}