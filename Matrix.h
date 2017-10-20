#pragma once

void PlusMatrix(int **matrix, int **matrix1, int **matrix2, int n) {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
		{
			matrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}

void MinusMatrix(int **matrix, int **matrix1, int **matrix2, int n) {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
		{
			matrix[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
}

void MultiplyMatrix(int **matrix, int **matrix1, int **matrix2, int n) {

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

void DivisionMatrix(int **matrix, int **matrix1, int **matrix2, int n) {

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
		{
			if ((i + j) % 2 == 0)
				matrix[i][j] = matrix2[j][i];
			else
				matrix[i][j] = -matrix2[j][i];
		}
	}

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