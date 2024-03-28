//week15 Creating and using Libraries in C++
#include "pch.h"
#include "Header.h"


void man()// arg[0] //program name, arg[1] // test1.txt
{
	vector< dictionary > temp, answer;
	answer.resize(1);//�]size��1
	temp.resize(0);
	bool breaking = false;

	char words[100];
	int num = 0;
	prepositionsload(temp);

	ifstream test("IHaveADream.txt", ios::in);
	while (test) {
		test >> words;//Ū�r��
		for (int i = 0; words[i] != '\0'; i++) {
			if (words[i] >= 'A' && words[i] <= 'Z')
				words[i] += 32;
			if (words[i] < 'a' || words[i] > 'z')
				for (int j = i; words[j] != '\0'; j++) {
					words[j] = words[j + 1];
				}
		}
		for (int j = 0; j < temp.size(); j++) {
			if (!strcmp(words, temp[j].word)) {
				breaking = true;
				break;
			}
		}
		if (breaking == false)
			for (int j = 0; j < answer.size(); j++) {
				if (!strcmp(words, answer[j].word)) {
					answer[j].count++;
					break;
				}
				if (j == answer.size() - 1) {
					answer[answer.size() - 1].count = 1;
					strcpy_s(answer[answer.size() - 1].word, words);
					answer.resize(answer.size() + 1);
					break;
				}
			}
		breaking = false;
	}

	int max = 0;
	for (int i = 0; i < answer.size(); i++)
		if (answer[i].count > max) {
			max = answer[i].count;
		}

	ofstream ans("IHaveADream-wc.txt", ios::out);
	for (int j = max; j > 0; j--)
		for (int i = 0; i < answer.size() - 1; i++)
			if (answer[i].count == j) {
				cout << answer[i].word << answer[i].count << endl;
				ans << answer[i].word << answer[i].count << endl;
			}
}

void prepositionsload(vector< dictionary >& temp)
{
	ifstream prepositions("prepositions.txt", ios::in);
	while (prepositions) {
		temp.resize(temp.size() + 1);
		prepositions >> temp[temp.size() - 1].word;
	}
}