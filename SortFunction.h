/*
@Author Chhoden Gurung
@Assignment HW4 - SortingEfficiency
@Date 02/23/18
*/

#pragma once

#include <iostream>
#include <fstream>
#include "ArrayList.h"

using namespace std;

class SortFunction
{
public:
	template <class TYPE>
	void selectionSort(ArrayList<TYPE> &list);
	template <class TYPE>
	void mergeSort(ArrayList<TYPE> &list);
	template <class TYPE>
	void quickSort(ArrayList<TYPE> &list);
	void readFile(const string filename);
	void test();

private:
	template <class TYPE>
	void mergeSort(ArrayList<TYPE> &list, int first, int last);
	template <class TYPE>
	void merge(ArrayList<TYPE> &list, int first, int mid, int last);
	template <class TYPE>
	void quickSort(ArrayList<TYPE> &list, int low, int high);
	template <class TYPE>
	int partition(ArrayList<TYPE> &list, int lowI, int highI);
};

