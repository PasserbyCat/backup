#include <iostream>
using namespace std;
int main()
{
	int x, a, b, c, d, e;
	cout << "Enter a 5-digit number: ";
	cin >> x;
	a = x / 10000;
	b = x % 10000 / 1000;
	c = x % 1000 / 100;
	d = x % 100 / 10;
	e = x % 10;
	if (a == e && b == d)
	{
		cout << x << " is a palindrome!!!" << endl;
	}
	else
	{
		cout << x << " is not a palindrome!!!" << endl;
	}
	system("pause");
}