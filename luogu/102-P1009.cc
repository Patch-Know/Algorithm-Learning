#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int Max = 10000;

void add(int a1[], int a2[], int a3[], int &l1, int &l2, int &l3)
{
    l3 = l1 > l2 ? l1 : l2;
    for (int i = 0; i < l3; i++)
    {
        a3[i] = a1[i] + a2[i];
    }
    for (int i = 0; i < l3; i++)
    {
        if (a3[i] > 9)
        {
            a3[i + 1] += a3[i] / 10;
            a3[i] %= 10;
        }
    }
    if (a3[l3] != 0)
        l3++;
}

void multiply(int a1[], int a2[], int a3[], int &l1, int &l2, int &l3)
{
    l3 = l1 + l2;
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            a3[i + j] += a1[i] * a2[j];
        }
    }
    for (int i = 0; i < l3 - 1; i++)
    {
        if (a3[i] > 9)
        {
            a3[i + 1] += a3[i] / 10;
            a3[i] %= 10;
        }
    }
    while (a3[l3 - 1] == 0)
        l3--;
}

int main()
{
    int sum[Max]{0}, ls = 0;
    int add_1[Max]{1}, la = 1;
    int cnt[Max]{1}, lc = 1;
    int mul[Max]{0}, lm = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp0[Max]{0}, lt0 = 0;
        add(mul, add_1, temp0, lm, la, lt0);
        lm = lt0;
        for (int i = 0; i < lt0; i++)
        {
            mul[i] = temp0[i];
        }
        int temp1[Max]{0}, lt1 = 0;
        multiply(cnt, mul, temp1, lc, lm, lt1);
        lc = lt1;
        for (int i = 0; i < lt1; i++)
        {
            cnt[i] = temp1[i];
        }
        int temp2[Max]{0}, lt2 = 0;
        add(sum, cnt, temp2, ls, lc, lt2);
        ls = lt2;
        for (int i = 0; i < lt2; i++)
        {
            sum[i] = temp2[i];
        }
    }
    for (int i = ls - 1; i >= 0; i--)
        cout << sum[i];

    return 0;
}