#pragma once

void InputArchivingMatrix(int**, int, int &, int &);



void InputArchivingMatrix(int **matrix, int n, int &nLower, int &nUpper) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i % 2 == 1 && i>j) {
				matrix[i][j] = 0;
				
			}
			else if (i % 2 == 0 && i<j) {
				matrix[i][j] = 0;
				
			}
			else {
				matrix[i][j] = 1 + rand() % (10 - 1 + 1);
			}
			if (i % 2 == 0 && i>j) {
				nLower++;
			}
			if (i % 2 == 1 && i<j) {
				nUpper++;
				
			}
		}
	}
}

void TransferMatrix(int **matrix,int *diagonalMatrix, int *lowerMatrix, int *upperMatrix, int n) {
	int iUp = 0, iLow=0, iDiagonal=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i % 2 == 0 && i>j) {
				lowerMatrix[iLow] = matrix[i][j];
				iLow++;
			}
			else if (i % 2 == 1 && i<j) {
				upperMatrix[iUp] = matrix[i][j];
				iUp++;
			}
			else if (i == j) {
				diagonalMatrix[iDiagonal] = matrix[i][j];
				iDiagonal++;
			}
		}
	}
}


void UnzippingMatrix(int **matrix, int *diagonalMatrix, int *lowerMatrix, int *upperMatrix, int n) {
	int iUp = 0, iLow = 0, iDiagonal = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i % 2 == 0 && i>j) {
				matrix[i][j]=lowerMatrix[iLow]  ;
				iLow++;
			}
			else if (i % 2 == 1 && i<j) {
				matrix[i][j]=upperMatrix[iUp];
				iUp++;
			}
			else if (i == j) {
				matrix[i][j]=diagonalMatrix[iDiagonal] ;
				iDiagonal++;
			}
			else matrix[i][j] = 0;
		}
	}
}