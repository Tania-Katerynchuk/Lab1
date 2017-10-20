#define _CRT_SECURE_NO_WARNINGS
#include "Calculator.h"
#include "Matrix.h"
#include "Interface.h"
#include "ArchivingMatrix.h"
#include <iostream>
#include <clocale>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "ukr");
	
	Interface expression = "";
	int choice = 1;
	bool b = true;
	while (choice != 0) {
		cout << "[1] - Обчислення виразу з простих числел\n[2] - Дiї з матрицями\n[3] - Архiвування матрицi\n[0] - Вихiд з програми\nВведiть дiю яку ви хочете обрати: ";
		cin >> choice;
		if (choice == 1) {
			while (b) {
				expression.InputExpression();
				Calculate calculate = expression.OutputExpression();
				if (calculate.RightExpression()) {
					calculate.TransferPolishForm();
					calculate.SteckMoveExit();
					calculate.CalculationsPolishForm();
					b = false;
				}
				else b = true;
				cout << endl;
			}
		}

		else if (choice == 2) {
			Interface matrix;
			int nMatrix = 0;
			cout << "Введiть кiлькiсть стовпцiв i рядкiв матрицi(квадратної): ";
			cin >> nMatrix;
			double **mainMatrix1 = (double**)malloc(nMatrix * sizeof(double));

			cout << "Введiть елементи 1 матрицi:" << endl;
			for (int i = 0; i < nMatrix; i++)
				mainMatrix1[i] = (double*)malloc(nMatrix * sizeof(double));
			matrix.InputMatrix(mainMatrix1, nMatrix);

			cout << "Введiть елементи 2 матрицi:" << endl;
			double **mainMatrix2 = (double**)malloc(nMatrix * sizeof(double));
			for (int i = 0; i < nMatrix; i++)
				mainMatrix2[i] = (double*)malloc(nMatrix * sizeof(double));

			matrix.InputMatrix(mainMatrix2, nMatrix);
			cout << "A=\t";
			matrix.OutputMatrix(mainMatrix1, nMatrix);
			cout << "B=\t";
			matrix.OutputMatrix(mainMatrix2, nMatrix);

			int actionMatrix = 1;
			while (actionMatrix != 0) {
				cout << "Введiть номер дiї яку ви хочете зробити з матрицями:\n[1] - Додавання\n[2] - Вiднiмання\n[3] - Множення\n[4] - Дiлення\n[0] - Вихiд в меню\n";
				cin >> actionMatrix;

				double **mainMatrix = (double**)malloc(nMatrix * sizeof(double));
				for (int i = 0; i < nMatrix; i++)
					mainMatrix[i] = (double*)malloc(nMatrix * sizeof(int));

				if (actionMatrix == 1) {
					PlusMatrix(mainMatrix, mainMatrix1, mainMatrix2, nMatrix);
					cout << "A+B=\t";
					matrix.OutputMatrix(mainMatrix, nMatrix);
				}
				if (actionMatrix == 2) {
					MinusMatrix(mainMatrix, mainMatrix1, mainMatrix2, nMatrix);
					cout << "A-B=\t";
					matrix.OutputMatrix(mainMatrix, nMatrix);
				}
				if (actionMatrix == 3) {
					MultiplyMatrix(mainMatrix, mainMatrix1, mainMatrix2, nMatrix);
					cout << "A*B=\t";
					matrix.OutputMatrix(mainMatrix, nMatrix);
				}
				if (actionMatrix == 4) {
					DivisionMatrix(mainMatrix, mainMatrix1, mainMatrix2, nMatrix);
					cout << "A/B=\t";
					matrix.OutputMatrix(mainMatrix, nMatrix);
				}
				for (int i = 0; i < nMatrix; i++)
					free(mainMatrix[i]);
				free(mainMatrix);
			}

			for (int i = 0; i < nMatrix; i++)
				free(mainMatrix1[i]);
			free(mainMatrix1);
			for (int i = 0; i < nMatrix; i++)
				free(mainMatrix2[i]);
			free(mainMatrix2);
		}




		else if (choice == 3) {
			Interface arhivMatrix = "";
			int nArchivingMatrix = 6;
			cout << "Введiть кількість стовпцiв i рядкiв матрицi: "; cin >> nArchivingMatrix;
			int **mainArchivingMatrix = (int**)malloc(nArchivingMatrix * sizeof(int));
			for (int i = 0; i < nArchivingMatrix; i++)
				mainArchivingMatrix[i] = (int*)malloc(nArchivingMatrix * sizeof(int));

			int nLowerPartMatrix = 0, nUpperPartMatrix = 0;

			cout << "Матриця до архiвацiї: \n";
			InputArchivingMatrix(mainArchivingMatrix, nArchivingMatrix, nLowerPartMatrix, nUpperPartMatrix);
			arhivMatrix.OutputArchivingMatrix(mainArchivingMatrix, nArchivingMatrix);

			int *lowerPartMatrix = (int*)malloc(nLowerPartMatrix * sizeof(int));
			int *upperPartMatrix = (int*)malloc(nUpperPartMatrix * sizeof(int));
			int *diagonalMatrix = (int*)malloc(nArchivingMatrix * sizeof(int));

			TransferMatrix(mainArchivingMatrix, diagonalMatrix, lowerPartMatrix, upperPartMatrix, nArchivingMatrix);
			cout << "Дiагональ матрицi: ";
			for (int i = 0; i < nArchivingMatrix; i++) {
				cout << diagonalMatrix[i] << " ";
			}

			cout << endl<<"Нижня частина матрицi(ненульовi елементи): ";
			for (int i = 0; i < nLowerPartMatrix;i++) {
				cout << lowerPartMatrix[i] << " ";
			}
			cout << endl<<"Верхня частина матрицi(ненульовi елементи):: ";
			for (int i = 0; i < nUpperPartMatrix; i++) {
				cout << upperPartMatrix[i] << " ";
			}
			cout << endl;

			for (int i = 0; i < nArchivingMatrix; i++)
				free(mainArchivingMatrix[i]);
			free(mainArchivingMatrix);


			int **createdMatrix = (int**)malloc(nArchivingMatrix * sizeof(int));
			for (int i = 0; i < nArchivingMatrix; i++)
				createdMatrix[i] = (int*)malloc(nArchivingMatrix * sizeof(int));
			UnzippingMatrix(createdMatrix, diagonalMatrix, lowerPartMatrix, upperPartMatrix, nArchivingMatrix);
			cout << "Розархiвована матриця: \n";
			arhivMatrix.OutputArchivingMatrix(createdMatrix, nArchivingMatrix);
			cout << endl;
			
			free(diagonalMatrix);
			free(lowerPartMatrix);
			free(upperPartMatrix);
			for (int i = 0; i < nArchivingMatrix; i++)
				free(createdMatrix[i]);
			free(createdMatrix);
		}
		else if(choice!=0)cout << "Некоректне введення!!!\n";
	}	
}