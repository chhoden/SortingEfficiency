#include "ArrayList.h"

template <class TYPE>
ArrayList<TYPE>::ArrayList()
{
	ListInterface<TYPE>();
	size = 0;
	capacity = 10;
}
/*
template <class TYPE>
ArrayList<TYPE>::~ArrayList()
{

}

template<class TYPE>
bool ArrayList<TYPE>::isEmpty() const
{
	if (size == 0) {
		return true;
	}
	return false;
}

template<class TYPE>
int ArrayList<TYPE>::getSize() const
{
	return size;
}

template<class TYPE>
void ArrayList<TYPE>::insertAt(int index, const TYPE & newEntry) throw(std::out_of_range)
{
	if(index < 0 || index >= capacity){
		throw out_of_range("Index out of bound");
	}
}

template<class TYPE>
void ArrayList<TYPE>::removeAt(int index) throw(std::out_of_range)
{
	if (size == 0 || index < 0 || index >= capacity ) {
		throw out_of_range("Index out of bound"); l
	}

	delete arr[index];
	for (int i = index; i < size; i++) {
		int temp = arr[i+1];
		arr[i] = temp;
	}
}

template<class TYPE>
void ArrayList<TYPE>::append(const TYPE &obj)
{
	if (size == capacity) {
		TYPE biggerArr[capacity*2];
		for (int i = 0; i < capacity; i++) {
			biggerArr[i] = arr[i];
		}
	}
	arr = biggerArr;
	arr[capacity] = obj;
}

*/

