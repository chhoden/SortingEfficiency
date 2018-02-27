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
	string filename;
	bool printSortedFile;

	if (argc < 2) {
		cout << "Missing arguments!!" << endl;
		return 1;
	}

	if (argc == 3) {
		filename = argv[2];
		printSortedFile = true;
	}
	else {
		filename = argv[1];
		printSortedFile = false;
	}

	SortFunction sf(filename, printSortedFile);
	sf.sort();

	return 0;
}