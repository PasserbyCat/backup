//�N�L���C�@��ƥ[�_�ӡA�Y���¤��O�Ӧ�ơA���ư���Ȩ�ȳѤU�Ӧ��
#include <iostream>
using namespace std;
int GCD(int divisor, int dividend, int process) {
	if (dividend % divisor == 0 && process % divisor == 0) {
		return divisor;
	}//�T�O�D�X�Ӫ��ȦP�ɬ����ƩM�Q���ƪ��]��
	else {
		return GCD(divisor - 1, dividend, process);
	}
}//���j���Y��
int main() {
	int number = 0, answer = 0;
	cin >> number;
	while (number != 0) {//�D�حn�D��J��0�ɵ����{��
		answer = 0;
		for (int divisor = 1; divisor < number; divisor++)
			for (int dividend = divisor + 1; dividend <= number; dividend++)
			{
				answer += GCD(divisor, dividend, divisor);
			}//�̷��D�حn�D
		cout << answer << endl;
		cin >> number;
	}
}
