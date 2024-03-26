#include <iostream>

using namespace std;

void path(bool** table, int position, char* store, int times, int select);

bool equal(char* store, char s, int n);

int main()
{
	int position, road, times = 0;
	char select, position1, position2;
	cin >> position >> road >> select;
	bool** table = new bool* [position]();
	char* store = new char[position + 2]();
	for (int i = 0; i < position; i++) {
		*(table + i) = new bool[position]();
	}
	for (int i = 0; i < road; i++) {
		cin >> position1 >> position2;
		table[position1 - 'A'][position2 - 'A'] = 1;
		table[position2 - 'A'][position1 - 'A'] = 1;
	}
	store[0] = select;
	path(table, position, store, times + 1, select);
	for (int i = 0; i < position; i++) {
		delete[] * (table + i);
	}
	delete[] table;
}

void path(bool** table, int position, char* store, int times, int select)
{
	if (times == position)
	{
		int a = store[position - 1];
		int b = store[0];
		if (table[a - 'A'][b - 'A'])
		{
			for (int i = 0; i < position; ++i)
				cout << store[i];
			cout << store[0] << '\n';
		}
		return;
	}
	for (int j = 0; j < position; j++)
	{
		if (table[select - 'A'][j] == 1)
		{
			if (!equal(store, j + 'A', times))
			{
				store[times] = j + 'A';
				path(table, position, store, times + 1, j + 'A');
			}
		}
	}
}

bool equal(char* store, char select, int position)
{
	for (int i = 0; i < position; i++)
	{
		if (store[i] == select)
			return true;
	}
	return false;
}