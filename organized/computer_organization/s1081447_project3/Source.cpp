#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <iomanip>

using namespace std;

int RF[5] = {0, 2, 4, 6, 8};
int RAT[5] = {};
int RSadd[3][3] = {};
int addBUF = 0;
int addFIN = 0;
int RSmul[2][3] = {};
int mulBUF = 0;
int mulFIN = 0;

bool finish()
{
	for (int i = 0; i < 5; i++) {
		if (RAT[i] != 0)
			return false;
		if (i > 2) {
			if (RSmul[i - 3][0] != 0) {
				return false;
			}
		}
		else {
			if (RSadd[i][0] != 0) {
				return false;
			}
		}
	}
	return true;
}
void print()
{
	cout << "     _ RF __\n";
	for (int i = 0; i < 5; i++) {
		cout << "  F" << i + 1 << " |" << setw(4) << RF[i] << " |\n";
	}
	cout << "     -------\n\n     _ RAT __\n";
	for (int i = 0; i < 5; i++) {
		cout << "  F" << i + 1 << " |";
		if (RAT[i] != 0)
			cout << "  RS" << RAT[i];
		else
			cout << "     ";
		cout << " |\n";
	}
	cout << "     --------\n\n    _ RS _________________\n";
	//RS1 |    + |    2 |    1 |
	for (int i = 0; i < 3; i++) {
		cout << "RS" << i + 1 << " |";
		if (RSadd[i][0] == 0) {
			cout << "      |      |      |\n";
			continue;
		}
		if (RSadd[i][0] == 1)
			cout << "    + |";
		else
			cout << "    - |";
		if (RSadd[i][1] < 0)
			cout << "  RS" << -(RSadd[i][1]) << " |";
		else
			cout << "    "<< RSadd[i][1] << " |";
		if (RSadd[i][2] < 0)
			cout << "  RS" << -(RSadd[i][2]) << " |\n";
		else
			cout << "    " << RSadd[i][2] << " |\n";
	}
	cout << "    ----------------------\nBUFFER: ";
	if (addBUF == 0) {
		cout << "empty";
	}
	else {
		cout << "(RS" << addBUF << ")" << setw(2) << RSadd[addBUF - 1][1];
		if (RSadd[addBUF - 1][0] == 1)
			cout << " +";
		else
			cout << " -";
		cout << setw(2) << RSadd[addBUF - 1][2];
	}
	cout << "\n\n    ______________________\n";
	for (int i = 0; i < 2; i++) {
		cout << "RS" << i + 4 << " |";
		if (RSmul[i][0] == 0) {
			cout << "      |      |      |\n";
			continue;
		}
		if (RSmul[i][0] == 1)
			cout << "    * |";
		else
			cout << "    / |";
		if (RSmul[i][1] < 0)
			cout << "  RS" << -(RSmul[i][1]) << " |";
		else
			cout << "    " << RSmul[i][1] << " |";
		if (RSmul[i][2] < 0)
			cout << "  RS" << -(RSmul[i][2]) << " |\n";
		else
			cout << "    " << RSmul[i][2] << " |\n";
	}
	cout << "    ----------------------\nBUFFER: ";
	if (mulBUF == 0) {
		cout << "empty";
	}
	else {
		cout << "(RS" << mulBUF << ")" << setw(2) << RSmul[mulBUF - 4][1];
		if (RSmul[mulBUF - 4][0] == 1)
			cout << " *";
		else
			cout << " /";
		cout << setw(2) << RSmul[mulBUF - 4][2];
	}
	cout << "\n\n\n";
}

int main()
{
	fstream inFile("input.txt", ios::in);
	queue<string>all;
	string temp;
	int timer = 0;
	while (inFile) {
		all.push(temp);
		getline(inFile, temp);
	}
	all.pop();
	do {
		timer++;
		bool change = false;
		//WR
		if (addFIN == timer) {
			for (int i = 0; i < 5; i++) {
				if (i < 3) {
					if (RSadd[addBUF - 1][0] == 1) {
						if (RSadd[i][1] == -(addBUF)) {
							RSadd[i][1] = RSadd[addBUF - 1][1] + RSadd[addBUF - 1][2];
						}
						if (RSadd[i][2] == -(addBUF)) {
							RSadd[i][2] = RSadd[addBUF - 1][1] + RSadd[addBUF - 1][2];
						}
					}
					else {
						if (RSadd[i][1] == -(addBUF)) {
							RSadd[i][1] = RSadd[addBUF - 1][1] - RSadd[addBUF - 1][2];
						}
						if (RSadd[i][2] == -(addBUF)) {
							RSadd[i][2] = RSadd[addBUF - 1][1] - RSadd[addBUF - 1][2];
						}
					}
				}
				else {
					if (RSmul[addBUF - 4][0] == 1) {
						if (RSmul[i - 3][1] == -(addBUF)) {
							RSmul[i - 3][1] = RSadd[addBUF - 1][1] + RSadd[addBUF - 1][2];
						}
						if (RSmul[i - 3][2] == -(addBUF)) {
							RSmul[i - 3][2] = RSadd[addBUF - 1][1] + RSadd[addBUF - 1][2];
						}
					}
					else {
						if (RSmul[i - 3][1] == -(addBUF)) {
							RSmul[i - 3][1] = RSadd[addBUF - 1][1] - RSadd[addBUF - 1][2];
						}
						if (RSmul[i - 3][2] == -(addBUF)) {
							RSmul[i - 3][2] = RSadd[addBUF - 1][1] - RSadd[addBUF - 1][2];
						}
					}
				}
			}
			for (int i = 0; i < 5; i++) {
				if (RSadd[addBUF - 1][0] == 1) {
					if (RAT[i] == addBUF) {
						RAT[i] = 0;
						RF[i] = RSadd[addBUF - 1][1] + RSadd[addBUF - 1][2];
					}
				}
				else {
					if (RAT[i] == addBUF) {
						RAT[i] = 0;
						RF[i] = RSadd[addBUF - 1][1] - RSadd[addBUF - 1][2];
					}
				}
			}
			RSadd[addBUF - 1][0] = 0;
			addBUF = 0;
			change = true;
		}
		if (mulFIN == timer) {
			for (int i = 0; i < 5; i++) {
				if (i < 3) {
					if (RSmul[mulBUF - 4][0] == 1) {
						if (RSadd[i][1] == -(mulBUF)) {
							RSadd[i][1] = RSmul[mulBUF - 4][1] * RSmul[mulBUF - 4][2];
						}
						if (RSadd[i][2] == -(mulBUF)) {
							RSadd[i][2] = RSmul[mulBUF - 4][1] * RSmul[mulBUF - 4][2];
						}
					}
					else {
						if (RSadd[i][1] == -(mulBUF)) {
							RSadd[i][1] = RSmul[mulBUF - 4][1] / RSmul[mulBUF - 4][2];
						}
						if (RSadd[i][2] == -(mulBUF)) {
							RSadd[i][2] = RSmul[mulBUF - 4][1] / RSmul[mulBUF - 4][2];
						}
					}
				}
				else {
					if (RSmul[mulBUF - 4][0] == 1) {
						if (RSmul[i - 3][1] == -(mulBUF)) {
							RSmul[i - 3][1] = RSmul[mulBUF - 4][1] * RSmul[mulBUF - 4][2];
						}
						if (RSmul[i - 3][2] == -(mulBUF)) {
							RSmul[i - 3][2] = RSmul[mulBUF - 4][1] * RSmul[mulBUF - 4][2];
						}
					}
					else {
						if (RSmul[i - 3][1] == -(mulBUF)) {
							RSmul[i - 3][1] = RSmul[mulBUF - 4][1] / RSmul[mulBUF - 4][2];
						}
						if (RSmul[i - 3][2] == -(mulBUF)) {
							RSmul[i - 3][2] = RSmul[mulBUF - 4][1] / RSmul[mulBUF - 4][2];
						}
					}
				}
			}
			for (int i = 0; i < 5; i++) {
				if (RSmul[mulBUF - 4][0] == 1) {
					if (RAT[i] == mulBUF) {
						RAT[i] = 0;
						RF[i] = RSmul[mulBUF - 4][1] * RSmul[mulBUF - 4][2];
					}
				}
				else {
					if (RAT[i] == mulBUF) {
						RAT[i] = 0;
						RF[i] = RSmul[mulBUF - 4][1] / RSmul[mulBUF - 4][2];
					}
				}
			}
			RSmul[mulBUF - 4][0] = 0;
			mulBUF = 0;
			change = true;
		}
		//dispatch
		for (int i = 0; i < 3; i++) {
			if (addBUF == 0 && RSadd[i][0] != 0) {
				if (RSadd[i][1] >= 0 && RSadd[i][2] >= 0) {
					addBUF = i + 1;
					addFIN = timer + 2;
					change = true;
					break;
				}
			}
		}
		for (int i = 3; i < 5; i++) {
			if (mulBUF == 0 && RSmul[i - 3][0] != 0) {
				if (RSmul[i - 3][1] >= 0 && RSmul[i - 3][2] >= 0) {
					mulBUF = i + 1;
					if (RSmul[i - 3][0] == -1)
						mulFIN = timer + 40;
					else
						mulFIN = timer + 10;
					change = true;
					break;
				}
			}
		}
		//issue
		if (all.size() != 0) {
			temp = all.front();
			bool ime = false;
			if (temp[3] == 'I')
				ime = true;
			if (temp[0] == 'A') {
				for (int i = 0; i < 3; i++) {
					if (RSadd[i][0] == 0) {
						RSadd[i][0] = 1;
						if (ime) {
							if (RAT[temp[10] - '0' - 1] == 0)
								RSadd[i][1] = RF[temp[10] - '0' - 1];
							else
								RSadd[i][1] = -(RAT[temp[10] - '0' - 1]);
							RSadd[i][2] = temp[13] - '0';
							RAT[temp[6] - '0' - 1] = i + 1;
						}
						else {
							if (RAT[temp[9] - '0' - 1] == 0)
								RSadd[i][1] = RF[temp[9] - '0' - 1];
							else
								RSadd[i][1] = -(RAT[temp[9] - '0' - 1]);
							if (RAT[temp[13] - '0' - 1] == 0)
								RSadd[i][2] = RF[temp[13] - '0' - 1];
							else
								RSadd[i][2] = -(RAT[temp[13] - '0' - 1]);
							RAT[temp[5] - '0' - 1] = i + 1;
						}
						all.pop();
						change = true;
						break;
					}
				}
			}
			else if (temp[0] == 'S') {
				for (int i = 0; i < 3; i++) {
					if (RSadd[i][0] == 0) {
						RSadd[i][0] = -1;
						if (ime) {
							if (RAT[temp[10] - '0' - 1] == 0)
								RSadd[i][1] = RF[temp[10] - '0' - 1];
							else
								RSadd[i][1] = -(RAT[temp[10] - '0' - 1]);
							RSadd[i][2] = temp[13] - '0';
							RAT[temp[6] - '0' - 1] = i + 1;
						}
						else {
							if (RAT[temp[9] - '0' - 1] == 0)
								RSadd[i][1] = RF[temp[9] - '0' - 1];
							else
								RSadd[i][1] = -(RAT[temp[9] - '0' - 1]);
							if (RAT[temp[13] - '0' - 1] == 0)
								RSadd[i][2] = RF[temp[13] - '0' - 1];
							else
								RSadd[i][2] = -(RAT[temp[13] - '0' - 1]);
							RAT[temp[5] - '0' - 1] = i + 1;
						}
						all.pop();
						change = true;
						break;
					}
				}
			}
			else if (temp[0] == 'M') {
				for (int i = 0; i < 2; i++) {
					if (RSmul[i][0] == 0) {
						RSmul[i][0] = 1;
						if (ime) {
							if (RAT[temp[10] - '0' - 1] == 0)
								RSmul[i][1] = RF[temp[10] - '0' - 1];
							else
								RSmul[i][1] = -(RAT[temp[10] - '0' - 1]);
							RSmul[i][2] = temp[13] - '0';
							RAT[temp[6] - '0' - 1] = i + 4;
						}
						else {
							if (RAT[temp[9] - '0' - 1] == 0)
								RSmul[i][1] = RF[temp[9] - '0' - 1];
							else
								RSmul[i][1] = -(RAT[temp[9] - '0' - 1]);
							if (RAT[temp[13] - '0' - 1] == 0)
								RSmul[i][2] = RF[temp[13] - '0' - 1];
							else
								RSmul[i][2] = -(RAT[temp[13] - '0' - 1]);
							RAT[temp[5] - '0' - 1] = i + 4;
						}
						all.pop();
						change = true;
						break;
					}
				}
			}
			else if (temp[0] == 'D') {
				for (int i = 0; i < 2; i++) {
					if (RSmul[i][0] == 0) {
						RSmul[i][0] = -1;
						if (ime) {
							if (RAT[temp[10] - '0' - 1] == 0)
								RSmul[i][1] = RF[temp[10] - '0' - 1];
							else
								RSmul[i][1] = -(RAT[temp[10] - '0']);
							RSmul[i][2] = temp[13] - '0';
							RAT[temp[6] - '0' - 1] = i + 4;
						}
						else {
							if (RAT[temp[9] - '0' - 1] == 0)
								RSmul[i][1] = RF[temp[9] - '0' - 1];
							else
								RSmul[i][1] = -(RAT[temp[9] - '0' - 1]);
							if (RAT[temp[13] - '0' - 1] == 0)
								RSmul[i][2] = RF[temp[13] - '0' - 1];
							else
								RSmul[i][2] = -(RAT[temp[13] - '0' - 1]);
							RAT[temp[5] - '0' - 1] = i + 4;
						}
						all.pop();
						change = true;
						break;
					}
				}
			}
		}
		
		if (change) {
			cout << "Cycle " << timer << endl;
			print();
		}
	} while (!finish());
}