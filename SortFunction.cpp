/*
@Author Chhoden Gurung
@Assignment HW4 - SortingEfficiency
@Date 02/23/18
*/

#include "SortFunction.h"

using namespace std;

template<class TYPE>
void SortFunction::selectionSort(ArrayList<TYPE> &list)
{
	int minIndex;
	for (int i = 0; i < list.getSize() - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < list.getSize(); j++) {
			if (list[j] < list[minIndex]) {
				minIndex = j;
			}
		}
		list.swap(minIndex, i);
	}
}

template<class TYPE>
void SortFunction::quickSort(ArrayList<TYPE> &list)
{
	quickSort(list, 0, list.getSize() - 1);
}

template<class TYPE>
void SortFunction::quickSort(ArrayList<TYPE> &list, int low, int high)
{
	if (low < high) {
		int part = partition(list, low, high);
		quickSort(list, low, part - 1);
		quickSort(list, part + 1, high);
	}
}

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

template<class TYPE>
void SortFunction::mergeSort(ArrayList<TYPE> &list)
{
	mergeSort(list, 0, list.getSize() - 1);
}

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

	left.print();
	right.print();

	i = j = 0;
	k = first;

	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			list.set(k, left[i]);
			i++;
		}
		else {
			list.set(k, right[j]);
			j++;
		}
	}

	while (i < n1) {
		list.set(k, left[i]);
		i++;
		k++;
	}

	while (j < n2) {
		list.set(k, right[j]);
		j++;
		k++;
	}
}

void SortFunction::readFile(const string fileName) throw (logic_error)
{
	//test();
	int num;
	ifstream myFile(fileName);

	ArrayList<int> list1;

	while (myFile >> num)
	{
		list1.append(num);
	}

	ArrayList<int> list2(list1);
	ArrayList<int> list3(list1);

	list1.print();
	selectionSort(list1);
	list1.print();

	list2.print();
	quickSort(list2);
	list2.print();

	list3.print();
	mergeSort(list3);
	list3.print();
}

void SortFunction::test()
{
	ArrayList<int> list;
	list.append(38);
	list.append(27);
	list.append(43);
	list.append(3);
	list.append(9);
	list.append(82);
	list.append(10);

	list.print();
	selectionSort(list);
	quickSort(list);
	//mergeSort(list);
	list.print();
}