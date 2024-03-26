#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int number, baselen, wordlen, replace, breaking = 0;
	cin >> number;
	char base[10001], word[101];
	cin >> base;
	for (int i = 0; i < number - 1; i++) {
		cin >> word;
		baselen = strlen(base);
		wordlen = strlen(word);
		replace = baselen;
		for (int j = baselen - wordlen, k = 0; j < baselen; j++, k++) {
			if (j < 0) {
				k = 0 - j;
				j = 0;
			}
			for (int l = 0; l < wordlen - k; l++) {
				if (word[l] != base[j + l]) {
					replace = baselen;
					break;
				}
				if (l == wordlen - k - 1) {
					breaking++;
				}
				replace--;
			}
			if (breaking != 0) {
				breaking = 0;
				break;
			}
		}
		base[replace] = '\0';
		strcat(base, word);
	}
	cout << base << endl;
}
