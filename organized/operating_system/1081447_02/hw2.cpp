#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
string all;
int num;
vector <int> answer;
vector <string> input;
vector <int> length;
void *child (void *ptr) ;
struct pai {
	int start;
	int end;
	int in;
};
int main(int argc, char *argv[])
{	
	fstream inFile(argv[1], ios::in);
	inFile >> all >> num;
	string temp;
	while (inFile >> temp)
		input.push_back(temp);
	inFile.close();
	double START, END; START = clock();
	
	pthread_t thread1;
	pai data;
	for (int i = 0; i < input.size(); i++) {
		data.start = 0;
		int buffer = all.size() / num;
		data.end = data.start + buffer;
		data.in = i;
		for (int j = 0; j < num; j++) {
			pthread_create(&thread1, NULL, child, (void*)&data);
			pthread_join(thread1, NULL);
			data.start = data.end - input[i].size();
			data.end += buffer;
		}
		length.push_back(answer.size());
	}
	for (int i = 0; i < length.size(); i++) {
		cout << "[" << input[i] << "]";
		int j = (i == 0) ? 0 : length[i - 1];
		for (; j < length[i]; j++)
			cout << " " << answer[j];
		cout << endl;
	}
	END = clock();
	cout << "CPU time: " << (END - START) << " ms\n";
}
void *child (void *ptr) 
{
	pai *data = (pai *)ptr;
	cout << "[Tid=" << gettid() << "] search " << input[data->in] << " at "
		<< data->start << " ";
	for (int j = 0; j < 8; j++) {
		cout << all[data->start + j];
	}
	cout << endl;
	for (int i = data->start; i < data->end - input[data->in].size(); i++) {
		int k = 0;
		for (int j = 0; j + k < input[data->in].size(); j++) {
			if (input[data->in][j + k] == '?') {
				if(j + k == input[data->in].size() - 1)
					answer.push_back(i);
				continue;
			}
			if (input[data->in][j + k] == '{') {
				bool check = false;
				for (; input[data->in][j + k] != '}'; k++)
					if (all[i + j] == input[data->in][j + k])
						check = true;
				if (check) {
					if(j + k == input[data->in].size() - 1)
						answer.push_back(i);
					continue;
				}
			}
			
			if (all[i + j] != input[data->in][j + k])
				break;
			if(j + k == input[data->in].size() - 1)
				answer.push_back(i);
		}
	}
	return 0;
}
