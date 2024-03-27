// Huge integer addition, subtraction and multiplication
#include <iostream>
#include <fstream>
using namespace std;

// enable user to input a positive huge integer
void input(istream& inFile, int hugeInt[], int& size);

// perform addition, subtraction and multiplication
void perform(ostream& outFile, int hugeInt1[], int hugeInt2[], int hugeInt3[],
	int size1, int size2, int size3);

// output the specified huge integer
void output(ostream& outFile, int hugeInt[], int size);

// returns true if and only if the specified huge integer is zero
bool isZero(int hugeInt[], int size);

// returns true if and only if hugeInt1 < hugeInt2
bool less(int hugeInt1[], int hugeInt2[], int size1, int size2);

// sum = addend + adder
void addition(int addend[], int adder[], int sum[], int addendSize, int adderSize, int& sumSize);

// difference = minuend - subtrahend
void subtraction(int minuend[], int subtrahend[], int difference[],
	int minuendSize, int subtrahendSize, int& differenceSize);

// product = multiplicand * multiplier
void multiplication(int multiplicand[], int multiplier[], int product[],
	int multiplicandSize, int multiplierSize, int& productSize);

const int numTestCases = 22; // the number of test cases
const int arraySize = 200;

int main()
{
	system("mode con cols=122");

	ifstream inFile("Test cases.txt", ios::in);

	// exit program if ofstream could not open file
	if (!inFile)
	{
		cout << "File could not be opened" << endl;
		system("pause");
		exit(1);
	}

	ofstream outFile("Result.txt", ios::out);

	// exit program if ofstream could not open file
	if (!outFile)
	{
		cout << "File could not be opened" << endl;
		system("pause");
		exit(1);
	}

	for (int i = 0; i < numTestCases; i++)
	{
		int hugeInt1[arraySize] = {};
		int hugeInt2[arraySize] = {};
		int hugeInt3[arraySize] = {};
		int size1 = 1;
		int size2 = 1;
		int size3 = 1;

		input(inFile, hugeInt1, size1);
		input(inFile, hugeInt2, size2);
		perform(cout, hugeInt1, hugeInt2, hugeInt3, size1, size2, size3);
		perform(outFile, hugeInt1, hugeInt2, hugeInt3, size1, size2, size3);
	}


	inFile.close();
	outFile.close();

	system("pause");
}

// enable user to input a positive huge integer
void input(istream& inFile, int hugeInt[], int& size)
{
	char numericString[arraySize];

	inFile >> numericString;

	size = strlen(numericString);
	for (int i = 0; i < size; ++i)
		hugeInt[i] = numericString[size - i - 1] - '0';
}

// perform addition, subtraction and multiplication
void perform(ostream& outFile, int hugeInt1[], int hugeInt2[], int hugeInt3[],
	int size1, int size2, int size3)
{
	output(outFile, hugeInt1, size1);
	output(outFile, hugeInt2, size2);

	// hugeInt3 = hugeInt1 + hugeInt2
	addition(hugeInt1, hugeInt2, hugeInt3, size1, size2, size3);
	output(outFile, hugeInt3, size3);

	// if hugeInt1 < hugeInt2
	if (::less(hugeInt1, hugeInt2, size1, size2))
	{
		outFile << '-';
		// hugeInt3 = hugeInt2 - hugeInt1
		subtraction(hugeInt2, hugeInt1, hugeInt3, size2, size1, size3);
		output(outFile, hugeInt3, size3);         // outputs n2 - n1
	}
	else
	{
		// hugeInt3 = hugeInt1 - hugeInt2
		subtraction(hugeInt1, hugeInt2, hugeInt3, size1, size2, size3);
		output(outFile, hugeInt3, size3);         // outputs n1 - n2
	}

	// hugeInt3 = hugeInt1 * hugeInt2
	multiplication(hugeInt1, hugeInt2, hugeInt3, size1, size2, size3);
	output(outFile, hugeInt3, size3);         // outputs n1 * n2

	outFile << endl;
}

// output the specified huge integer
void output(ostream& outFile, int hugeInt[], int size)
{
	if (isZero(hugeInt, size))
		outFile << 0;
	else
		for (int i = size - 1; i >= 0; i--)
			if (hugeInt[i] < 10)
				outFile << hugeInt[i];

	outFile << endl;
}

// returns true if and only if the specified huge integer is zero
bool isZero(int hugeInt[], int size)
{
	for (int i = 0; i < size; i++)
		if (hugeInt[i] != 0)
			return false;
	return true;
}

// returns true if and only if hugeInt1 < hugeInt2
bool less(int hugeInt1[], int hugeInt2[], int size1, int size2)
{
	if (size2 > size1)
		return true;
	if (size2 < size1)
		return false;
	for (int i = size2 - 1; i >= 0; i--)
	{
		if (hugeInt1[i] < hugeInt2[i])
			return true;
		if (hugeInt1[i] > hugeInt2[i])
			return false;
	}
	return false;
}

// sum = addend + adder
void addition(int addend[], int adder[], int sum[], int addendSize, int adderSize, int& sumSize)
{
	sumSize = (addendSize >= adderSize) ? addendSize + 1 : adderSize + 1;

	for (int i = 0; i < addendSize; i++)
		sum[i] = addend[i];

	for (int i = addendSize; i < sumSize; i++)
		sum[i] = 0;

	for (int i = 0; i < adderSize; i++)
		sum[i] += adder[i];

	for (int i = 0; i < sumSize - 1; i++)
		if (sum[i] > 9)
		{
			sum[i] -= 10;
			sum[i + 1]++;
		}

	if (sum[sumSize - 1] == 0)
		sumSize--;
}

// difference = minuend - subtrahend
void subtraction(int minuend[], int subtrahend[], int difference[],
	int minuendSize, int subtrahendSize, int& differenceSize)
{
	differenceSize = minuendSize;
	for (int i = 0; i < subtrahendSize; i++)
	{
		difference[i] = minuend[i] - subtrahend[i];
	}
	for (int i = subtrahendSize; i < minuendSize; i++)
	{
		difference[i] = minuend[i];
	}
	for (int i = 0; i < differenceSize; i++)
	{
		if (difference[i] < 0)
		{
			difference[i] += 10;
			difference[i + 1]--;
		}
	}
	for (int i = differenceSize; i > 0; i--) {
		if (difference[differenceSize - 1] == 0)
			differenceSize--;
		else
			break;
	}
}

// product = multiplicand * multiplier
void multiplication(int multiplicand[], int multiplier[], int product[],
	int multiplicandSize, int multiplierSize, int& productSize)
{
	productSize = multiplicandSize + multiplierSize;
	for (int i = 0; i < productSize; i++)
		product[i] = 0;
	for (int i = 0; i < multiplicandSize; i++)
	{
		for (int j = 0; j < multiplierSize; j++)
		{
			product[i + j] += multiplicand[i] * multiplier[j];
		}
	}
	for (int i = 0; i < productSize; i++)
	{
		if (product[i] > 9)
		{
			product[i + 1] += product[i] / 10;
			product[i] %= 10;
		}
	}
	for (int i = productSize; i > 0; i--) {
		if (product[productSize - 1] == 0)
			productSize--;
		else
			break;
	}
}