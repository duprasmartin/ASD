#include<iostream>
using namespace std;

//function that works with value
int square_by_val(int a) {
  return a*a;
}

void square_by_addr(int * a) {
    int temp = *a;
    *a = temp*temp;
    return;
}


int main() {

  int myvalue = 3;

  // invoke by value

  for (int i = 0; i < 3; i ++) {
    cout << "Output by value is " << square_by_val(myvalue) << endl;
  }

  cout << "\n\n\n"; // like three endl

  // invoke by address

  for (int i = 0; i < 3; i ++) {
    square_by_addr(&myvalue);
    cout << "Output by address is " << myvalue << endl;
  }
}
