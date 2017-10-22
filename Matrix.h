#pragma once
//додавання матриць
void PlusMatrix(double **matrix, double **matrix1, double **matrix2, int n) {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
		{
			matrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}
//віднімання матриць
void MinusMatrix(double **matrix, double **matrix1, double **matrix2, int n) {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
		{
			matrix[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
}
//множення матриць
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
//ділення матриць
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