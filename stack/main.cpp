#include <iostream>
#include "MyStack.h"
#include "MyStack.cpp"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	MyStack<int> a(10);
	a.Push(7);
	a.Push(10);
	a.Push(3);
	a.Push(6);
	a.Push(25);
	a.Push(90);
	a.Push(44);
	std::cout  << "Стек: "<<endl;
	while (!a.IsEmpty())
	{
		int tmp = a.Pop();
		std::cout << tmp << endl;

	}
	std::cout << "Размер стека: "<<a.GetSize()<<endl;
	std::cout << "Индекс верхнего элемента стека: " << a.GetTop();



	
}
