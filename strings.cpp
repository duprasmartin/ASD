//
//  main.cpp
//  strings
//
//  Created by Martin Dupras on 15/02/2019.
//  Copyright © 2019 Martin Dupras. All rights reserved.
//

#include <iostream>
#include <string> // that's the library that contains the string thingies
using namespace std;

int main(int argc, const char * argv[]) {
    string mystring("zeppelinisawesome");

    cout << "Here's what string mystring contains: " << endl;
    cout << mystring << endl;
    cout << "\n\n\n"; // that's like three endl in a row
    
    cout << "The length of string mystring is: " << endl;
    cout << mystring.length(); // this is invoking the length function that is a member of class "string". We'll see about that in week 3.
    cout << "\n\n\n";
    
    // here's another way to make a string, C-style:
    char anotherstring[12] = "abcdefghijk";
    cout << "String anotherstring contains: " << endl;
    cout << anotherstring << endl;
    
    // but see how this doesn't work... Uncomment to see it break:
/*
    cout << "The length of the string anotherstring is: " << endl;
    cout << anotherstring.length(); // that's because the C-style string is just an array of characters, whereas the previous string was a C++ style string, which is done using the "string" class, which contains a bunch of useful things, like the length() member function.
    cout << "\n\n\n";
*/
    // Now let's do some stuff to that string...
    
    // add a bit at the end:
    mystring.insert(0, "led"); // insert a bit at character 0
    
    cout << "Here's what string mystring contains: " << endl;
    cout << mystring << endl;
    cout << "\n\n\n"; // that's like three endl in a row
    
    // Check this out; we will delete one character at a time until we are left with none
    
    while(mystring.length() > 0) {
        cout << mystring <<endl;
        mystring.pop_back();
    }
    
    
    
    
    
    return 0;
}
