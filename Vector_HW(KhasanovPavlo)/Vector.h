#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Vector
{
private:
	T* arr;
	int size;
public:
	Vector() = delete;
	Vector(int size, T el);
	Vector(int size, T* arr);
	void changeSize(int size);
	int getSize();
	T& operator[](int index);
	Vector<T>& operator+(const Vector<T>& obj);
	Vector<T>& operator-(const Vector<T>& obj) = delete;
	Vector<T>& operator*(const int num);
	
	template<typename T>
	friend ostream& operator<<(ostream& out, Vector<T>& obj);
};

template<typename T>
inline Vector<T>::Vector(int size, T el)
{
	this->arr = new T[size];
	for (int i = 0; i < size; i++) {
		this->arr[i] = el;
	}
	this->size = size;
}

template<typename T>
inline Vector<T>::Vector(int size, T* arr)
{
	this->arr = new T[size];
	for (int i = 0; i < size; i++) {
		this->arr[i] = arr[i];
	}
	this->size = size;
}

template<typename T>
inline void Vector<T>::changeSize(int size)
{
	if (this->size > size) {
		this->size = size;
		T* tempArr = new T[size];
		for (int i = 0; i < size; i++) {
			tempArr[i] = arr[i];
		}
		delete[] arr;
		arr = tempArr;
	}
	else {
		T* tempArr = new T[size];
		T el = 0;
		for (int i = 0; i < size; i++) {
			if (i < this->size)
				tempArr[i] = arr[i];
			else
				tempArr[i] = el;
		}
		this->size = size;
		delete[] arr;
		arr = tempArr;
	}
}

template<typename T>
inline int Vector<T>::getSize()
{
	return this->size;
}

template<typename T>
inline T& Vector<T>::operator[](int index)
{
	if (index >= 0 && this->size > index)
		return this->arr[index];
}

template<typename T>
inline Vector<T>& Vector<T>::operator+(const Vector<T>& obj)
{
	T el = 0;
	Vector<T> tempVector(this->size + obj.size, el);
	for (int i = 0; i < this->size + obj.size; i++) {
		if (i < this->size)
			tempVector.arr[i] = this->arr[i];
		else
			tempVector.arr[i] = obj.arr[i - this->size];
	}
	return tempVector;
}

template<typename T>
inline Vector<T>& Vector<T>::operator*(const int num)
{
	T el = 0;
	Vector<T> tempVector(this->size * num, el);
	for (int i = 0; i < tempVector.size; i++) {
		tempVector.arr[i] = arr[i % this->size];
	}
	return tempVector;
}

template<typename T>
inline ostream& operator<<(ostream& out, Vector<T>& obj)
{
	for (int i = 0; i < obj.getSize(); i++) {
		out << obj[i] << " ";
	}
	return out;
}
