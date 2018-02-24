/*
@Author Chhoden Gurung
@Assignment HW4 - SortingEfficiency
@Date 02/23/18
*/

#include <iostream>
#include "SortFunction.h"

using namespace std;

// Driver program
int main(int argc, char* argv[]) {
	bool printSortedFile = false;

	if (argc < 2) {
		cout << "Missing arguments!!" << endl;
		return 1;
	}

	if (argc == 3) {
		printSortedFile = true;
	}

	SortFunction sf;
	if (printSortedFile) {
		sf.readFile(argv[2]);
	}
	else {
		cout << argv[1];
	}

	return 0;
}