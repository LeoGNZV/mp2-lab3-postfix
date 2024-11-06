#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
	string expression;
	double res;

	setlocale(LC_ALL, "Russian");
	cout << "Введите арифметическое выражение, используя переменные вместо значений: ";
	getline(cin, expression);
	TPostfix postfix(expression);
	cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
	postfix.ToPostfix();
	cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
	vector<char> operands = postfix.GetOperands();
	map<char, double> values;
	double val;
	for (const auto& op : operands)
	{
		cout << "Введите переменную " << op << ": ";
		cin >> val;
		values[op] = val;
		cout << "\n";
	}
	res = postfix.Calculate(values);
	cout << res << endl;

	return 0;
}
