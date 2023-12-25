#include "Stack.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

class MyPostf
{
protected:
	string infix;
	string postfix;
	MyStack<char> opstack;
	MyStack<double> dstack;
	double res = 0;
	//vector<char> lexems;
	//static map<char, int> priority;
	//map<char, double> operands;

	void Parse();

public:
	void ToPostfix();
	double GetResult() { return res; }
	MyPostf(std::string infix);
	string GetInfix();//Метод, который возвращает входную инфиксную форму
	string GetPostfix();//Метод, который возвращает результирующую постфиксную форму
	//vector<char> GetOperands();
	void Calculate(/*const map<char, double>& values*/);
};