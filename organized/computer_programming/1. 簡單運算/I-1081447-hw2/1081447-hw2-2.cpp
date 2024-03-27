#include <iostream>
using namespace std;
int main()
{
	int number , total = 0 , quotient;
	cout << "Enter a positive integer of at most 8 digits: ";
	cin >> number;
	cout << "\nThe sum of all digits of " << number << " is ";
	for (int i = 10000000; i >= 1; i /= 10)
	{	
		quotient = number / i;//找商數
		total = quotient + total;//將商數相加
		number -= quotient * i;//去掉已算出的部分
	}
	cout << total;
	system("pause");
}