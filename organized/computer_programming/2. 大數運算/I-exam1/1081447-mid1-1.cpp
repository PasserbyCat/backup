#include <iostream>  
using namespace std;

long long a, b, c, d;

// a recursive function that returns the number of function values
// f(0), f(1), ..., f(L) divisible by d, where f(i) = a * i * i + b * i + c.
// Note that there cannot be loops in this function
int answer( long long L )
{
	if (L < 0) {
		return 0;
	}
	long long function = 0;
	function = a * L * L + b * L + c;
	if (function % d == 0) {
		return 1 + answer(L - 1);
	}
	else
		return answer(L - 1);
}

int main()
{
   long long L;
   cin >> a >> b >> c >> d >> L;
   while (a != 0 || b != 0 || c != 0 || d != 0 || L != 0) {
	   cout << answer(L) << endl;
	   cin >> a >> b >> c >> d >> L;
   }
}