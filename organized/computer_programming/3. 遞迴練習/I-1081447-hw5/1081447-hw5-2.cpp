//將他的每一位數加起來，若仍舊不是個位數，重複執行值到僅剩下個位數
#include <iostream>
using namespace std;
int sum(int number) {
	if (number < 10) return number;
	else return sum(number % 10 + number / 10);
}//遞迴關係式
int main() {
	int number = 0;
	cin >> number;
	for (int i = 0; number != 0; i++) {
		cout << sum(number);
		cin >> number;
	}
}
