#ifndef DECLARE
#define DECLARE


enum class State {kEmpty, kObstacle, kClosed, kPath};


// Function Decleration
std::vector<State> ParseLine(std::string line) ;
std::vector<std::vector<State>> ReadBoardFile(std::string path);
void PrintBoard(const std::vector<std::vector<State>> board);
std::string CellString(State cell);

//Part two - Search
std::vector<std::vector<State>> Search(std::vector<std::vector<State>> grid, int init[2], int goal[2]);
int Heuristic(int x1, int y1, int x2, int y2);
void AddToOpen(int x , int y , int g , int h, std::vector<std::vector<int>>& openlist, std::vector<std::vector<State>>& grid);
bool Compare(const std::vector<int> a , const std::vector<int> b);
void CellSort(std::vector<std::vector<int>> *v);
bool CheckValidCell(int x , int y, std::vector<std::vector<State>>& grid);



#endif