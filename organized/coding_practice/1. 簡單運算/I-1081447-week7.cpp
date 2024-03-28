//Print the probability of each possible sum which vary from 2 to 12.
//The probability of each possible sum
/*
運用電腦亂數模擬骰子輸出之點數
計算各點數之機率
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	int seed = time(NULL);
	srand(seed);
	int row, column, array[6][6] = {};
	for (int i = 0; i < 36000; i++) {
		row = rand() % 6;
		column = rand() % 6;
		if (row == 0)
			row = 6;
		if (column == 0)
			column = 6;
		array[row - 1][column - 1]++;
	}
	cout << "  ";
	for (int i = 0; i < 6; i++) {
		cout << "    " << i + 1;
	}
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << i + 1 << " ";
		for (int j = 0; j < 6; j++) {
			cout << setw(5) << array[i][j];
		}
		cout << endl;
	}
	for (int k = 2; k < 13; k++) {
		cout << "P(" << k << ") =";
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (i + j == k - 2) {
					cout << "P(" << i + 1 << "+" << j + 1 << ")";
					if (i + 1 != 6 && j + 1 != 1) {
						cout << " + ";
					}
					else
						cout << " = ";
				}
			}
		}
		double answer = 0;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (i + j == k - 2) {
					answer += array[i][j] / 36000.0;
					cout << array[i][j] / 36000.0;
					if (i + 1 != 6 && j + 1 != 1) {
						cout << " + ";
					}
					else if (i == 0 && j == 0 || i == 5 && j == 5)
						cout << " ";
					else
						cout << " = ";
				}
			}
		}
		if (k == 2 || k == 12);
		else
			cout << answer;
		cout << endl;
	}
}