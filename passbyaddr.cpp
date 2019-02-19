#include<iostream>
using namespace std;


void addone(int * a) {
    *a = *a+1;
    return;
}


int main() {

  int myvalue = 3;

  cout << "\n\n";
  cout << "myvalue is " << myvalue << endl;

  // add one:
  addone(&myvalue);

  cout << "myvalue is " << myvalue << endl;
}
