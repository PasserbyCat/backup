//WEEK12-Write a program to convert data format.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

struct record {
	int id;
	unsigned char name[16];
	int weight;
	int height;
	float bmi;
};

int main()
{
	record list[10];
	ifstream inFile("records.csv", ios::in );
	ofstream outFile("records.dat", ios::out | ios::binary);
	stringstream first, second;
	string value;
	int i = 0, j = 0, m = 0;
	while (getline(inFile, value, '\n')) {
		first.str("");
		first.clear();
		first << value;//存資料
		while (getline(first, value, ',')) {
			second.str("");
			second.clear();
			j++;
			//將ID,名字,體重,身高分別存起來
			if (j % 4 == 1) {
				second << value;
				second >> list[i].id;
			}
			if (j % 4 == 2) {
				second << value;
				second >> list[i].name;
			}
			if (j % 4 == 3) {
				second << value;
				second >> list[i].weight;
			}
			if (j % 4 == 0) {
				second << value;
				second >> list[i].height;
			}
		}
		
		list[i].bmi = list[i].weight * 100 * 100.0 / (list[i].height * list[i].height);//計算BMI

		cout << setw(4) << list[i].id << setw(16) << list[i].name << setw(6) << list[i].weight << setw(6) << list[i].height
			<< setw(10) << list[i].bmi << endl;
		
		if (list[i].bmi < 18.5) {
			m++;//計算體重不足的人數
			outFile.write(reinterpret_cast <char*> (&list[i]), sizeof(record));
		}

		i++;
	}

	cout << endl;

	inFile.close();
	outFile.close();
	
	record answer[10];
	ifstream infile("records.dat", ios::in | ios::binary);
	//再讀一次
	for (int k = 0; k < m; k++) {
		infile.read(reinterpret_cast <char*> (&answer[k]), sizeof(record));
		if (answer[k].bmi < 18.5)
			cout << setw(4) << answer[k].id << setw(16) << answer[k].name << setw(6) << answer[k].weight << setw(6) << answer[k].height
				<< setw(10) << answer[k].bmi << endl;
	}
	infile.close();
}