//將一個數字改成16進位
#include <iostream>

using namespace std;

void iterative(int number)
{
	int process = 1, answer = 0;
	for (int i = 1; number > process; i++) {
		process *= 16;
	}//加大process
	if (number % process != 0) {
		process /= 16;
	}//排除特例
	for (;process > 0; process /= 16) {
		answer = number / process;
		number %= process;//16進位運算轉換
		if (answer == 10)
			cout << 'A';
		else if (answer == 11)
			cout << 'B';
		else if (answer == 12)
			cout << 'C';
		else if (answer == 13)
			cout << 'D';
		else if (answer == 14)
			cout << 'E';
		else if (answer == 15)
			cout << 'F';
		else
			cout << answer;//條件句
	}
}

void recursive(int number, int process) {
	int answer = 0;
	if (process == 0)
		return;
	answer = number / process;
	number %= process;//16進位運算轉換
	process /= 16;
	if (answer == 10)
		cout << 'A';
	else if (answer == 11)
		cout << 'B';
	else if (answer == 12)
		cout << 'C';
	else if (answer == 13)
		cout << 'D';
	else if (answer == 14)
		cout << 'E';
	else if (answer == 15)
		cout << 'F';
	else
		cout << answer;//條件句
	recursive(number, process);
}

int main()
{
	int number, process = 1;
	cout << "請輸入一個介於0~32767的數字 : ";
	cin >> number;
	if (number > 32767 || number < 0) {
		cout << "你輸入的值是錯誤的。";
		return 0;
	}
	cout << endl;
	iterative(number);
	cout << endl << endl;
	for (int i = 1; number > process; i++)
		process *= 16;//加大process
	if (number % process != 0)
		process /= 16;//排除特例
	recursive(number, process);
	return 0;
}