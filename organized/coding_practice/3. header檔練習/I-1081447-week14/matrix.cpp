#include "matrix.h"

void loaddata()
{
	stringstream first, second;
	string value;
	int a = 0, b = 0, c = 0, up = 0, length, width;

	ifstream inFile1("A.csv", ios::in);

	getline(inFile1, value, '\n');
	first.str("");
	first.clear();
	first << value;
	while (getline(first, value, ',')) {
		second.str("");
		second.clear();
		if (up == 0) {
			second << value;
			second >> length;
			up++;
		}
		else {
			second << value;
			second >> width;
		}
	}
	up = reset(up);
	int** list1 = new int* [length];
	for (int i = 0; i < length; i++)
		list1[i] = new int[width];

	while (getline(inFile1, value, '\n')) {
		first.str("");
		first.clear();
		first << value;
		while (getline(first, value, ',')) {
			second.str("");
			second.clear();
			up++;
			if (up % 3 == 1) {
				second << value;
				second >> list1[b][0];
			}
			else if (up % 3 == 2) {
				second << value;
				second >> list1[b][1];
			}
			else {
				second << value;
				second >> list1[b][2];
			}
		}
		cout << setw(8) << list1[b][0] << setw(8) << list1[b][1] << setw(8) << list1[b][2];
		eennddll();
		b++;
	}

	up = reset(up);
	b = reset(b);
	ifstream inFile2("B.csv", ios::in);

	getline(inFile2, value, '\n');
	first.str("");
	first.clear();
	first << value;
	while (getline(first, value, ',')) {
		second.str("");
		second.clear();
		if (up == 0) {
			second << value;
			second >> length;
			up++;
		}
		else {
			second << value;
			second >> width;
		}
	}
	up = reset(up);
	int** list2 = new int* [length];
	for (int i = 0; i < length; i++)
		list2[i] = new int[width];

	while (getline(inFile2, value, '\n')) {
		first.str("");
		first.clear();
		first << value;
		while (getline(first, value, ',')) {
			second.str("");
			second.clear();
			up++;
			if (up % 3 == 1) {
				second << value;
				second >> list2[b][0];
			}
			else if (up % 3 == 2) {
				second << value;
				second >> list2[b][1];
			}
			else {
				second << value;
				second >> list2[b][2];
			}
		}
		cout << setw(8) << list2[b][0] << setw(8) << list2[b][1] << setw(8) << list2[b][2];
		eennddll();
		b++;
	}
	int answer[100][100] = {};
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			for (int k = 0; k < width; k++) {
				answer[i][j] += list1[i][k] * list2[k][j];
			}
			cout << setw(8) << answer[i][j];
		}
		eennddll();
	}

	for (int i = 0; i < length; i++)
		delete[]list1[i];
	delete[]list1;
	for (int i = 0; i < length; i++)
		delete[]list2[i];
	delete[]list2;
}

void eennddll()
{
	cout << endl;
}

int reset(int number)
{
	number = 0;
	return number;
}