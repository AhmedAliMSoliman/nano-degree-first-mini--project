#include <iostream>
using std::cout;



void InnerFunction(int i) 
{
    cout << "The value of the integer is: " << i << "\n";
}

void OuterFunction(int i) 
{
    InnerFunction(i);
}

int main() 
{
    int a = 5;
    OuterFunction(a);
}
