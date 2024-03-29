#include <iostream>
#include <time.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <mutex>
#include <string.h>

using namespace std;

void* child(void* ptr);
void* robot(void* ptr);
int hour = 9, min = 10, sec = 0, finish = 0;
queue<int>seet;

int main(int argc, char* argv[])
{
	int seed = 0, student = 0;
	for (int i = 0; i < strlen(argv[1]); i++) {
		student *= 10;
		student += argv[1][i] - '0';
	}
	if (student < 10 || student > 20) {
		cerr << "student number is error.\n";
		return 0;
	}
	for (int i = 0; i < strlen(argv[2]); i++) {
		seed *= 10;
		seed += argv[2][i] - '0';
	}
	if (seed < 0 || seed > 100) {
		cerr << "seed number is error.\n";
		return 0;
	}

	srand(seed);

	pthread_t tid[21];
	void* data;
	pthread_create(&tid[20], NULL, robot, (void*)&data);
	for (int i = 0; i < student; i++) {
		pthread_create(&tid[i], NULL, child, (void*)&data);
		pthread_join(tid[i], NULL);
	}
	//cout << seed << "\t" << student << "\n";
}

void* robot(void* ptr)
{

}

void* child(void* ptr)
{

}