//��J�@�p�@�j��ӼơA�]�A�䥻���M��d�򤺪��Ҧ��_�Ƭۥ[�A�Y����
#include <iostream>
using namespace std;
int sum(int small, int big) {
	if (small == big) return small;
	else return sum(small, big - 2) + big;
}//���j���Y��
int main() {
	int a = 0, b = 0, times;
	cin >> times;
	for (int i = 1; i <= times; i++) {
		cin >> a >> b;
		if (a % 2 == 0) {
			a++;
		}//�T�Oa�O�_��
		if (b % 2 == 0) {
			b--;
		}//�T�Ob�O�_��
		cout << "Case " << i << ": "<<sum(a, b) << endl;
	}
	return 0;
}
