#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

fstream inFile("input.txt", ios::in | ios::out);
vector<string>all;
map <string, int>place;
map<string, int>opcode;
map<string, long long>value;
int entry;
vector<vector<int>> EN;

int execute(int op, int pl, int present);
int main()
{
	cout << "Please input entry(entry > 0):\n";
	cin >> entry;
	EN.resize(entry);
	for (int i = 0; i < entry; i++) {
		EN[i].resize(6);
	}
	while (inFile) {
		char buffer[200];
		inFile.getline(buffer, sizeof(buffer));
		string temp;
		for (int i = 0; buffer[i] != '\0'; i++) {
			if (buffer[i] == ':') {
				place[temp] = all.size();
				break;
			}
			if (buffer[i] == ';') {
				temp.push_back(buffer[i]);
				all.push_back(temp);
				break;
			}
			temp.push_back(buffer[i]);
		}
	}
	{
		//opcode["lui"] = 0;
		//opcode["auipc"] = 1;
		//opcode["jal"] = 2;
		//opcode["jalr"] = 3;
		opcode["beq"] = 4;
		opcode["bne"] = 5;
		opcode["blt"] = 6;
		opcode["bge"] = 7;
		opcode["bltu"] = 8;
		opcode["bgeu"] = 9;
		//opcode["lb"] = 10;
		//opcode["lh"] = 11;
		//opcode["lw"] = 12;
		//opcode["lbu"] = 13;
		//opcode["lhu"] = 14;
		opcode["li"] = 10;
		//opcode["sb"] = 15;
		//opcode["sh"] = 16;
		//opcode["sw"] = 17;
		opcode["addi"] = 18;
		opcode["slti"] = 19;
		opcode["sltiu"] = 20;
		opcode["xori"] = 21;
		opcode["ori"] = 22;
		opcode["andi"] = 23;
		opcode["slli"] = 24;
		opcode["srli"] = 25;
		opcode["srai"] = 26;
		opcode["add"] = 27;
		opcode["sub"] = 28;
		opcode["sll"] = 29;
		opcode["slt"] = 30;
		opcode["sltu"] = 31;
		opcode["xor"] = 32;
		opcode["srl"] = 33;
		opcode["sra"] = 34;
		opcode["or"] = 35;
		opcode["and"] = 36;

		value["R0"] = 0;
	}
	for (int i = 0; i < all.size(); i++) {
		string temp;
		for (int j = 0; j < all[i].size(); j++) {
			if (all[i][j] == ' ') {
				i = execute(opcode[temp], j + 1, i);
				break;
			}
			if (all[i][j] != '\t')
				temp.push_back(all[i][j]);
		}
	}
}

int execute(int op, int pl, int present)
{
	if (op == 10) {
		string temp;
		bool check = false;
		bool sign = true;
		for (int i = pl; i < all[present].size(); i++) {
			if (all[present][i] == ';')
				break;
			else if (all[present][i] == ',') {
				value[temp] = 0;
				check = true;
			}
			else if (check) {
				if (all[present][i] == '-') {
					sign = false;
					continue;
				}
				value[temp] *= 10;
				if (sign)
					value[temp] += all[present][i] - '0';
				else
					value[temp] -= all[present][i] - '0';
			}
			else
				temp.push_back(all[present][i]);
		}
		return present;
	}
	if (op >= 4 && op <= 9) {
		string first, second, temp;
		int check = 0;
		for (int i = pl; i < all[present].size(); i++) {
			if (all[present][i] == ';')
				break;
			else if (all[present][i] == ',' && check == 1) {
				check++;
				second = temp;
				temp.resize(0);
			}
			else if (all[present][i] == ',' && check == 0) {
				check++;
				first = temp;
				temp.resize(0);
			}
			else
				temp.push_back(all[present][i]);
		}

		switch (op) {
		case 4:
			op = (value[first] == value[second]) ? place[temp] - 1 : present;
			break;
		case 5:
			op = (value[first] != value[second]) ? place[temp] - 1 : present;
			break;
		case 6:
			op = (value[first] < value[second]) ? place[temp] - 1 : present;
			break;
		case 7:
			op = (value[first] >= value[second]) ? place[temp] - 1 : present;
			break;
		case 8:
			op = (value[first] < value[second]) ? place[temp] - 1 : present;
			break;
		case 9:
			op = (value[first] >= value[second]) ? place[temp] - 1 : present;
			break;
		}

		cout << "entry: " << present % entry << setprecision(19) << all[present] << endl << "(";
		int predict;
		switch (EN[present % entry][0]) {
		case 0:
			cout << "00";
			predict = 0;
			break;
		case 1:
			cout << "01";
			predict = 1;
			break;
		case 2:
			cout << "10";
			predict = 2;
			break;
		case 3:
			cout << "11";
			predict = 3;
			break;
		}
		for (int i = 1; i < 5; i++) {
			cout << ", ";
			switch (EN[present % entry][i]) {
			case 0:
				cout << "SN";
				break;
			case 1:
				cout << "WN";
				break;
			case 2:
				cout << "WT";
				break;
			case 3:
				cout << "ST";
				break;
			}
		}
		cout << ") ";

		if (EN[present % entry][predict + 1] > 1) {
			cout << "T ";
			if (op == present) {
				cout << "N   ";
				EN[present % entry][5]++;
				EN[present % entry][predict + 1]--;
			}
			else {
				cout << "T   ";
				EN[present % entry][predict + 1]++;
			}
		}
		else {
			cout << "N ";
			if (op == present) {
				cout << "N   ";
				EN[present % entry][predict + 1]--;
			}
			else {
				cout << "T   ";
				EN[present % entry][5]++;
				EN[present % entry][predict + 1]++;
			}
		}

		if (EN[present % entry][predict + 1] > 3)
			EN[present % entry][predict + 1] = 3;
		if (EN[present % entry][predict + 1] < 0)
			EN[present % entry][predict + 1] = 0;
		cout << "misprediction: " << EN[present % entry][5] << endl;

		if (EN[present % entry][0] == 3) {
			EN[present % entry][0]--;
			if (op != present)
				EN[present % entry][0]++;
		}
		else if (EN[present % entry][0] == 2) {
			EN[present % entry][0] -= 2;
			if (op != present)
				EN[present % entry][0]++;
		}
		else if (EN[present % entry][0] == 1) {
			EN[present % entry][0]++;
			if (op != present)
				EN[present % entry][0]++;
		}
		else if (EN[present % entry][0] == 0 && op != present)
			EN[present % entry][0]++;

		for (int i = 0; i < EN.size(); i++) {
			cout << "\tentry: " << i << "     (";
			switch (EN[i][0]) {
			case 0:
				cout << "00";
				break;
			case 1:
				cout << "01";
				break;
			case 2:
				cout << "10";
				break;
			case 3:
				cout << "11";
				break;
			}
			for (int j = 1; j < 5; j++) {
				cout << ", ";
				switch (EN[i][j]) {
				case 0:
					cout << "SN";
					break;
				case 1:
					cout << "WN";
					break;
				case 2:
					cout << "WT";
					break;
				case 3:
					cout << "ST";
					break;
				}
			}
			cout << ") \n";
		}
		cout << endl;
		return op;
	}
	else {
		string first, second, temp;
		int check = 0;
		for (int i = pl; i < all[present].size(); i++) {
			if (all[present][i] == ';')
				break;
			else if (all[present][i] == ',' && check == 1) {
				check++;
				second = temp;
				temp.resize(0);
			}
			else if (all[present][i] == ',' && check == 0) {
				check++;
				first = temp;
				temp.resize(0);
			}
			else
				temp.push_back(all[present][i]);
		}
		if (op <= 26) {
			int imme = 0;
			bool sign = true;
			for (int i = 0; i < temp.size(); i++) {
				imme *= 10;
				if (temp[i] == '-') {
					sign = false;
					continue;
				}
				if (sign)
					imme += temp[i] - '0';
				else
					imme -= temp[i] - '0';
			}
			unsigned int k = imme;
			unsigned real = value[second] >> imme;
			switch (op) {
			case 18:
				value[first] = value[second] + imme;
				break;
			case 19:
				value[first] = (value[second] < imme) ? 1 : 0;
				break;
			case 20:
				value[first] = (value[second] < k) ? 1 : 0;
				break;
			case 21:
				value[first] = value[second] ^ imme;
				break;
			case 22:
				value[first] = value[second] | imme;
				break;
			case 23:
				value[first] = value[second] & imme;
				break;
			case 24:
				value[first] = value[second] << imme;
				break;
			case 25:
				value[first] = real;
				break;
			case 26:
				value[first] = value[second] >> imme;
				break;
			}
		}
		else {
			unsigned int k = value[temp];
			unsigned real = value[second] >> value[temp];
			switch (op) {
			case 27:
				value[first] = value[second] + value[temp];
				break;
			case 28:
				value[first] = value[second] - value[temp];
				break;
			case 29:
				value[first] = value[second] << value[temp];
				break;
			case 30:
				value[first] = (value[second] < value[temp]) ? 1 : 0;
				break;
			case 31:

				value[first] = (value[second] < k) ? 1 : 0;
				break;
			case 32:
				value[first] = value[second] ^ value[temp];
			case 33:
				value[first] = real;
				break;
			case 34:
				value[first] = value[second] >> value[temp];
				break;
			case 35:
				value[first] = value[second] | value[temp];
				break;
			case 36:
				value[first] = value[second] & value[temp];
				break;
			}
		}
		return present;
	}
}
