#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream fin;
    fin.open(argv[1]);
    char bitmap[2000];
    string word;
    int sum = 0;
    int j = 0;

    fin.read((char*)&bitmap, 2000);
    fin.close();

    for (int i = 54; i < 2000; i += 3) {
        sum *= 2;
        j++;
        if (bitmap[i] == 0) {
            sum += 1;
        }
        if (j == 8) {
            if (sum > 'z' || sum < 32 || word.size() > 72)
                break;
            else {
                word.push_back(sum);
                sum = 0;
                j = 0;
            }
        }
    }

    cout << word;
}
