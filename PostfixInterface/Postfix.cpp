#pragma once
#include "Postfix.h"

string MyPostf::GetInfix()
{
	return infix;
}

MyPostf::MyPostf(string infix)
{
	this->infix = infix;
	postfix = " ";
	opstack = MyStack<char>(infix.length());
	dstack = MyStack<double>(infix.length());
	res = 0;
	ToPostfix();
}

string MyPostf::GetPostfix()
{
	return postfix;
}

//map<char, int>MyPostf::priority = {//Раставление приорететов
//	{'(', 0 },
//	{')', 0 },
//	{'+', 1},
//	{ '-', 1 },
//	{ '*', 2 },
//	{ '/', 2 },
//};
int Priority(char ch) {
	switch (ch)
	{
	case '(':
	case ')':
		return 1;

	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	default: break;
	}
}

void MyPostf::ToPostfix()
{
	char el = '!';
	postfix = "";
	string s = "(" + infix + ")";
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] <= '9' && s[i] >= '0') postfix += s[i];
		if (s[i] == '/' || s[i] == '*' || s[i] == '+' || s[i] == '-') {
			postfix += " ";
			el = opstack.Pop();
			while (Priority(s[i]) <= Priority(el)) {
				postfix += el;
				postfix += " ";
				el = opstack.Pop();
			}
			opstack.Push(el);
			opstack.Push(s[i]);
		}
		if (s[i] == '(') opstack.Push(s[i]);
		if (s[i] == ')') {
			el = opstack.Pop();

			while (el != '(') {
				postfix += el;
				el = opstack.Pop();
			}
		}
	}
	/*Parse();
	MyStack<char> st(200);
	char stackItem;
	for (char item : lexems) {
		switch (item) {
		case '(':
			st.Push(item);
			break;
		case ')':
			stackItem = st.Pop();
			while (stackItem != '(') {
				postfix += stackItem;
				stackItem = st.Pop();
			}
			break;
		case '+': case '-': case '*': case '/':
			while (!st.IsEmpty()) {
				stackItem = st.Pop();
				if (priority[item] <= priority[stackItem])
					postfix += stackItem;
				else {
					st.Push(stackItem);
					break;
				}
			}
			st.Push(item);
			break;
		default:
			operands.insert({ item, 0.0 });
			postfix += item;
		}*/
}
	//while (!st.IsEmpty()) {
	//	stackItem = st.Pop();
	//	postfix += stackItem;
	//}

//vector<char> MyPostf::GetOperands()
//{
//	vector<char> op;
//	for (const auto& item : operands)
//		op.push_back(item.first);
//	return op;


void MyPostf::Calculate(/*const map<char, double>& values*/)
{
	/*for (auto& val : values)
	{
		try
		{
			operands.at(val.first) = val.second;
		}
		catch (out_of_range& e) {}
	}
	MyStack<double> st(200);
	double leftOperand, rightOperand;
	for (char lexem : postfix)
	{
		switch (lexem)
		{
		case '+':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand + rightOperand);
			break;
		case '-':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand - rightOperand);
			break;
		case '*':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand * rightOperand);
			break;
		case '/':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand / rightOperand);
			break;
		default:
			st.Push(operands[lexem]);
		}
	}
	return st.Pop();*/
	for (size_t i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
			double d1, d2;
			switch (postfix[i]) {
			case '+':
				d1 = dstack.Pop();
				d2 = dstack.Pop();
				dstack.Push(d1 + d2);
				break;
			case '-':
				d2 = dstack.Pop();
				d1 = dstack.Pop();
				dstack.Push(d1 - d2);
				break;
			case '*':
				d1 = dstack.Pop();
				d2 = dstack.Pop();
				dstack.Push(d1 * d2);
				break;
			case '/':
				d1 = dstack.Pop();
				d2 = dstack.Pop();
				dstack.Push(d1 / d2);
				break;
			default: break;
			}
			if (postfix[i] <= '9' && postfix[i] >= '0') {
				size_t count;
				double t = std::stod(&postfix[i], &count);
				dstack.Push(t);
				i += count - 1;
			}
		}
		res = dstack.TopView();
	}
}