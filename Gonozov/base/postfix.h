#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;


class TPostfix
{
	string infix;
	string postfix;
	vector<char> lexems;
	map<char, int> priority;
	map<char, double> operands;

	void Parse()
	{
		for (char c : infix)
			if (c != ' ')
				lexems.push_back(c);
	}
	void Check();

public:
	TPostfix(string infx) : infix(infx)
	{
		priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, { '^', 3 }, { '!', 4 } };
	}
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string ToPostfix();

	vector<char> GetOperands() const
	{
		vector<char> op;
		for (const auto& item : operands)
			op.push_back(item.first);
		return op;
	}
	double Calculate(const map<char, double>& values); // Ввод переменных, вычисление по постфиксной форме
};

#endif