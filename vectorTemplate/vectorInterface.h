#pragma once

template<typename T>
class VectorInterface
{

public:

	VectorInterface(void) {};
	virtual ~VectorInterface(void) {};

	virtual void push_back(T value) = 0;
	
	/* Insert value after given index */
	virtual void insertAt(int index, T value) = 0;

	/* Remove the element at index */
	virtual void remove(int index) = 0;
	
	virtual T at(int index) = 0;

	virtual int size() = 0;
};


//#include "VectorInterface.h"
template <class T>
class MyVector: public VectorInterface<T>
{
protected:
	T *array; 
	int current_capacity; 
	int num_items;
public:

	MyVector(void) {cout << "In constructor"<<endl;};
	~MyVector(void) {cout << "In destructor"<<endl;};

	void push_back(T value){cout << "In push_back"<<endl;};
	
	/* Insert value after given index */
	void insertAt(int index, T value){cout << "In insertAt"<<endl;};

	/* Remove the element at index */
	void remove(int index) {cout << "In remove"<<endl;};
	
	T at(int index){cout << "In at"<<endl;};

	int size(){cout << "In size"<<endl; return(0);};
};