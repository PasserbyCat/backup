//程式考試input須知
#include <iostream>
using namespace std;
int main()
{
	long long int num1, num2, i, j, answer = 0, m = 0;
	int tnum1[1000] = {}, tnum2[1000] = {};
	cin >> num1 >> num2;
	while (num2 != 0 || num1 != 0) {
		//�ư��t��
		if (num2 < 0 || num1 < 0) {
			cout << "Invalid input." << endl;
			cin >> num1 >> num2;
		}
		else {
			//�N�Ʀr�ίx�}�@�Ӥ@�Ӧs�_��
			for (i = 0; ; i++) {
				if (num1 == 0) {
					break;
				}
				tnum1[i] = num1 % 10;
				num1 /= 10;
			}
			//�N�Ʀr�ίx�}�@�Ӥ@�Ӧs�_��
			for (j = 0; ; j++) {
				if (num2 == 0) {
					break;
				}
				tnum2[j] = num2 % 10;
				num2 /= 10;
			}
			//�קK��Ƥj��10
			if (i > 9 || j > 9) {
				cout << "Invalid input." << endl;
				cin >> num1 >> num2;
			}
			else {
				//���ƨ��X��
				if (i < j) {
				i = j;
				}
				//�@���@���P�_
				for (int k = 0; k < i; k++) {
					if (tnum1[k] + tnum2[k] >= 10) {
						tnum1[k + 1]++;
						answer++;
					}
					//��l��
					tnum1[k] = 0;
					tnum2[k] = 0;
				}
				//��X�P�_��
				if (answer == 0) {
					cout << "No carry operation." << endl;
				}
				else if (answer == 1) {
					cout << answer << " carry operation." << endl;
				}
				else {
					cout << answer << " carry operations." << endl;
				}
				answer = 0;
				cin >> num1 >> num2;
			}
		}
	}

}