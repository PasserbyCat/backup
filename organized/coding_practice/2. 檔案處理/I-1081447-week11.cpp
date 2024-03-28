//week11 : sequential access
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
int main()
{
	stringstream first, second;
	string value;
	fstream inFile("records.csv", ios::in);
	int i = 0, j = 0, height[10] = {}, weight[10] = {}, allh = 0, allw = 0;
	char name[10][10];
	while (getline(inFile, value, '\n')) {
		first.str("");
		first.clear();
		first << value;
		while (getline(first, value, ',')) {
			second.str("");
			second.clear();
			j++;
			if (j % 4 == 2) {
				second << value;
				second >> name[i];
			}
			if (j % 4 == 3) {
				second << value;
				second >> weight[i];
			}
			if (j % 4 == 0) {
				second << value;
				second >> height[i];
			}
		}
		i++;
	}
	for (int k = 0; k < 10; k++) {
		allh += height[k];
		allw += weight[k];
	}
	cout << allh / 10.0 << endl << allw / 10.0 << endl;
	int max = 0;
	for (int l = 1; l < 11; l++) {
		for (int k = 0; k < 10; k++)
			if (height[k] > max)
				max = height[k];
		for (int k = 0; k < 10; k++)
			if (height[k] == max) {
				cout << k + 1 << "," << name[k] << "," << weight[k] << "," << height[k] << endl;
				height[k] = 0;
			}
		max = 0;
	}
}