//#include "postfix.h"
//#include "stack.h"
//
//string TPostfix::ToPostfix()
//{
//	Parse();
//	Check();
//	TStack<char> st(100);
//	char stackItem;
//	for (char item : lexems)
//	{
//		switch (item)
//		{
//		case '(':
//			st.push(item);
//			break;
//		case ')':
//			stackItem = st.pop();
//			while (stackItem != '(')
//			{
//				postfix += stackItem;
//				stackItem = st.pop();
//			}
//			break;
//		case '+': case '-': case '*': case '/': case '^': case '!':
//			while (!st.empty())
//			{
//				stackItem = st.pop();
//				if (priority[item] <= priority[stackItem])
//					postfix += stackItem;
//				else
//				{
//					st.push(stackItem);
//					break;
//				}
//			}
//			st.push(item);
//			break;
//		default:
//			operands.insert({ item, 0.0 });
//			postfix += item;
//		}
//
//	}
//	while (!st.empty())
//	{
//		stackItem = st.pop();
//		if (stackItem != '(')
//			postfix += stackItem;
//	}
//	return postfix;
//}
//
//double TPostfix::Calculate(const map<char, double>& values)
//{
//	for (auto& val : values)
//	{
//		try
//		{
//			operands.at(val.first) = val.second;
//		}
//		catch (out_of_range& e) {}
//	}
//	TStack<double> st(100);
//	double leftOperand, rightOperand;
//	double result;
//	for (char lexem : postfix)
//	{
//		switch (lexem)
//		{
//		case '+':
//			rightOperand = st.pop();
//			leftOperand = st.pop();
//			st.push(leftOperand + rightOperand);
//			break;
//		case '-':
//			rightOperand = st.pop();
//			leftOperand = st.pop();
//			st.push(leftOperand - rightOperand);
//			break;
//		case '*':
//			rightOperand = st.pop();
//			leftOperand = st.pop();
//			st.push(leftOperand * rightOperand);
//			break;
//		case '/':
//			rightOperand = st.pop();
//			leftOperand = st.pop();
//			st.push(leftOperand / rightOperand);
//			break;
//		case '^':
//			rightOperand = st.pop();
//			leftOperand = st.pop();
//			st.push(pow(leftOperand, rightOperand));
//			break;
//		case '!':
//			rightOperand = st.pop();
//			result = 1;
//			for (int i = 1; i < rightOperand + 1; i++)
//			{
//				result *= i;
//			}
//			st.push(result);
//			break;
//		default:
//			st.push(operands[lexem]);
//		}
//	}
//	return st.pop();
//}
