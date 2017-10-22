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
//введення виразу
string Interface::InputExpression() {
	cout << "Введiть вираз: ";
	cin >> initialExpression;
	return initialExpression;
}
//виведення виразу
string Interface::OutputExpression() {
	return initialExpression;
}
//введення матриці
void Interface::InputMatrix(double **matrix, int n) {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
		{
			cout << "[" << i << "][" << j << "]:"; cin >> matrix[i][j];
		}
	}
}
//виведення матриці
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
//виведення матриці архівування
void Interface::OutputArchivingMatrix(int **matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


