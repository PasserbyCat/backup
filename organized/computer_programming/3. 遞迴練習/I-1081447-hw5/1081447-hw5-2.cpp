//�N�L���C�@��ƥ[�_�ӡA�Y���¤��O�Ӧ�ơA���ư���Ȩ�ȳѤU�Ӧ��
#include <iostream>
using namespace std;
int sum(int number) {
	if (number < 10) return number;
	else return sum(number % 10 + number / 10);
}//���j���Y��
int main() {
	int number = 0;
	cin >> number;
	for (int i = 0; number != 0; i++) {
		cout << sum(number);
		cin >> number;
	}
}
