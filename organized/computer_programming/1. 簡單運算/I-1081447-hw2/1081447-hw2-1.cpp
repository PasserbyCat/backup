#include <iostream>
using namespace std;
int main()
{
	int numbertrue, number, process = 0, quotient = 0;
	cout << "Enter a positive decimal integer of at most 8 digits: ";
	cin >> number;
	numbertrue = number;//確保輸入的值不被移除
	cout << "\nThe binary equivalent of " << number << " is ";
	for (int i = 1; i <= number; i *= 2)
		process = i;//讓process的值為最接近number但不大於他的2的次方倍
	for (process; process > 0; process /= 2)
	{
		if (number / process == 0)
			cout << "0";
		else
		{
			cout << "1";
			number -= process;
		}
	}//寫出二進位的值
	number = numbertrue;
	for (int i = 1; i <= number; i *= 8)
		process = i;//讓process的值為最接近number但不大於他的8的次方倍
	cout << "\nThe octal equivalent of " << number << " is ";
	for (process; process > 0; process /= 8)
	{
		quotient = number / process;
		cout << quotient;
		number = number - quotient * process;
	}//寫出八進位的值
	cout << endl;
	system("pause");
}