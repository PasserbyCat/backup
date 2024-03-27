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
		return false;//�T�Osize1 = size2
	for (int i = size1 - 1; i >= 0; i--) {
		if (hugeInt1[i] != hugeInt2[i])
			return false;
	}//�Y���@�줣�۵��N���i��۵�
	return true;
}

// returns true if and only if hugeInt1 < hugeInt2
bool less(int hugeInt1[], int hugeInt2[], int size1, int size2)
{
	if (size2 > size1)
		return true;
	if (size2 < size1)
		return false;//����L�����
	for (int i = size2 - 1; i >= 0; i--)
	{
		if (hugeInt1[i] < hugeInt2[i])
			return true;
		if (hugeInt1[i] > hugeInt2[i])
			return false;
	}//�@��@���j�p
	return false;//��̬۵��N���Υ[�t��
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
	remainderSize = dividendSize;//�l�Ʀ�ƩM�Q���Ƥ@��
	for (int i = 0; i <= dividendSize - 1; i++) {
		remainder[i] = dividend[i];
	}//��Q���ƪ��ȼg�i�l�Ƹ̭�
	for (int i = 0; i < quotientSize; i++) {
		quotient[i] = 0;
	}//���N�ӼƳ]��0
	if (isZero(dividend, dividendSize)) {
		quotientSize = 1;
		quotient[0] = 0;
		remainder[0] = 0;
		return;
	}//�Y�Q���Ƭ�0�A������X�ӼƩM�l��
	if (equal(dividend, divisor, dividendSize, divisorSize)) {
		quotientSize = 1;
		quotient[0] = 1;
		remainderSize = 1;
		remainder[0] = 0;
		return;
	}//��Ƭ۵��ɡA������X��ӼƩM�l��
	if (dividendSize < divisorSize) {
		quotientSize = 1;
		quotient[0] = 0;
		for (int i = 0; i <= dividendSize - 1; i++) {
			remainder[i] = dividend[i];
		}
		return;
	}//�Y�Q���ƪ���Ƥp�󰣼ƪ���ƪ�����X�ӼƩM�l��
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
			}//�Y�Q���Ƥp�󰣼ơA������X�ӼƩM�l��
		}
	}
	quotientSize = dividendSize - divisorSize + 1;//�D�Ӽƪ�SIZE
	process = divisorSize;//�T�wdivisorSize����
	divisorSize = dividendSize;//�N�䩹�����ɥ������NdivisorSize�[�j
	for (int i = 1; i < quotientSize; i++) {
		for (int j = divisorSize - 1; j >= 0; j--) {
			divisor[j + 1] = divisor[j];
			divisor[j] = 0;
		}
	}//�ǻ�����������
	for (int i = divisorSize - 1; i >= 0; i++) {
		if (!less(divisor, dividend, divisorSize, dividendSize)) {
			divideBy10(divisor, divisorSize);
			quotientSize--;
			break;
		}
		if (less(divisor, dividend, divisorSize, dividendSize)) {
			break;
		}
	}//�T�w��������A���ƨ̵M�p��Q���ơA���M���k���@��
	int breaking = 0;//�Y���ݭn�������X�����ɳ]���ܼ�
	for (int i = quotientSize - 1; i >= 0; i--) {
		while (breaking == 0) {
			if (equal(remainder, divisor, remainderSize, divisorSize)) {
				remainderSize = 1;
				remainder[0] = 0;
				divisorSize = process;
				quotient[i]++;
				breaking++;
				break;
			}//�p�G���@�b�A�l�ƫ�굥�󰣼ƮɡA�ڭ����Ӫ����פ�{��
			else if (less(divisor, remainder, divisorSize, remainderSize)) {
				quotient[i]++;
				subtraction(remainder, divisor, remainder, remainderSize, divisorSize, remainderSize);
			}//�@�몺��k
			else {
				if (process == divisorSize) {
					breaking++;
					break;
				}//�קKdivisorSize���Ȥp��̪쪺�ȡA�y���ɮצs�������~
				divideBy10(divisor, divisorSize);
				break;
			}//��remainder���Ȥp��divisor���ȮɡA�Ndivisor�V�k��
		}
		if (breaking != 0) {
			break;
		}//�������X����������
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