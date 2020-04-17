#include <iostream>
using std::cout;

int main() 
{
    auto i = 0;

    while (i <= 10) {
      if (int i % 2 != 0)
      {
          cout << i << "\n";
      }
      i++;
    }
}
