#pragma once

void PlusMatrix(double **matrix, double **matrix1, double **matrix2, int n) {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
		{
			matrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}

void MinusMatrix(double **matrix, double **matrix1, double **matrix2, int n) {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
		{
			matrix[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
}

void MultiplyMatrix(double **matrix, double **matrix1, double **matrix2, int n) {

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
		{
			matrix[i][j] = 0;
			for (int k = 0; k < n; k++) {
				matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}

		}
	}
}

void DivisionMatrix(double **matrix, double **matrix1, double **matrix2, int n) {
	double **matrix3 = (double**)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++)
		matrix3[i] = (double*)malloc(n * sizeof(double));
	double element;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
			if (i == j)
				matrix3[i][j] = 1;
			else
				matrix3[i][j] = 0;
		}

	for (int i = 0; i < n; i++)
	{
		element = matrix2[i][i];

		for (int j = 0; j < n; j++)
		{
			matrix2[i][j] /= element;
			matrix3[i][j] /= element;
		}

		for (int k = i + 1; k < n; k++)
		{
			element = matrix2[k][i];

			for (int j = 0; j < n; j++)
			{
				matrix2[k][j] -= matrix2[i][j] * element;
				matrix3[k][j] -= matrix3[i][j] * element;
			}
		}
	}

	for (int i = n - 1; i > 0; i--)
	{
		for (int k = i - 1; k >= 0; k--)
		{
			element = matrix2[k][i];

			for (int j = 0; j < n; j++)
			{
				matrix2[k][j] -= matrix2[i][j] * element;
				matrix3[k][j] -= matrix3[i][j] * element;
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				matrix[i][j] += matrix1[i][k] * matrix2[k][j];

	for (int i = 0; i < n; i++)
		free(matrix3[i]);
	free(matrix3);

}








/*class Matrix {
protected:
int n;
int **m1,**m2;
public:
Matrix() {}
~Matrix(){
free(m1);
free(m2);
}
Matrix(int **m11,int **m22,int n1) {
m1 = m11;
m2 = m22;
n = n1;
}
void inputmat() {
cout << "Введіть кількість стовпців і рядків матриці(квадратної): "; cin >> n;
int **m1 = (int**)malloc(n * sizeof(int));
int **m2 = (int**)malloc(n * sizeof(int));
cout << "Введіть елементи 1 матриці:" << endl;
for (int i = 0; i < n; i++)
m1[i] = (int*)malloc(n * sizeof(int));
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
cout << "[" << i + 1 << "][" << j + 1 << "]="; cin >> m1[i][j];
}
}
cout << "Введіть елементи 2 матриці:" << endl;
for (int i = 0; i < n; i++)
m2[i] = (int*)malloc(n * sizeof(int));
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
cout << "[" << i + 1 << "][" << j + 1 << "]="; cin >> m2[i][j];
}
}
}
void outputmat() {
cout << "A=|";
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
cout << m1[i][j]<<" ";
}
cout <<"|"<< endl;
}
cout << "B=|";
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
cout <<  m2[i][j]<<" ";
}
cout << "|" << endl;
}
}
};*/