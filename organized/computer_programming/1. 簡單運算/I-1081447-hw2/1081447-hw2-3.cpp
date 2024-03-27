#include <iostream>
using namespace std;
int main()
{
	
	cout << "all Armstrong numbers of three digits:\n";
	int number, hundred, ten, one, total;
	for (number = 100; number < 1000; number++)
	{
		hundred = number / 100;
		ten = (number - 100 * hundred) / 10;
		one = number % 10;//將三位數各自找出來
		total = hundred * hundred * hundred + ten * ten * ten + one * one * one;
		if (total == number)
		{
			cout << number << "   ";
		}
	}
	cout << endl;
	system("pause");
}