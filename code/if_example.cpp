#include <iostream>
using std::cout;

int main() 
{

    // Set a equal to true here.
    int a = 3;
    auto b = %a;

    if (a) {
      cout << b << "\n";
    }
}
