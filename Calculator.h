#pragma once
#include "Interface.h"
#include <stack>
#include <queue>


class Calculate:public Interface {
protected:
	string initialExpression;
	queue <string> exit;
	queue <string> expression;
	stack <string> steck;
	stack <double> number;
	string auxiliary;
	int numberMulDiv[100];
	int numberPow[100];
	int numberPlMin[100];
	int numberBrackets = 0;
public:
	Calculate() {}
	Calculate(string f1) {
		initialExpression = f1;
	}

	bool RightExpression() {
		for (int i = 0; i < initialExpression.size(); i++) {
			if (initialExpression[i] >= 48 && initialExpression[i] <= 57) {
				if (initialExpression[i + 1] >= 48 && initialExpression[i + 1] <= 57) {
					auxiliary.append(initialExpression, i, 1);
				}
				else {
					expression.push(auxiliary.append(initialExpression, i, 1));
					if (!ProstoNumber(atoi(auxiliary.c_str()))) {
						cout << "Помилка! Введіть вираз який буде складатися тільки з простих чисел:" << endl;
						while (!expression.empty()) {
							expression.pop();
						}
						auxiliary.clear();
						return false;
					}
					auxiliary.clear();
				}
			}
			else if (initialExpression[i] == '+' || initialExpression[i] == '-' || initialExpression[i] == '*' || initialExpression[i] == '/' || initialExpression[i] == '^' || initialExpression[i] == '(' || initialExpression[i] == ')' || initialExpression[i] == '=') {
				expression.push(auxiliary.append(initialExpression, i, 1));
				auxiliary.clear();
			}
			else {
				cout << "Помилка! Некоректне значення. ";
				while (!expression.empty()) {
					expression.pop();
				}
				InputExpression();
				RightExpression();
			}
		}
		return true;
	}

	void TransferPolishForm() {
		for (int i = 0; i < 100; i++) {
			numberMulDiv[i] = 0;
			numberPow[i] = 0;
			numberPlMin[i] = 0;
		}
		while (!expression.empty()) {
			VerifyNumber(expression.front());
			VerifyPlusMinus(expression.front());
			VerifyMultiplicationDivision(expression.front());
			VerifyPower(expression.front());
			VerifyBrackets(expression.front());
			if (!expression.empty())
				expression.pop();
		}

	}
	void VerifyNumber(string element) {
		if (element[0] >= 48 && element[0] <= 57) {
			exit.push(element);
			if (numberPow[numberBrackets] > 0) {
				exit.push(steck.top());
				steck.pop();
				if (numberMulDiv[numberBrackets] > 0) {
					exit.push(steck.top());
					steck.pop();
					numberMulDiv[numberBrackets] = 0;
				}
				numberPow[numberBrackets] = 0;
			}
		}
	}
	void VerifyPlusMinus(string element) {
		if (element == "+" || element == "-") {
			if (numberMulDiv[numberBrackets] > 0) {
				exit.push(steck.top());
				steck.pop();
				numberMulDiv[numberBrackets] = 0;
			}
			if (numberPlMin[numberBrackets] > 0) {
				exit.push(steck.top());
				steck.pop();
				numberPlMin[numberBrackets] = 0;
			}
			else
				numberPlMin[numberBrackets]++;
			steck.push(element);
		}
	}
	void VerifyMultiplicationDivision(string element) {
		if (element == "*" || element == "/") {
			if (numberMulDiv[numberBrackets] > 0) {
				exit.push(steck.top());
				steck.pop();
				numberMulDiv[numberBrackets] = 0;
			}
			steck.push(element);
			numberMulDiv[numberBrackets]++;
		}
	}
	void VerifyPower(string element) {
		if (element == "^") {
			steck.push(element);
			numberPow[numberBrackets]++;
		}
	}
	void VerifyBrackets(string element) {
		if (element == "(") {
			numberBrackets++;
			steck.push(element);
			expression.pop();
			while (!expression.empty()) {
				VerifyNumber(expression.front());
				VerifyPlusMinus(expression.front());
				VerifyMultiplicationDivision(expression.front());
				VerifyPower(expression.front());
				VerifyBrackets(expression.front());
				if (expression.front() == ")") {
					break;
					numberBrackets--;
				}
				expression.pop();
			}
			while (steck.top() != "(") {
				exit.push(steck.top());
				steck.pop();
			}
			steck.pop();
		}
	}
	void SteckMoveExit() {
		while (!steck.empty()) {
			exit.push(steck.top());
			steck.pop();
		}
	}
	void CalculationsPolishForm() {
		double calculations = 0;
		cout << "Польський запис виразу: ";
		while (!exit.empty()) {
			auxiliary = exit.front();
			if (auxiliary[0] >= 48 && auxiliary[0] <= 57) {
				number.push(atoi(auxiliary.c_str()));
			}
			else {
				double right = number.top();
				number.pop();
				double left = number.top();
				number.pop();
				if (auxiliary == "+") {
					number.push(left + right);
				}
				if (auxiliary == "-") {
					number.push(left - right);
				}
				if (auxiliary == "*") {
					number.push(left * right);
				}
				if (auxiliary == "/") {
					number.push(left / right);
				}
				if (auxiliary == "^") {
					number.push(pow(left, right));
				}
			}
			calculations = number.top();
			cout << auxiliary << " ";
			exit.pop();
		}
		cout << endl;
		cout << initialExpression << "=" << calculations << endl;
	}

	bool ProstoNumber(int n) {
		for (int i = 2; i <= sqrt(n); i++)
			if (n % i == 0)
				return false;
		return true;
	}

};

