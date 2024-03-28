//輸入每日銷售額，輸出以符號製成的bar graph
#include <iostream>
using namespace std;
int main()
{
	int pencil[1000] = { 0 }, ballpoint[1000] = { 0 }, sum[1000] = { 0 };
	for (int i = 0; i < 4; i++) {
		cin >> pencil[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> ballpoint[i];
		sum[i] = ballpoint[i] + pencil[i];
		if (sum[i] > 5) {
			cout << " the validity of total daily sales is wrong ";
			return 0;
		}
	}
	for (int j = 5; j > 0; j--) {
		for (int i = 0; i < 4; i++) {
			if (sum[i] < j) {
				cout << "  ";
			}
			else if (ballpoint[i] >= j) {
				cout << "+ ";
			}
			else {
				cout << "* ";
			}
		}
		cout << endl;
	}
	cout << "1 2 3 4";
}