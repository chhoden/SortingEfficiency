#pragma once
#include "ListInterface.h"

template <class TYPE>
class ArrayList : public ListInterface<TYPE>
{
public:
	ArrayList();
	~ArrayList();

	//TYPE & operator[](int) const  throw (std::out_of_range);

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
	
	//Clear everything
	void clearAll();
/*
	////// Clear out any instrumentation
	////void clearStatistics();

	////// Provide statistics on number of times method was performed
	////int getNumAccess() const;    // operator [] OR getAt
	////int getNumSwap() const;
	////int getNumRemove() const;
	////int getNumInsertAt() const;
	////int getNumAppends() const;
	*/
private:
	static const int DEFAULT_CAPACITY = 10;\
	TYPE* arr;
	int size;
	int capacity;
};

template<class TYPE>
inline ArrayList<TYPE>::ArrayList()
{
	arr = new TYPE[DEFAULT_CAPACITY];
	size = 0;
	capacity = DEFAULT_CAPACITY;
}

template<class TYPE>
inline ArrayList<TYPE>::~ArrayList()
{
	size = 0;
	capacity = 0;
	delete[] arr;
}

template<class TYPE>
inline bool ArrayList<TYPE>::isEmpty() const
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

template<class TYPE>
inline int ArrayList<TYPE>::getSize() const
{
	return size;
}

template<class TYPE>
inline void ArrayList<TYPE>::insertAt(int index, const TYPE & newEntry) throw(std::out_of_range)
{
	if (index < 0 || index >= capacity)
	{
		throw std::out_of_range("Index out of bound");
	}
	for (int i = 0; i < capacity; i++)
	{

	}
	size++;
}

template<class TYPE>
inline void ArrayList<TYPE>::removeAt(int index) throw(std::out_of_range)
{
	if (size == 0 || index < 0 || index >= capacity)
	{
		throw std::out_of_range("Index out of bound");
	}

	for (int i = index; i < size; i++) {
		int temp = arr[i + 1];
		arr[i] = temp;
	}
	size--;
}

template<class TYPE>
inline void ArrayList<TYPE>::append(const TYPE & newEntry)
{
	if (size == capacity)
	{
		int* biggerArr = new int[capacity * 2];
		capacity *= 2;
		for (int i = 0; i < size; i++) {
			biggerArr[i] = arr[i];
		}
		arr = biggerArr;
		biggerArr[size] = newEntry;
		size++;
	}
	arr[size] = newEntry;
	size++;
}

template<class TYPE>
inline void ArrayList<TYPE>::swap(int from, int to) throw(std::out_of_range)
{
	if (from < 0 || from >= capacity || to < 0 || to >= capacity)
	{
		throw std::out_of_range("Index out of bound");
	}
	TYPE temp = arr[from];
	arr[from] = arr[to];
	arr[to] = temp;
}

template<class TYPE>
inline TYPE & ArrayList<TYPE>::getAt(int index) const throw(std::out_of_range)
{
	if (index < 0 || index >= capacity) {
		throw std::out_of_range("Index out of bound");
	}
	return arr[index];
}

