#include <iostream>
using namespace std;
int main()
{
	int x;
	
	cout << "Enter an integer : ";
	cin >> x;
	if (x % 2 == 1)
	{
		cout << "The integer " << x << " is odd." << endl;
	}
	if (x % 2 == 0)
	{
		cout << "The integer " << x << " is even." << endl;
	}
	system("pause");
}