/*
@Author Chhoden Gurung
@Assignment HW4 - SortingEfficiency
@Date 02/23/18
*/

#pragma once
#include "ListInterface.h"

template <class TYPE>
class ArrayList : public ListInterface<TYPE>
{
public:
	// Constructors 
	ArrayList();
	ArrayList(int capacity);
	ArrayList(const ArrayList<TYPE> &source);

	//Destructor
	~ArrayList();

	// The easy way to access an element
	TYPE & operator[](int) const  throw (std::out_of_range);

	// Tell of it is empty
	bool isEmpty() const;

	// Return the number of elements in the list
	int getSize() const;

	// Inserts at the location.
	void insertAt(int index, const TYPE & newEntry) throw (std::out_of_range);

	// delete at location
	void removeAt(int index) throw (std::out_of_range);

	// Append to end
	void append(const TYPE &);

	void swap(int from, int to) throw(std::out_of_range);

	// Get an item at location
	TYPE & getAt(int index) const throw (std::out_of_range);

	// Print all the elements in arrayList
	void print();

	//Clear everything
	void clearAll();
	// Clear out any instrumentation
	void clearStatistics();

	// Provide statistics on number of times method was performed
	int getNumAccess() const;    // operator [] OR getAt
	int getNumSwap() const;
	int getNumRemove() const;
	int getNumInsertAt() const;
	int getNumAppends() const;

private:
	static const int DEFAULT_CAPACITY = 2;

	static int numAccess;
	static int numSwap;
	static int numRemove;
	static int numInsert;
	static int numAppend;

	TYPE* arr;
	int size;
	int capacity;

	void growArr();
};

template<class TYPE>
int ArrayList<TYPE>::numAccess = 0;
template<class TYPE>
int ArrayList<TYPE>::numSwap = 0;
template<class TYPE>
int ArrayList<TYPE>::numRemove = 0;
template<class TYPE>
int ArrayList<TYPE>::numInsert = 0;
template<class TYPE>
int ArrayList<TYPE>::numAppend = 0;

template<class TYPE>
inline ArrayList<TYPE>::ArrayList()
{
	arr = new TYPE[DEFAULT_CAPACITY];
	size = 0;
	capacity = DEFAULT_CAPACITY;
}

template<class TYPE>
inline ArrayList<TYPE>::ArrayList(int cap)
{
	arr = new TYPE[cap];
	size = 0;
	capacity = cap;
}

template<class TYPE>
inline ArrayList<TYPE>::ArrayList(const ArrayList<TYPE> &source)
{
	size = source.getSize();
	arr = new TYPE[size];
	capacity = size;

	for (int i = 0; i < size; i++) {
		arr[i] = source[i];
		numAppend++;
	}
}

template<class TYPE>
inline ArrayList<TYPE>::~ArrayList()
{
	while (size != 0) {
		removeAt(0);
	}
}

template<class TYPE>
inline TYPE & ArrayList<TYPE>::operator[](int index) const throw(std::out_of_range)
{
	return getAt(index);
}

template<class TYPE>
inline bool ArrayList<TYPE>::isEmpty() const
{
	return size == 0;
}

template<class TYPE>
inline int ArrayList<TYPE>::getSize() const
{
	return size;
}

template<class TYPE>
inline void ArrayList<TYPE>::insertAt(int index, const TYPE & newEntry) throw(std::out_of_range)
{
	if (index < 0 || index > size)
	{
		throw std::out_of_range("Index out of bound");
	}

	growArr();

	for (int i = size; i > index; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[index] = newEntry;
	size++;
	numInsert++;
}

template<class TYPE>
inline void ArrayList<TYPE>::removeAt(int index) throw(std::out_of_range)
{
	if (size == 0 || index < 0 || index >= capacity)
	{
		throw std::out_of_range("Index out of bound");
	}

	for (int i = index; i < size; i++) {
		TYPE temp = arr[i + 1];
		arr[i] = temp;
	}
	size--;
	numRemove++;
}

template<class TYPE>
inline void ArrayList<TYPE>::append(const TYPE & newEntry)
{
	growArr();
	arr[size] = newEntry;
	size++;
	numAppend++;
}

template<class TYPE>
inline void ArrayList<TYPE>::swap(int from, int to) throw(std::out_of_range)
{
	if (from < 0 || from >= size || to < 0 || to >= size)
	{
		throw std::out_of_range("Index out of bound");
	}
	TYPE temp = arr[from];
	arr[from] = arr[to];
	arr[to] = temp;
	numSwap++;
}

template<class TYPE>
inline TYPE & ArrayList<TYPE>::getAt(int index) const throw(std::out_of_range)
{
	if (index < 0 || index >= size) {
		throw std::out_of_range("Index out of bound");
	}
	numAccess++;
	return arr[index];
}

template<class TYPE>
inline void ArrayList<TYPE>::print()
{
	for (int i = 0; i < size; i++) {
		cout << getAt(i) << " ";
	}
	cout << endl;
}

template<class TYPE>
inline void ArrayList<TYPE>::clearAll()
{
	size = 0;
	capacity = 0;
	delete[] arr;
}

template<class TYPE>
inline void ArrayList<TYPE>::clearStatistics()
{
	numAccess = 0;
	numSwap = 0;
	numRemove = 0;
	numInsert = 0;
	numAppend = 0;
}

template<class TYPE>
inline int ArrayList<TYPE>::getNumAccess() const
{
	return numAccess;
}

template<class TYPE>
inline int ArrayList<TYPE>::getNumSwap() const
{
	return numSwap;
}

template<class TYPE>
inline int ArrayList<TYPE>::getNumRemove() const
{
	return numRemove;
}

template<class TYPE>
inline int ArrayList<TYPE>::getNumInsertAt() const
{
	return numInsert;
}

template<class TYPE>
inline int ArrayList<TYPE>::getNumAppends() const
{
	return numAppend;
}

template<class TYPE>
inline void ArrayList<TYPE>::growArr()
{
	if (size == capacity) {
		TYPE* biggerArr = new TYPE[capacity*2];
		for (int i = 0; i < size; i++) {
			biggerArr[i] = arr[i];
		}
		arr = biggerArr;
		capacity *= 2;
	}
}

