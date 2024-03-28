//計算停車費
/*
兩小時內3元
之後每一小時加收0.6元
每天最多15元
*/
#include <iostream>
#include <iomanip>
using namespace std;
double calculateCharges(double hour)
{
	double charge = 0;
	int k = 0;
	if (hour <= 2) {
		charge = 3;
	}
	else if (hour > 22) {
		charge = 15;
	}
	else {
		while (k < hour) {
			k++;
		}
		charge = k - 2;
		charge *= 0.6;
		charge += 3;
	}
	return charge;
}

int main()
{
	double hour = 0, charge[5] = {}, hours[5] = {};
	for (int i = 1; i < 4; i++) {
		cin >> hour;
		hours[i] = hour;//�B�~�Τ@�ӯx�}�s�ɶ�
		if (hour > 24) {
			cout << "error";
			return 0;
		}//�Y�����ɶ��j��1�ѫh���X
		hours[4] += hour;
		charge[i] = calculateCharges(hour);//�N�B�⵲�G�Ǧ^
		charge[4] += charge[i];
	}
	cout << "Car" << setw(10) << "Hours" << setw(14) << "Charge" << endl;
	for (int i = 1; i < 4; i++) {
		cout << i <<setprecision(1) << fixed << setw(12) << hours[i] << setw(14) << setprecision(2) << fixed << charge[i] << endl;
	}
	cout << "TOATL" << setw(8) << setprecision(1) << fixed << hours[4] << setw(14) << setprecision(2) << fixed << charge[4] << endl;
}
