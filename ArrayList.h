#pragma once
#include "ListInterface.h"

template <class TYPE>
class ArrayList: public ListInterface<TYPE>
{
public:
	ArrayList();
	/*
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

	////void swap(int from, int to) throw(std::out_of_range);

	////// Get an item at location
	////TYPE & getAt(int index) const throw (std::out_of_range);

	////// Clear everything
	////void clearAll();

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
	TYPE arr[10];
	int size;
	int capacity;
};
#include "ArrayList.cpp"