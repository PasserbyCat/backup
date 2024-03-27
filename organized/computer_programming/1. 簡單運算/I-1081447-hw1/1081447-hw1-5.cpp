#include <iostream>
using namespace std;
int main()
{
	int x;
	cout << "Enter a year: ";
	cin >> x;
	if (x % 400 == 0)
	{
		cout << "Year " << x << " is a leap year." << endl;
	}
	if (x % 100 == 0 && x % 400 != 0)
	{
		cout << "Year " << x << " is a common year." << endl;
	}
	if (x % 4 == 0 && x % 100 != 0 && x % 400 != 0)
	{
		cout << "Year " << x << " is a leap year." << endl;
	}
	if (x % 4 != 0 && x % 100 != 0 && x % 400 != 0)
	{
		cout << "Year " << x << " is a common year." << endl;
	}
	system("pause");
	return 0;
}