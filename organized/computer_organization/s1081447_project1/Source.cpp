#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	map<string, int>opcode;
	{
		opcode["lui"] = 0;
		opcode["auipc"] = 1;
		opcode["jal"] = 2;
		opcode["jalr"] = 3;
		opcode["beq"] = 4;
		opcode["bne"] = 5;
		opcode["blt"] = 6;
		opcode["bge"] = 7;
		opcode["bltu"] = 8;
		opcode["bgeu"] = 9;
		opcode["lb"] = 10;
		opcode["lh"] = 11;
		opcode["lw"] = 12;
		opcode["lbu"] = 13;
		opcode["lhu"] = 14;
		opcode["sb"] = 15;
		opcode["sh"] = 16;
		opcode["sw"] = 17;
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
	}
	string input1, input2, answer;
	while (cin >> input1) {
		cin >> input2;
		answer.resize(0);
		int temp = opcode[input1];
		if (temp <= 17) {
			if (temp <= 14) {
				int rd = 0, offset = 0, rs1 = 0;
				answer += "1100000";
				for (int i = 0; i < input2.size(); i++) {
					if (input2[i] >= '0' && input2[i] <= '9') {
						rd *= 10;
						rd += input2[i] - '0';
					}
					else if (input2[i] == ',') {
						for (int j = i + 1; j < input2.size(); j++) {
							if (input2[j] == '(') {
								for (int k = j + 1; k < input2.size(); k++) {
									if (input2[k] >= '0' && input2[k] <= '9') {
										rs1 *= 10;
										rs1 += input2[k] - '0';
										i = j = input2.size();
									}
								}
							}
							else {
								offset *= 10;
								offset += input2[j] - '0';
							}
						}
					}
				}
				for (int i = 0; i < 5; i++) {
					answer += rd % 2 + '0';
					rd /= 2;
				}
				switch (temp)
				{
				case 10:
					answer += "000";
					break;
				case 11:
					answer += "100";
					break;
				case 12:
					answer += "010";
					break;
				case 13:
					answer += "001";
					break;
				case 14:
					answer += "101";
					break;
				}
				for (int i = 0; i < 5; i++) {
					answer += rs1 % 2 + '0';
					rs1 /= 2;
				}
				for (int i = 0; i < 12; i++) {
					answer += offset % 2 + '0';
					offset /= 2;
				}
			}
			else {
				int rs2 = 0, offset = 0, rs1 = 0;
				answer += "1100000";
				for (int i = 0; i < input2.size(); i++) {
					if (input2[i] >= '0' && input2[i] <= '9') {
						rs2 *= 10;
						rs2 += input2[i] - '0';
					}
					else if (input2[i] == ',') {
						for (int j = i + 1; j < input2.size(); j++) {
							if (input2[j] == '(') {
								for (int k = j + 1; k < input2.size(); k++) {
									if (input2[k] >= '0' && input2[k] <= '9') {
										rs1 *= 10;
										rs1 += input2[k] - '0';
										i = j = input2.size();
									}
								}
							}
							else {
								offset *= 10;
								offset += input2[j] - '0';
							}
						}
					}
				}
				for (int i = 0; i < 5; i++) {
					answer += offset % 2 + '0';
					offset /= 2;
				}
				switch (temp)
				{
				case 15:
					answer += "000";
					break;
				case 16:
					answer += "100";
					break;
				case 17:
					answer += "010";
					break;
				}
				for (int i = 0; i < 5; i++) {
					answer += rs1 % 2 + '0';
					rs1 /= 2;
				}
				for (int i = 0; i < 5; i++) {
					answer += rs2 % 2 + '0';
					rs2 /= 2;
				}
				for (int i = 0; i < 7; i++) {
					answer += offset % 2 + '0';
					offset /= 2;
				}
			}
		}
		else if (temp <= 26) {
			if (temp <= 23) {
				int rd = 0, imm = 0, rs1 = 0;
				answer += "1100100";
				for (int i = 0; i < input2.size(); i++) {
					if (input2[i] >= '0' && input2[i] <= '9') {
						rd *= 10;
						rd += input2[i] - '0';
					}
					else if (input2[i] == ',') {
						for (int j = i + 1; j < input2.size(); j++) {
							if (input2[j] >= '0' && input2[j] <= '9') {
								rs1 *= 10;
								rs1 += input2[j] - '0';
							}
							else if (input2[j] == ',') {
								for (int k = j + 1; k < input2.size(); k++) {
									if (input2[k] >= '0' && input2[k] <= '9') {
										imm *= 10;
										imm += input2[k] - '0';
										i = j = input2.size();
									}
								}
							}
						}
					}
				}
				for (int i = 0; i < 5; i++) {
					answer += rd % 2 + '0';
					rd /= 2;
				}
				switch (temp)
				{
				case 18:
					answer += "000";
					break;
				case 19:
					answer += "010";
					break;
				case 20:
					answer += "110";
					break;
				case 21:
					answer += "001";
					break;
				case 22:
					answer += "011";
					break;
				case 23:
					answer += "111";
					break;
				}
				for (int i = 0; i < 5; i++) {
					answer += rs1 % 2 + '0';
					rs1 /= 2;
				}
				for (int i = 0; i < 12; i++) {
					answer += imm % 2 + '0';
					imm /= 2;
				}
			}
			else {
				int rd = 0, imm = 0, rs1 = 0;
				answer += "1100100";
				for (int i = 0; i < input2.size(); i++) {
					if (input2[i] >= '0' && input2[i] <= '9') {
						rd *= 10;
						rd += input2[i] - '0';
					}
					else if (input2[i] == ',') {
						for (int j = i + 1; j < input2.size(); j++) {
							if (input2[j] >= '0' && input2[j] <= '9') {
								rs1 *= 10;
								rs1 += input2[j] - '0';
							}
							else if (input2[j] == ',') {
								for (int k = j + 1; k < input2.size(); k++) {
									if (input2[k] >= '0' && input2[k] <= '9') {
										imm *= 10;
										imm += input2[k] - '0';
										i = j = input2.size();
									}
								}
							}
						}
					}
				}
				for (int i = 0; i < 5; i++) {
					answer += rd % 2 + '0';
					rd /= 2;
				}
				switch (temp)
				{
				case 24:
					answer += "100";
					break;
				case 25:
					answer += "101";
					break;
				case 26:
					answer += "101";
					break;
				}
				for (int i = 0; i < 5; i++) {
					answer += rs1 % 2 + '0';
					rs1 /= 2;
				}
				for (int i = 0; i < 10; i++) {
					answer += imm % 2 + '0';
					imm /= 2;
				}
				if (temp == 26)
					answer += "10";
				else
					answer += "00";
			}
		}
		else {
			int rd = 0, rs2 = 0, rs1 = 0;
			answer += "1100110";
			for (int i = 0; i < input2.size(); i++) {
				if (input2[i] >= '0' && input2[i] <= '9') {
					rd *= 10;
					rd += input2[i] - '0';
				}
				else if (input2[i] == ',') {
					for (int j = i + 1; j < input2.size(); j++) {
						if (input2[j] >= '0' && input2[j] <= '9') {
							rs1 *= 10;
							rs1 += input2[j] - '0';
						}
						else if (input2[j] == ',') {
							for (int k = j + 1; k < input2.size(); k++) {
								if (input2[k] >= '0' && input2[k] <= '9') {
									rs2 *= 10;
									rs2 += input2[k] - '0';
									i = j = input2.size();
								}
							}
						}
					}
				}
			}
			for (int i = 0; i < 5; i++) {
				answer += rd % 2 + '0';
				rd /= 2;
			}
			switch (temp)
			{
			case 27:
				answer += "000";
				break;
			case 28:
				answer += "000";
				break;
			case 29:
				answer += "100";
				break;
			case 30:
				answer += "010";
				break;
			case 31:
				answer += "110";
				break;
			case 32:
				answer += "001";
				break;
			case 33:
				answer += "101";
				break;
			case 34:
				answer += "101";
				break;
			case 35:
				answer += "011";
				break;
			case 36:
				answer += "111";
				break;
			}
			for (int i = 0; i < 5; i++) {
				answer += rs1 % 2 + '0';
				rs1 /= 2;
			}
			for (int i = 0; i < 10; i++) {
				answer += rs2 % 2 + '0';
				rs2 /= 2;
			}
			if (temp == 28 || temp == 34)
				answer += "10";
			else
				answer += "00";
		}
		for (int i = answer.size() - 1; i >= 0; i--)
			cout << answer[i];
		cout << endl;
	}
}