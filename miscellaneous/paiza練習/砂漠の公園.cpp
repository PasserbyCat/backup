#include <iostream>
#include <string>
using namespace std;
int main() {
	int w[100] = {}, d[100] = {}, l[100] = {}, s, t[100] = {}, max = 0, maxnum;
	char ch[100][100];
	cin >> s;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
		cin >> ch[i][j];
		if (ch[i][j] == 'W') {
			t[i] += 2;
			w[i]++;
		}
		if (ch[i][j] == 'D') {
			t[i]++;
			d[i]++;
		}
		if (ch[i][j] == 'L') {
			l[i]++;
		}
		}
	}
	for (int i = 0; i < s; i++) {
		if (t[i] > max) {
			max = t[i];
			maxnum = i;
		}
	}
	cout << maxnum + 1 << " " << max << " " << w[maxnum] << " " << d[maxnum] << " " << l[maxnum] << " " << endl;
}