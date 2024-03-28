//bubble sort

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void bubbleSort(int *studentsScores, int amounts);

int main()
{
	int seed = time(NULL);
	srand(seed);
	int *studentsScores = new int [10](), number = 0;
	float average = 0;
	for (int i = 0; i < 10; i++) {
		*(studentsScores + i) = rand() % 101;
	}
	bubbleSort(studentsScores, 10);
	average = (*(studentsScores + 4) + *(studentsScores + 5)) / 2.0;
	cout << average << endl;
	for (int i = 0; i < 10; i++) {
		cout << *(studentsScores + i) << endl;
	}
	delete[] studentsScores;
}

void bubbleSort(int *studentsScores, int amounts)
{
	int store = 0;
	for (int i = amounts - 1; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			if (*(studentsScores + j) < *(studentsScores + j - 1)) {
				store = *(studentsScores + j);
				*(studentsScores + j) = *(studentsScores + j - 1);
				*(studentsScores + j - 1) = store;
			}
		}
	}
}