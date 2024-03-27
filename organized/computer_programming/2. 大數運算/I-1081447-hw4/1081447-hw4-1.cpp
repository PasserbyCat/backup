// Huge integer addition, subtraction, multiplication and division
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::ios;

// enable user to input a positive huge integer
void input(istream& inFile, int hugeInt[], int& size);

// perform addition, subtraction, multiplication and division
void perform(ostream& outFile, int hugeInt1[], int hugeInt2[], int hugeInt3[],
	int hugeInt4[], int size1, int size2, int size3, int size4);

// output the specified huge integer
void output(ostream& outFile, int hugeInt[], int size);

// returns true if and only if the specified huge integer is zero
bool isZero(int hugeInt[], int size);

// return true if and only if hugeInt1 == hugeInt2
bool equal(int hugeInt1[], int hugeInt2[], int size1, int size2);

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

// quotient = dividend / divisor; remainder = dividend % divisor
void division(int dividend[], int divisor[], int quotient[], int remainder[],
	int dividendSize, int divisorSize, int& quotientSize, int& remainderSize);

// hugeInt /= 10
void divideBy10(int hugeInt[], int& size);

const int numTestCases = 22; // the number of test cases
const int arraySize = 200;

int main()
{
	system("mode con cols=122");

	ifstream inFile("Test cases.txt", ios::in);

	// exit program if ifstream could not open file
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
		int hugeInt4[arraySize] = {};
		int size1 = 1;
		int size2 = 1;
		int size3 = 1;
		int size4 = 1;

		input(inFile, hugeInt1, size1);
		input(inFile, hugeInt2, size2);
		perform(cout, hugeInt1, hugeInt2, hugeInt3, hugeInt4, size1, size2, size3, size4);
		perform(outFile, hugeInt1, hugeInt2, hugeInt3, hugeInt4, size1, size2, size3, size4);
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

// perform addition, subtraction, multiplication and division
void perform(ostream& outFile, int hugeInt1[], int hugeInt2[], int hugeInt3[],
	int hugeInt4[], int size1, int size2, int size3, int size4)
{
	output(outFile, hugeInt1, size1);
	output(outFile, hugeInt2, size2);

	// hugeInt3 = hugeInt1 + hugeInt2
	addition(hugeInt1, hugeInt2, hugeInt3, size1, size2, size3);
	output(outFile, hugeInt3, size3);

	// if hugeInt1 < hugeInt2
	if (less(hugeInt1, hugeInt2, size1, size2))
	{
		outFile << '-';
		// hugeInt3 = hugeInt2 - hugeInt1
		subtraction(hugeInt2, hugeInt1, hugeInt3, size2, size1, size3);
		output(outFile, hugeInt3, size3); // outputs n2 - n1
	}
	else
	{
		// hugeInt3 = hugeInt1 - hugeInt2
		subtraction(hugeInt1, hugeInt2, hugeInt3, size1, size2, size3);
		output(outFile, hugeInt3, size3); // outputs n1 - n2
	}

	// hugeInt3 = hugeInt1 * hugeInt2
	multiplication(hugeInt1, hugeInt2, hugeInt3, size1, size2, size3);
	output(outFile, hugeInt3, size3); // outputs n1 * n2

	if (isZero(hugeInt2, size2))
	{
		outFile << "DivideByZero!\n";
		outFile << "DivideByZero!\n";
	}
	else
	{
		division(hugeInt1, hugeInt2, hugeInt3, hugeInt4, size1, size2, size3, size4);
		output(outFile, hugeInt3, size3);         // outputs n1 / n2
		output(outFile, hugeInt4, size4);         // outputs n1 % n2
	}

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

// return true if and only if hugeInt1 == hugeInt2
bool equal(int hugeInt1[], int hugeInt2[], int size1, int size2)
{
	if (size1 > size2)
		return false;
	if (size1 < size2)
		return false;//確保size1 = size2
	for (int i = size1 - 1; i >= 0; i--) {
		if (hugeInt1[i] != hugeInt2[i])
			return false;
	}//若有一位不相等就不可能相等
	return true;
}

// returns true if and only if hugeInt1 < hugeInt2
bool less(int hugeInt1[], int hugeInt2[], int size1, int size2)
{
	if (size2 > size1)
		return true;
	if (size2 < size1)
		return false;//先比他的位數
	for (int i = size2 - 1; i >= 0; i--)
	{
		if (hugeInt1[i] < hugeInt2[i])
			return true;
		if (hugeInt1[i] > hugeInt2[i])
			return false;
	}//一位一位比大小
	return false;//兩者相等就不用加負號
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
		if (sum[i] > 9) // carrying
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

// quotient = dividend / divisor; remainder = dividend % divisor
void division(int dividend[], int divisor[], int quotient[], int remainder[],
	int dividendSize, int divisorSize, int& quotientSize, int& remainderSize)
{
	int process = 0, digit = 0;
	remainderSize = dividendSize;//餘數位數和被除數一樣
	for (int i = 0; i <= dividendSize - 1; i++) {
		remainder[i] = dividend[i];
	}//把被除數的值寫進餘數裡面
	for (int i = 0; i < quotientSize; i++) {
		quotient[i] = 0;
	}//先將商數設為0
	if (isZero(dividend, dividendSize)) {
		quotientSize = 1;
		quotient[0] = 0;
		remainder[0] = 0;
		return;
	}//若被除數為0，直接輸出商數和餘數
	if (equal(dividend, divisor, dividendSize, divisorSize)) {
		quotientSize = 1;
		quotient[0] = 1;
		remainderSize = 1;
		remainder[0] = 0;
		return;
	}//兩數相等時，直接輸出其商數和餘數
	if (dividendSize < divisorSize) {
		quotientSize = 1;
		quotient[0] = 0;
		for (int i = 0; i <= dividendSize - 1; i++) {
			remainder[i] = dividend[i];
		}
		return;
	}//若被除數的位數小於除數的位數直接輸出商數和餘數
	if (dividendSize == divisorSize) {
		for (int i = dividendSize - 1; i >= 0; i--) {
			if (less(divisor, dividend, divisorSize, dividendSize)) {
				break;
			}
			if (!(less(divisor, dividend, divisorSize, dividendSize))) {
				quotientSize = 1;
				quotient[0] = 0;
				for (int i = 0; i <= dividendSize - 1; i++) {
					remainder[i] = dividend[i];
				}
				return;
			}//若被除數小於除數，直接輸出商數和餘數
		}
	}
	quotientSize = dividendSize - divisorSize + 1;//求商數的SIZE
	process = divisorSize;//固定divisorSize的值
	divisorSize = dividendSize;//將其往左移時必須先將divisorSize加大
	for (int i = 1; i < quotientSize; i++) {
		for (int j = divisorSize - 1; j >= 0; j--) {
			divisor[j + 1] = divisor[j];
			divisor[j] = 0;
		}
	}//傳說中的往左移
	for (int i = divisorSize - 1; i >= 0; i++) {
		if (!less(divisor, dividend, divisorSize, dividendSize)) {
			divideBy10(divisor, divisorSize);
			quotientSize--;
			break;
		}
		if (less(divisor, dividend, divisorSize, dividendSize)) {
			break;
		}
	}//確定往左移後，除數依然小於被除數，不然往右移一格
	int breaking = 0;//若有需要提早跳出視窗時設的變數
	for (int i = quotientSize - 1; i >= 0; i--) {
		while (breaking == 0) {
			if (equal(remainder, divisor, remainderSize, divisorSize)) {
				remainderSize = 1;
				remainder[0] = 0;
				divisorSize = process;
				quotient[i]++;
				breaking++;
				break;
			}//如果減到一半，餘數恰恰等於除數時，我們應該直接終止程式
			else if (less(divisor, remainder, divisorSize, remainderSize)) {
				quotient[i]++;
				subtraction(remainder, divisor, remainder, remainderSize, divisorSize, remainderSize);
			}//一般的減法
			else {
				if (process == divisorSize) {
					breaking++;
					break;
				}//避免divisorSize的值小於最初的值，造成檔案存取的錯誤
				divideBy10(divisor, divisorSize);
				break;
			}//當remainder的值小於divisor的值時，將divisor向右移
		}
		if (breaking != 0) {
			break;
		}//提早跳出視窗的應用
	}
}

// hugeInt /= 10
void divideBy10(int hugeInt[], int& size)
{
	if (size == 1)
		hugeInt[0] = 0;
	else
	{
		for (int i = 1; i < size; i++)
			hugeInt[i - 1] = hugeInt[i];

		size--;
		hugeInt[size] = 0;
	}
}