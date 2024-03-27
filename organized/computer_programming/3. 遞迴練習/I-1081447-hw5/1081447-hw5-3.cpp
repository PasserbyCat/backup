//將他的每一位數加起來，若仍舊不是個位數，重複執行值到僅剩下個位數
#include <iostream>
using namespace std;
int GCD(int divisor, int dividend, int process) {
	if (dividend % divisor == 0 && process % divisor == 0) {
		return divisor;
	}//確保求出來的值同時為除數和被除數的因數
	else {
		return GCD(divisor - 1, dividend, process);
	}
}//遞迴關係式
int main() {
	int number = 0, answer = 0;
	cin >> number;
	while (number != 0) {//題目要求輸入為0時結束程式
		answer = 0;
		for (int divisor = 1; divisor < number; divisor++)
			for (int dividend = divisor + 1; dividend <= number; dividend++)
			{
				answer += GCD(divisor, dividend, divisor);
			}//依照題目要求
		cout << answer << endl;
		cin >> number;
	}
}
