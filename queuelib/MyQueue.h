
#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyQueue
{
protected:
	int size;
	int start;
	int end;
	int count;
	T* pMem;

public:
	MyQueue(int n = 0);
	MyQueue(MyQueue <T>& q);
	~MyQueue();

	void Push(T a)
	{
		if (!IsFull()) {
			pMem[end] = a;
			end = (end + 1) % size;
			count++;
		}
	}
	T Pop()
	{
		if (!IsEmpty()) {
			T temp = pMem[start];
			start = (start + 1) % size;
			count--;
			return temp;
		}
		return T();
	}

	bool IsFull() { return count == size; }
	bool IsEmpty() { return count == 0; }

	//операторы вводы и выводы
	friend std::ostream& operator<< (std::ostream& ostr, const MyQueue<T>& A) {
		for (int i = 0; i < A.count; i++) {
			ostr << A.pMem[i] << " ";
		}
		return ostr;
	}
	friend std::istream& operator>> (std::istream& istr, MyQueue<T>& A) {
		for (int i = 0; i < A.size; i++) {
			istr >> A.pMem[i];
			A.count++;
		}
		return istr;
	}
};

template <class T>
MyQueue<T> ::MyQueue(int n)// заполение стека
{
	if (n < 0)
	{
		throw "Error";
	}
	this->size = n;
	this->start = 0;
	this->end = 0;
	this->count = 0;
	this->pMem = new T[n]();
}

template <class T>
MyQueue<T> ::MyQueue(MyQueue<T>& q)
{
	size = q.size;
	start = q.start;
	end = q.end;
	cout = q.count;
	pMem = new T[size];
	for (int i = 0; i < size; ++i) {
		pMem[i] = q.pMem[i];
	}

}

template <class T>
MyQueue<T> ::~MyQueue()
{
	delete[]pMem;
}








