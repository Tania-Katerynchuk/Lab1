#pragma once
#include <iostream>
#include <string>

using namespace std;

class Interface {
protected:
	string initialExpression;
public:
	
	Interface() {}
	Interface(string f1) {
		initialExpression = f1;
	}
	string InputExpression() {
		cout << "¬ведiть вираз: ";
		cin >> initialExpression;
		return initialExpression;
	}
	string OutputExpression() {
		return initialExpression;
	}
	void InputMatrix(int **matrix, int n) {
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++)
			{
				cout << "[" << i << "][" << j << "]:"; cin >> matrix[i][j];
			}
		}
	}
	void OutputMatrix(int **matrix, int n) {
		for (int i = 0; i < n; i++) {
			cout << "|";
			for (int j = 0; j < n; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << "|" << endl << "\t";
		}
		cout << endl;
	}
	void OutputArchivingMatrix(int **matrix, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};



