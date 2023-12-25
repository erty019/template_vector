#pragma once
#pragma once
#include <iostream>
#include <math.h>
using namespace std;

template<typename T>
class MyStack
{
protected:
	T* pMem;
	int size;//������� ������ �����
	int top;//������� �����
public:
	MyStack(int n = 0);
	MyStack(const MyStack<T>& stack);
	~MyStack();

	MyStack<T>& operator=(const MyStack<T>& st);
	friend std::ostream& operator<< (std::ostream& ostr, const MyStack<T>& A);
	friend std::istream& operator>> (std::istream& istr, MyStack<T>& A);

	void Push(T el) {//���������� �������� �� ������� �����
		if (IsFull()) {
			throw - 1;
		}
		pMem[top] = el;
		top++;
	}
	T Pop() {// ���������� �������� �� ������� �����
		if (IsEmpty()) {
			throw "Error";
		}
		return pMem[--top];
	}
	T TopView();// ����������� �������� ��������

	int GetSize();//���������� ������� ������ �����
	int GetTop();// ���������� ������ �������� �������� �����

	bool IsFull();//��������� ���� �� ������� 
	bool IsEmpty();//��������� ���� �� �������  
};

template <class T>
MyStack<T> ::MyStack(int n)// ��������� �����
{
	if (n < 0)
	{
		throw "Error";
	}
	size = n;
	top = 0;
	pMem = new T[n];
}

template <class T>
MyStack<T> ::MyStack(const MyStack<T>& stack)
{
	size = stack.size;
	top = stack.top;
	pMem = new T[size];
	std::copy(stack.pMem, stack.pMem + top, pMem);

}

template <class T>
MyStack<T> ::~MyStack()
{
	delete[]pMem;
}

template <class T>
MyStack<T>& MyStack<T>:: operator=(const MyStack<T>& st)
{
	if (this == &st)
	{
		return *this;
	}
	delete[] pMem;
	size = st.size;
	top = st.top;
	pMem = new T[size];
	std::copy(st.pMem, st.pMem + top, pMem);
	return *this;
}

template <class T>
ostream& operator<< (ostream& ostr, const MyStack<T>& A)
{
	for (int i = 0; i < A.top;i++)
	{
		ostr << A.pMem[i] << "\n" << endl;

	}
	return ostr;
}

template <class T>
istream& operator>> (istream& istr, MyStack<T>& A)
{

	for (int i = 0; i < A.size;i++)
	{
		istr >> A.pMem[i];

	}
	return istr;
}

template <class T>
T MyStack<T> ::TopView()
{
	return pMem[top];
}

template <class T>
int MyStack<T> ::GetSize()
{
	return size;
}
template <class T>
int MyStack<T> ::GetTop()
{
	return top;
}

template <class T>
bool MyStack<T> ::IsFull()
{
	return top == size;
}
template <class T>
bool MyStack<T> ::IsEmpty()
{
	return top == 0;
}