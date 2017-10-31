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

	while (choice != 0) {
		cout << "[1] - ���������� ������ � ������� ������\n[2] - �i� � ���������\n[3] - ���i������� ������i\n[0] - ���i� � ��������\n����i�� �i� ��� �� ������ ������: ";
		cin >> choice;
		bool right = true;
		if (choice == 1) {
			while (right) {
				expression.InputExpression();
				Calculate calculate = expression.OutputExpression();
				if (calculate.RightExpression()) {
					calculate.TransferPolishForm();
					calculate.SteckMoveExit();
					calculate.CalculationsPolishForm();
					right = false;
				}
				else right = true;
				cout << endl;
			}
		}

		else if (choice == 2) {
			Interface matrix;
			int nMatrix = 0;
			cout << "����i�� �i���i��� ������i� i ����i� ������i(���������): ";
			cin >> nMatrix;
			double **mainMatrix1 = new double*[nMatrix];

			for (int i = 0; i < nMatrix; i++)
				mainMatrix1[i] = new double[nMatrix];
			matrix.InputMatrix(mainMatrix1, nMatrix);

			double **mainMatrix2 = new double*[nMatrix];
			for (int i = 0; i < nMatrix; i++)
				mainMatrix2[i] = new double[nMatrix];

			matrix.InputMatrix(mainMatrix2, nMatrix);
			cout << "A=\t";
			matrix.OutputMatrix(mainMatrix1, nMatrix);
			cout << "B=\t";
			matrix.OutputMatrix(mainMatrix2, nMatrix);

			int actionMatrix = 1;
			while (actionMatrix != 0) {
				cout << "����i�� ����� �i� ��� �� ������ ������� � ���������:\n[1] - ���������\n[2] - �i��i�����\n[3] - ��������\n[4] - �i�����\n[0] - ���i� � ����\n";
				cin >> actionMatrix;

				double **mainMatrix = new double*[nMatrix];
				for (int i = 0; i < nMatrix; i++)
					mainMatrix[i] = new double[nMatrix];
				switch (actionMatrix) {
				case 1:
					PlusMatrix(mainMatrix, mainMatrix1, mainMatrix2, nMatrix);
					cout << "A+B=\t";
					matrix.OutputMatrix(mainMatrix, nMatrix);
					break;
				case 2:
					MinusMatrix(mainMatrix, mainMatrix1, mainMatrix2, nMatrix);
					cout << "A-B=\t";
					matrix.OutputMatrix(mainMatrix, nMatrix);
					break;
				case 3:
					MultiplyMatrix(mainMatrix, mainMatrix1, mainMatrix2, nMatrix);
					cout << "A*B=\t";
					matrix.OutputMatrix(mainMatrix, nMatrix);
					break;
				case 4:
					DivisionMatrix(mainMatrix, mainMatrix1, mainMatrix2, nMatrix);
					cout << "A/B=\t";
					matrix.OutputMatrix(mainMatrix, nMatrix);
					break;
				default:
					cout << "�������!!!";
					break;
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
			cout << "����i�� ������� ������i� i ����i� ������i: "; cin >> nArchivingMatrix;
			int **mainArchivingMatrix = new int*[nArchivingMatrix];
			for (int i = 0; i < nArchivingMatrix; i++)
				mainArchivingMatrix[i] = new int[nArchivingMatrix];

			int nLowerPartMatrix = 0, nUpperPartMatrix = 0;

			cout << "������� �� ���i���i�: \n";
			InputArchivingMatrix(mainArchivingMatrix, nArchivingMatrix, nLowerPartMatrix, nUpperPartMatrix);
			arhivMatrix.OutputArchivingMatrix(mainArchivingMatrix, nArchivingMatrix);

			int *lowerPartMatrix = new int[nLowerPartMatrix];
			int *upperPartMatrix = new int[nUpperPartMatrix];
			int *diagonalMatrix = new int[nArchivingMatrix];

			TransferMatrix(mainArchivingMatrix, diagonalMatrix, lowerPartMatrix, upperPartMatrix, nArchivingMatrix);
			cout << "�i������� ������i: ";
			for (int i = 0; i < nArchivingMatrix; i++) {
				cout << diagonalMatrix[i] << " ";
			}

			cout << endl << "����� ������� ������i(��������i ��������): ";
			for (int i = 0; i < nLowerPartMatrix; i++) {
				cout << lowerPartMatrix[i] << " ";
			}
			cout << endl << "������ ������� ������i(��������i ��������):: ";
			for (int i = 0; i < nUpperPartMatrix; i++) {
				cout << upperPartMatrix[i] << " ";
			}
			cout << endl;

			for (int i = 0; i < nArchivingMatrix; i++)
				free(mainArchivingMatrix[i]);
			free(mainArchivingMatrix);


			int **createdMatrix = new int*[nArchivingMatrix];
			for (int i = 0; i < nArchivingMatrix; i++)
				createdMatrix[i] = new int[nArchivingMatrix];
			UnzippingMatrix(createdMatrix, diagonalMatrix, lowerPartMatrix, upperPartMatrix, nArchivingMatrix);
			cout << "������i������ �������: \n";
			arhivMatrix.OutputArchivingMatrix(createdMatrix, nArchivingMatrix);
			cout << endl;

			free(diagonalMatrix);
			free(lowerPartMatrix);
			free(upperPartMatrix);
			for (int i = 0; i < nArchivingMatrix; i++)
				free(createdMatrix[i]);
			free(createdMatrix);
		}
		else if (choice != 0)cout << "���������� ��������!!!\n";
	}
}