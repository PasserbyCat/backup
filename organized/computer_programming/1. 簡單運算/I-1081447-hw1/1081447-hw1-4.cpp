#include <iostream>
using namespace std;
int main()
{
	int a, b, c, m, n, o;
	cout << "Enter side 1: ";
	cin >> a;
	cout << "\nEnter side 2: ";
	cin >> b;
	cout << "\nEnter side 3: ";
	cin >> c;
	cout << endl;
	if (a >= b && a >= c)
	{
		m = a;
		n = b;
		o = c;
	}
	if (b >= a && b >= c)
	{
		m = b;
		n = a;
		o = c;
	}
	if (c >= b && c >= a)
	{
		m = c;
		n = b;
		o = a;
	}
	if (m*m==n*n+o*o)
	{
		cout << "These are the sides of a right triangle.";
	}
	else
	{
		cout << "These do not form a right triangle." << endl;	
	}
	system("pause");
	return 0;
}