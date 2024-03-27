//輸入一小一大兩個數，包括其本身和其範圍內的所有奇數相加，即為解
#include <iostream>
using namespace std;
int sum(int small, int big) {
	if (small == big) return small;
	else return sum(small, big - 2) + big;
}//遞迴關係式
int main() {
	int a = 0, b = 0, times;
	cin >> times;
	for (int i = 1; i <= times; i++) {
		cin >> a >> b;
		if (a % 2 == 0) {
			a++;
		}//確保a是奇數
		if (b % 2 == 0) {
			b--;
		}//確保b是奇數
		cout << "Case " << i << ": "<<sum(a, b) << endl;
	}
	return 0;
}
