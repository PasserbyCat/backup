//矩陣運算
/*
以三乘三矩陣為主
*/
#include <iostream>

using namespace std;

int createMatrixFromArray(int**& mat, int* sample);

int** multiplicateMatrix(int** first, int** second);

int printMatrix(int** answer);

int destroyMatrix(int** ptr);

int main()
{
	int sample1[9] = { 48, 24, 32, 69, 79, 59, 8, 24, 10 }; 
	int sample2[9] = { 18, 90, 2, 26, 31, 47, 47, 36, 98 };
	int** mat1 = NULL, ** mat2 = NULL, ** answer = NULL;
	createMatrixFromArray(mat1, sample1);
	createMatrixFromArray(mat2, sample2);
	answer = multiplicateMatrix(mat1, mat2);
	printMatrix(answer);
	printMatrix(mat1);
	printMatrix(mat2);
	destroyMatrix(mat1);
	destroyMatrix(mat2);
	destroyMatrix(answer);
}

int createMatrixFromArray(int**& mat, int sample[])
{
	mat = new int* [3]();
	for (int i = 0; i < 3; i++) {
		mat[i] = new int[3]();
		for (int j = 0; j < 3; j++) {
			mat[i][j] = sample[i + j * 3];
		}
	}
	return 0;
}

int** multiplicateMatrix(int** first, int** second)
{
	int** answer = new int* [3]();
	for (int i = 0; i < 3; i++) {
		answer[i] = new int[3]();
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				answer[i][j] += first[i][k] * second[k][j];
			}
		}
	}
	return answer;
}

int destroyMatrix(int** ptr)
{
	for (int i = 0; i < 3; i++) {
		delete[]ptr[i];
	}
	delete[]ptr;
	ptr = NULL;
	return 0;
}

int printMatrix(int** answer)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}