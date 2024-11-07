#include "postfix.h"
#include "stack.h"

string TPostfix::ToPostfix()
{
	Parse();
	Check();
	TStack<char> st(100);
	char stackItem;
	for (char item : lexems)
	{
		switch (item)
		{
		case '(':
			st.push(item);
			break;
		case ')':
			stackItem = st.pop();
			while (stackItem != '(')
			{
				postfix += stackItem;
				stackItem = st.pop();
			}
			break;
		case '+': case '-': case '*': case '/': case '^': case '!':
			while (!st.empty())
			{
				stackItem = st.pop();
				if (priority[item] <= priority[stackItem])
					postfix += stackItem;
				else
				{
					st.push(stackItem);
					break;
				}
			}
			st.push(item);
			break;
		default:
			operands.insert({ item, 0.0 });
			postfix += item;
		}

	}
	while (!st.empty())
	{
		stackItem = st.pop();
		if (stackItem != '(')
			postfix += stackItem;
	}
	return postfix;
}


double TPostfix::Calculate(const map<char, double>& values)
{
	for (auto& val : values)
	{
		try
		{
			operands.at(val.first) = val.second;
		}
		catch (out_of_range& e) {}
	}
	TStack<double> st(100);
	double leftOperand, rightOperand;
	double result;
	for (char lexem : postfix)
	{
		switch (lexem)
		{
		case '+':
			rightOperand = st.pop();
			leftOperand = st.pop();
			st.push(leftOperand + rightOperand);
			break;
		case '-':
			rightOperand = st.pop();
			leftOperand = st.pop();
			st.push(leftOperand - rightOperand);
			break;
		case '*':
			rightOperand = st.pop();
			leftOperand = st.pop();
			st.push(leftOperand * rightOperand);
			break;
		case '/':
			rightOperand = st.pop();
			leftOperand = st.pop();
			st.push(leftOperand / rightOperand);
			break;
		case '^':
			rightOperand = st.pop();
			leftOperand = st.pop();
			st.push(pow(leftOperand, rightOperand));
			break;
		case '!':
			rightOperand = st.pop();
			result = 1;
			for (int i = 1; i < rightOperand + 1; i++)
			{
				result *= i;
			}
			st.push(result);
			break;
		default:
			st.push(operands[lexem]);
		}
	}
	return st.pop();
}

void TPostfix::Check()
{
	if (lexems.size() == 0)
		throw "empty string";
	if ((lexems[0] == '+') || (lexems[0] == '-') || (lexems[0] == '*') || (lexems[0] == '/') || (lexems[0] == '^') || (lexems[0] == '!') || (lexems[0] == ')'))
		throw "the expression begins with an operation";
	if ((lexems[lexems.size() - 1] == '+') || (lexems[lexems.size() - 1] == '-') || (lexems[lexems.size() - 1] == '*') || (lexems[lexems.size() - 1] == '/') || (lexems[lexems.size() - 1] == '^') || (lexems[lexems.size() - 1] == '('))
		throw "the expression ends with an operation";

	int count1 = 0, count2 = 0;
	int type_last_lexems = 4; // 0: +-*/^	1: )	2: (	3:!		4: a 
	if ((lexems[0] == '+') || (lexems[0] == '-') || (lexems[0] == '*') || (lexems[0] == '/') || (lexems[0] == '^'))
		type_last_lexems = 0;
	if (lexems[0] == ')')
	{
		type_last_lexems = 1;
		count2++;
	}
	if (lexems[0] == '(')
	{
		type_last_lexems = 2;
		count1++;
	}
	if ((lexems[0] == '!'))
		type_last_lexems = 3;
	for (int i = 1; i < lexems.size(); i++)
	{
		switch (lexems[i])
		{
		case '(':
			if (type_last_lexems == 1 || type_last_lexems == 3 || type_last_lexems == 4)
				throw "incorrect parenthesis order";
			count1++;
			type_last_lexems = 2;
			break;
		case ')':
			if (type_last_lexems == 0 || type_last_lexems == 2)
				throw "incorrect parenthesis order";
			count2++;
			type_last_lexems = 1;
			break;
		case '+': case '-': case '*': case '/': case '^':
			if (type_last_lexems == 0 || type_last_lexems == 2)
				throw "incorrect operations order";
			type_last_lexems = 0;
			break;
		case '!':
			if (type_last_lexems == 0 || type_last_lexems == 2 || type_last_lexems == 3)
				throw "incorrect factorial order";
			type_last_lexems = 3;
			break;
		default:
			if (type_last_lexems == 1 || type_last_lexems == 3 || type_last_lexems == 4)
				throw "incorrect variables order";
			type_last_lexems = 4;
			break;
		}
	}

	if (count1 != count2)
		throw "different number of opening and closing parenthesis";
}
