#include <iostream>
using namespace std;

int main() {
	int n_rows = 8;
	int n_columns = 8;

	// the rows
	for (int i = 0; i < n_rows; i ++ ) {
		for (int j = 0; j < n_columns; j++) {
			cout << "|row" << i << "col" << j << "| ";
		}
		// ... and go to next line for next row:
		cout << endl;
	}
	return 0;
}
