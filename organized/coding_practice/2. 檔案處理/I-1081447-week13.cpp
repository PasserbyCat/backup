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
	answer.resize(1);//�]size��1

	char words[1000][1000];
	int num = 0;
	dictload(answer);

	ifstream test(argv[1], ios::in);
	while (test) {
		test >> words[num];//Ū�r��
		for (int i = 0; words[num][i] != '\0'; i++) {
			if (words[num][i] >= 'A' && words[num][i] <= 'Z')//�j�g��p�g
				words[num][i] += 32;
			if (words[num][i] < 'a' || words[num][i] > 'z')
				for (int j = i; words[num][j] != '\0'; j++)//�V�����A���O�p�g�^��r����
					words[num][j] = words[num][j + 1];
		}
		num++;
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < answer.size(); j++) {
			if (!strcmp(words[i], answer[j].word)) {
				answer[j].count++;
				break;
			}//���g�X�{�L�h+1
			if (j == answer.size() - 1) {
				answer[answer.size() - 1].count = 1;
				strcpy_s(answer[answer.size() - 1].word, words[i]);
				answer.resize(answer.size() + 1);
				break;
			}//�S�X�{�L��
		}
	}

	int max = 0;
	for (int i = 0; i < answer.size(); i++)//��X�̦h���X�{����
		if (answer[i].count > max) {
			max = answer[i].count;
		}

	ofstream ans("dict.dat", ios::out | ios::binary);
	for (int j = max; j > 0; j--)//�q�̦h���ƪ��}�l��X
		for (int i = 0; i < answer.size() - 1; i++)//��X���G
			if (answer[i].count == j) {
				cout << answer[i].word << answer[i].count << endl;
				ans.write(reinterpret_cast<char*>(&answer[i]), sizeof(answer[i]));
			}
}

//Ūdict��
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