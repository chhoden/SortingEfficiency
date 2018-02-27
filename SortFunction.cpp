/*
@Author Chhoden Gurung
@Assignment HW4 - SortingEfficiency
@Date 02/23/18
*/

#include "SortFunction.h"

using namespace std;

//Default constructor
SortFunction::SortFunction()
{
	filename = "";
	printSortedFile = false;
}

// Constructor 
SortFunction::SortFunction(const string fn, const bool printsf)
{
	filename = fn;
	printSortedFile = printsf;
	readFile();
}

//Insertion sort
template<class TYPE>
void SortFunction::insertionSort(ArrayList<TYPE> &list)
{
	int i, j, tmp;
	for (i = 1; i < list.getSize(); i++) {
		j = i;
		while (j > 0 && list[j - 1] > list[j]) {
			list.swap(j - 1, j);
			j--;
		}
	}
}

//Quick sort
template<class TYPE>
void SortFunction::quickSort(ArrayList<TYPE> &list)
{
	quickSort(list, 0, list.getSize() - 1);
}

//Quick sort helper function
template<class TYPE>
void SortFunction::quickSort(ArrayList<TYPE> &list, int low, int high)
{
	if (low < high) {
		int part = partition(list, low, high);
		quickSort(list, low, part - 1);
		quickSort(list, part + 1, high);
	}
}

//Helper function for quick sort to partition an array
template<class TYPE>
int SortFunction::partition(ArrayList<TYPE> &list, int low, int high) {
	int pivot = list[high];
	int idx = (low - 1);

	for (int pos = low; pos <= high - 1; pos++) {
		if (list[pos] <= pivot) {
			idx++;
			list.swap(idx, pos);
		}
	}

	list.swap(idx + 1, high);
	return (idx + 1);
}

//Merge sort
template<class TYPE>
void SortFunction::mergeSort(ArrayList<TYPE> &list)
{
	mergeSort(list, 0, list.getSize() - 1);
}

//Helper function that recursively breaks bigger unsorted array into tiny array
template<class TYPE>
void SortFunction::mergeSort(ArrayList<TYPE> &list, int first, int last)
{
	if (first < last)
	{
		int mid = first + (last - first) / 2;

		mergeSort(list, first, mid);
		mergeSort(list, mid + 1, last);

		merge(list, first, mid, last);
	}
}

//A helper function to sort and merge each tiny array into the original big array
template<class TYPE>
void SortFunction::merge(ArrayList<TYPE> &list, int first, int mid, int last)
{
	int i, j, k;
	int n1 = mid - first + 1;
	int n2 = last - mid;

	ArrayList<TYPE> left(n1), right(n2);

	for (i = 0; i < n1; i++) {
		left.append(list[first + i]);
	}

	for (j = 0; j < n2; j++) {
		right.append(list[mid + 1 + j]);
	}

	i = j = 0;
	k = first;

	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			list.removeAt(k);
			list.insertAt(k, left[i]);
			i++;
		}
		else {
			list.removeAt(k);
			list.insertAt(k, right[j]);
			j++;
		}
		k++;
	}

	while (i < n1) {
		list.removeAt(k);
		list.insertAt(k, left[i]);
		i++;
		k++;
	}

	while (j < n2) {
		list.removeAt(k);
		list.insertAt(k, right[j]);
		j++;
		k++;
	}
}

// A function to sort the array using Insertion, Quick and Merge sorts and prints the statistics.
void SortFunction::sort()
{
	char line[350];
	cout << "Filename: " << filename << endl;
	cout << "Number of items: " << originalList.getSize() << endl << endl;

	int j = 0;;
	j = sprintf_s(line + j, 350 - j, "Number of: %14s %10s %10s %10s %10s\n", "Access", "Swap", "Remove", "InsertAt", "Append");

	originalList.clearStatistics();
	ArrayList<int> insertionList(originalList);
	insertionSort(insertionList);
	j += sprintf_s(
		line + j,
		350 - j,
		"InsertionSort: %10d %10d %10d %10d %10d\n",
		insertionList.getNumAccess(),
		insertionList.getNumSwap(),
		insertionList.getNumRemove(),
		insertionList.getNumInsertAt(),
		insertionList.getNumAppends()
	);

	originalList.clearStatistics();
	ArrayList<int> quickList(originalList);
	quickSort(quickList);
	j += sprintf_s(
		line + j,
		350 - j,
		"QuickSort: %14d %10d %10d %10d %10d\n",
		quickList.getNumAccess(),
		quickList.getNumSwap(),
		quickList.getNumRemove(),
		quickList.getNumInsertAt(),
		quickList.getNumAppends()
	);

	originalList.clearStatistics();
	ArrayList<int> mergeList(originalList);
	mergeSort(mergeList);
	j += sprintf_s(
		line + j,
		350 - j,
		"MergeSort: %14d %10d %10d %10d %10d\n",
		mergeList.getNumAccess(),
		mergeList.getNumSwap(),
		mergeList.getNumRemove(),
		mergeList.getNumInsertAt(),
		mergeList.getNumAppends()
	);

	if (printSortedFile) {
		cout << "Original List:" << endl;
		originalList.print();

		cout << "Insertion Sort Results:" << endl;
		insertionList.print();

		cout << "Quick Sort Results:" << endl;
		quickList.print();

		cout << "Merge Sort Results:" << endl;
		mergeList.print();

		cout << endl << endl;
	}

	printf_s(line, j);
}

//A function to read a file line by line and then store it into an arrayList
void SortFunction::readFile() throw (logic_error)
{
	int num;
	ifstream myFile(filename);

	while (myFile >> num)
	{
		originalList.append(num);
	}
}