#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const int N = 10000;
const float PI = 3.14159;

inline void swap(float& a, float& b)
{
    float t;
    t = a;
    a = b;
    b = t;
}

void bitrp(float xreal[], float ximag[], int n)
{
    int i, j, a, b, p;

    for (i = 1, p = 0; i < n; i *= 2)
    {
        p++;
    }
    for (i = 0; i < n; i++)
    {
        a = i;
        b = 0;
        for (j = 0; j < p; j++)
        {
            b = (b << 1) + (a & 1);     // b = b * 2 + a % 2;
            a >>= 1;         // a = a / 2;
        }
        if (b > i)
        {
            swap(xreal[i], xreal[b]);
            swap(ximag[i], ximag[b]);
        }
    }
}

void FFT(float xreal[], float ximag[], int n)
{
    float wreal[N / 2], wimag[N / 2], treal, timag, ureal, uimag, arg;
    int m, k, j, t, index1, index2;

    bitrp(xreal, ximag, n);

    arg = -2 * PI / n;
    treal = cos(arg);
    timag = sin(arg);
    wreal[0] = 1.0;
    wimag[0] = 0.0;
    for (j = 1; j < n / 2; j++)
    {
        wreal[j] = wreal[j - 1] * treal - wimag[j - 1] * timag;
        wimag[j] = wreal[j - 1] * timag + wimag[j - 1] * treal;
    }

    for (m = 2; m <= n; m *= 2)
    {
        for (k = 0; k < n; k += m)
        {
            for (j = 0; j < m / 2; j++)
            {
                index1 = k + j;
                index2 = index1 + m / 2;
                t = n * j / m;
                treal = wreal[t] * xreal[index2] - wimag[t] * ximag[index2];
                timag = wreal[t] * ximag[index2] + wimag[t] * xreal[index2];
                ureal = xreal[index1];
                uimag = ximag[index1];
                xreal[index1] = ureal + treal;
                ximag[index1] = uimag + timag;
                xreal[index2] = ureal - treal;
                ximag[index2] = uimag - timag;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    ifstream fin;
    string all;
    fin.open("ex2.csv");

    stringstream ss;
    float xreal[N] = {}, ximag[N] = {};
    int n = 0, i, data = 0;;

    while (getline(fin, all)) {
        data++;
        for (i = 0; all.size(); i++) {
            if (i == all.size()) {
                string temp(all, 0, i);
                ss << temp;
                ss >> xreal[n];
                n++;
                i = 0;
                ss.clear();
                break;
            }
            else if (all[i] == ',') {
                string temp(all, 0, i);
                all.erase(0, i + 1);
                ss << temp;
                ss >> xreal[n];
                n++;
                i = 0;
                ss.clear();
            }
        }
        FFT(xreal, ximag, n);
        cout << "Data " << data << ":\n";
        for (int i = 0; i < n; i++) {
            cout << fixed << setprecision(4) << xreal[i] << " " << ximag[i] << endl;
            xreal[i] = 0;
            ximag[i] = 0;
        }
        n = 0;
        cout << endl;
        all.resize(0);
    }
}