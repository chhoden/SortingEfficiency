/*
@Author Chhoden Gurung
@Assignment HW4 - SortingEfficiency
@Date 02/23/18
*/

#pragma once

#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include "ArrayList.h"

using namespace std;

class SortFunction
{
public:
	//Constructors
	SortFunction();
	SortFunction(const string filename, const bool printSortedFile);

	//Insertion sort
	template <class TYPE>
	void insertionSort(ArrayList<TYPE> &list);

	//Merge sort
	template <class TYPE>
	void mergeSort(ArrayList<TYPE> &list);

	//Quick sort
	template <class TYPE>
	void quickSort(ArrayList<TYPE> &list);

	//Helper functions
	void sort();
	void readFile();

private:
	string filename;
	bool printSortedFile;
	ArrayList<int> originalList;

	//Helper functions for sort functions
	template <class TYPE>
	void mergeSort(ArrayList<TYPE> &list, int first, int last);
	template <class TYPE>
	void merge(ArrayList<TYPE> &list, int first, int mid, int last);
	template <class TYPE>
	void quickSort(ArrayList<TYPE> &list, int low, int high);
	template <class TYPE>
	int partition(ArrayList<TYPE> &list, int lowI, int highI);
};

