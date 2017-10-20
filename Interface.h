#pragma once
#include <iostream>
#include <string>

using namespace std;

class Interface {
protected:
	string initialExpression;
public:
	
	Interface() {}
	Interface(string f1);
	string InputExpression();
	string OutputExpression();
	void InputMatrix(double **matrix, int n);
	void OutputMatrix(double **matrix, int n);
	void OutputArchivingMatrix(int **matrix, int n);
};

Interface::Interface(string f1) {
	initialExpression = f1;
}

string Interface::InputExpression() {
	cout << "¬ведiть вираз: ";
	cin >> initialExpression;
	return initialExpression;
}

string Interface::OutputExpression() {
	return initialExpression;
}

void Interface::InputMatrix(double **matrix, int n) {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
		{
			cout << "[" << i << "][" << j << "]:"; cin >> matrix[i][j];
		}
	}
}

void Interface::OutputMatrix(double **matrix, int n) {
	for (int i = 0; i < n; i++) {
		cout << "|";
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "|" << endl << "\t";
	}
	cout << endl;
}

void Interface::OutputArchivingMatrix(int **matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


