#include <iostream>   // this is the library that containc console input and output (e.g. "cout")
using namespace std;  // this prevents having to write "std::cout" every time

int main()
{
    int value1 = 12;
    int value2 = 23;
    cout << "The sum of ";
    cout << value1;
    cout << " and ";
    cout <<value2;
    cout << " is ";
    cout << value1+value2;
    return 0;                 // when done, exit and return the value 0, which usually means that no error happened.
}
