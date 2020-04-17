#include <iostream>
#include <string>
using std::cout;
using std::string;


void DoubleString(string &reference) {
    // Concatentate the string with a space and itself.
    reference = reference + " " + reference;
}

int main() {
    string s = "Hello";
    cout << "The string s is: " << s << "\n";
    DoubleString(s);
    cout << "The string s is now: " << s << "\n";
}
