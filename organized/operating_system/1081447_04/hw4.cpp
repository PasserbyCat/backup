#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<int>compute;
vector<int>ava;
vector<vector<int>>Max;
vector<vector<int>>allocation;
vector<vector<int>>need;
vector<vector<int>>request;
vector<int>work;

void print()
{
	cout << "(";
	for (int i = 0; i < request[0].size() - 1; i++) {
		if (i != 0) cout << ", ";
		cout << request[0][i];
	}
	cout << "): ";
}

bool testneed(int j = -1)
{
	if (j == -1) {
		print();
		for (int i = 0; i < ava.size(); i++)
			if (need[request[0][0]][i] > request[0][i + 1]) return false;
	}
	else {
		for (int i = 0; i < ava.size(); i++)
			if (need[j][i] > work[i]) return false;
	}
	return true;
}

bool testava()
{
	print();
	for (int i = 0; i < ava.size(); i++)
		if (ava[i] < request[0][i + 1]) return false;
	return true;
}

bool testsafe()
{
	vector<bool>finish(ava.size(), false);
	vector<int>sequence;
	work = ava;

	print();
	cout << "WORK= (";
	for (int i = 0; i < ava.size(); i++) {
		if (i != 0) cout << ", ";
		work[i] = ava[i] - request[0][i + 1];
		cout << work[i];
	}
	cout << ")\n";

	for (int j = 0; j < allocation.size(); j++) {
		for (int i = 0; i < need.size(); i++) {
			if (finish[i] == true) continue;
			if (testneed(i)) {
				finish[i] = true;
				sequence.push_back(i);
				for (int k = 0; k < ava.size(); k++)
					work[k] += need[i][k];
				print();
				cout << "gid " << i << " finish, WORK= (";
				for (int k = 0; k < ava.size(); k++) {
					if (k != 0) cout << ", ";
					work[k] += allocation[i][k];
					cout << work[k];
				}
				cout << ")\n";
				break;
			}
		}
	}
	for (int i = 0; i < finish.size(); i++) {
		if (!finish[i]) return false;
	}
	print();
	cout << "request granted, safe sequence = [";
	for (int i = 0; i < sequence.size(); i++) {
		if (i != 0)
			cout << ",";
		cout << sequence[i];
	}
	cout << "]\n";
	return true;
}

bool testrelease()
{
	print();
	for (int i = 0; i < ava.size(); i++)
		if (allocation[request[0][0]][i] < request[0][i + 1]) return false;
	for (int i = 0; i < ava.size(); i++) {
		allocation[request[0][0]][i] -= request[0][i + 1];
		ava[i] += request[0][i + 1];
	}
	return true;
}

void trans(string temp, int start = 0)
{
	compute.resize(0);
	int alu = 0;
	for (int i = start; i < temp.size(); i++) {
		if (temp[i] != ' ') {
			alu *= 10;
			alu += temp[i] - '0';
		}
		if (temp[i] == ' ') {
			compute.push_back(alu);
			alu = 0;
		}
	}
	compute.push_back(alu);
	return;
}

int main(int argc, char* argv[])
{
	fstream inFile(argv[1], ios::in);
	string temp;
	bool state = true;

	getline(inFile, temp);
	getline(inFile, temp);
	trans(temp, 0);
	ava = compute;

	getline(inFile, temp);
	getline(inFile, temp);
	for (int i = 0; temp != "#ALLOCATION"; i++) {
		if (i >= 10)
			trans(temp, 3);
		else
			trans(temp, 2);
		Max.push_back(compute);
		getline(inFile, temp);
	}

	getline(inFile, temp);
	for (int i = 0; temp != "#REQUEST"; i++) {
		if (i >= 10)
			trans(temp, 3);
		else
			trans(temp, 2);
		allocation.push_back(compute);
		getline(inFile, temp);
	}

	for (int i = 0; i < allocation.size(); i++) {
		compute.resize(0);
		for (int j = 0; j < Max[i].size(); j++) {
			compute.push_back(Max[i][j] - allocation[i][j]);
		}
		need.push_back(compute);
	}

	vector<bool>finish(ava.size(), false);
	vector<int>sequence;
	work = ava;
	for (int j = 0; j < allocation.size(); j++) {
		for (int i = 0; i < need.size(); i++) {
			if (finish[i] == true) continue;
			if (testneed(i)) {
				finish[i] = true;
				sequence.push_back(i);
				for (int k = 0; k < ava.size(); k++)
					work[k] += need[i][k];
				for (int k = 0; k < ava.size(); k++)
					work[k] += allocation[i][k];
				break;
			}
		}
	}
	for (int i = 0; i < finish.size(); i++) {
		if (!finish[i]) state = false;
	}
	cout << "Initial state: ";
	if (state) {
		cout << "safe, safe sequence = [";
		for (int i = 0; i < sequence.size(); i++) {
			if (i != 0)
				cout << ",";
			cout << sequence[i];
		}
		cout << "]\n";
	}
	else {
		cout << "unsafe\n";
	}

	while (getline(inFile, temp)) {
		trans(temp, 0);
		request.push_back(compute);
	}

	while (request.size() != 0) {
		if (request[0][compute.size() - 1] == 49) {//a

			if (testneed()) cout << "NEED OK\n";
			else {
				cout << "NEED error, request aborted\n";
				request.erase(request.begin());
				continue;
			}

			if (testava()) cout << "AVAILABLE OK\n";
			else {
				cout << "AVAILABLE error, request skip\n";
				request.push_back(request[0]);
				request.erase(request.begin());
				continue;
			}

			if (testsafe()) {
				for (int i = 0; i < ava.size(); i++) {
					ava[i] -= request[0][i + 1];
					allocation[request[0][0]][i] += request[0][i + 1];
					allocation[request[0][0]][i] -= request[0][i + 1];
				}
			}
			else {
				print();
				cout << "unsafe state, request skip\n";
				request.push_back(request[0]);
			}
		}
		else if (compute[compute.size() - 1] == 66) {//r
			if (testrelease()) {
				cout << "RELEASE granted, AVAILABLE=(";
				for (int i = 0; i < ava.size(); i++) {
					if (i != 0) cout << ",";
					cout << ava[i];
				}
				cout << ")\n";
			}
			else {
				cout << "RELEASE error, request skip";
				request.push_back(request[0]);
			}
		}
		request.erase(request.begin());
	}
}