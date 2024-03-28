//week13 Random-Access Files
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define MAXWORDLENGTH 255
struct dictionary {
	char word[MAXWORDLENGTH];
	unsigned int count;
};

void dictload(vector< dictionary >& answer);

int main(int argc, char* argv[])// arg[0] //program name, arg[1] // test1.txt
{
	vector< dictionary > answer;
	answer.resize(1);//設size為1

	char words[1000][1000];
	int num = 0;
	dictload(answer);

	ifstream test(argv[1], ios::in);
	while (test) {
		test >> words[num];//讀字串
		for (int i = 0; words[num][i] != '\0'; i++) {
			if (words[num][i] >= 'A' && words[num][i] <= 'Z')//大寫轉小寫
				words[num][i] += 32;
			if (words[num][i] < 'a' || words[num][i] > 'z')
				for (int j = i; words[num][j] != '\0'; j++)//向左移，當不是小寫英文字母時
					words[num][j] = words[num][j + 1];
		}
		num++;
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < answer.size(); j++) {
			if (!strcmp(words[i], answer[j].word)) {
				answer[j].count++;
				break;
			}//曾經出現過則+1
			if (j == answer.size() - 1) {
				answer[answer.size() - 1].count = 1;
				strcpy_s(answer[answer.size() - 1].word, words[i]);
				answer.resize(answer.size() + 1);
				break;
			}//沒出現過的
		}
	}

	int max = 0;
	for (int i = 0; i < answer.size(); i++)//找出最多的出現次數
		if (answer[i].count > max) {
			max = answer[i].count;
		}

	ofstream ans("dict.dat", ios::out | ios::binary);
	for (int j = max; j > 0; j--)//從最多次數的開始輸出
		for (int i = 0; i < answer.size() - 1; i++)//輸出結果
			if (answer[i].count == j) {
				cout << answer[i].word << answer[i].count << endl;
				ans.write(reinterpret_cast<char*>(&answer[i]), sizeof(answer[i]));
			}
}

//讀dict檔
void dictload(vector< dictionary >& answer)
{
	ifstream dict("dict.dat", ios::in | ios::binary);
	if (!dict) {
		return;
	}
	else {
		dict.seekg(0, ios::end);
		int numLine = dict.tellg() / sizeof(dictionary);
		dict.seekg(0, ios::beg);
		for (int i = 0; i < numLine; i++) {
			answer.resize(numLine);
			dict.read(reinterpret_cast<char*>(&answer[i]), sizeof(answer[i]));
		}
		return;
	}
}