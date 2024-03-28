//華氏溫度與攝氏溫度之轉換
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double ctof(double input);

double ftoc(double input);

int main()
{
	int x, lower, upper, difference;
	double second, process;
	cout << "1.Celsius to Fahrenheit " << endl << "2. Fahrenheit to Celsius " << endl;
	cin >> x;
	cout << "lower bond: ";
	cin >> lower;
	cout << "upper bond: ";
	cin >> upper;
	//difference��̪��t
	difference = upper - lower;
	//scecond��������
	second = difference / 2;
	cout << "Celsius" << setw(15) << "Fahrenheit" << setw(15) << "Celsius" << setw(15) << "Fahrenheit" << endl;
	//�����ؤ������������ؤ�
	if (x == 1) {
		for (double i = lower; i < upper - ceil(second); i++) {
			cout << setw(7) << setprecision(1) << fixed << i << setw(15) << ctof(i);
			process = i + ceil(second) + 1;
			cout << setw(15) << setprecision(1) << fixed << process << setw(15) << ctof(process) << endl;
		}
		if (difference % 2 == 0) {
			cout << setw(7) << setprecision(1) << fixed << upper - ceil(second) << setw(15) << ctof(upper - ceil(second));
		}//�Y�t�����ơA�W����FOR�j�餣�|��X�̫�@�ռ�
	}
	else if (x == 2) {
		for (double i = lower; i < upper - ceil(second); i++) {
			cout << setw(7) << setprecision(1) << fixed << i << setw(15) << ftoc(i);
			process = i + ceil(second) + 1;
			cout << setw(15) << setprecision(1) << fixed << process << setw(15) << ftoc(process) << endl;
		}
		if (difference % 2 == 0) {
			cout << setw(7) << setprecision(1) << fixed << upper - ceil(second) << setw(15) << ftoc(upper - ceil(second));
		}
	}
	//���b
	else {
		cout << "your's input is wrong.";
	}
}

double ctof(double input)
{
	double answer = 0;
	answer = input * 9 / 5 + 32;
	return answer;
}

double ftoc(double input)
{
	double answer = 0;
	answer = (input - 32) * 5 / 9;
	return answer;
}
