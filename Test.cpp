#include <iostream>
#include "ArrayList.h"

using namespace std;
int main() {
	ArrayList<int> list;
	cout << "isEmpty: " << list.isEmpty() << endl;

	list.insertAt(0,1);
	list.insertAt(1,2);
	cout << "isEmpty: " << list.isEmpty() << endl;

	system("pause");
	return 0;
}