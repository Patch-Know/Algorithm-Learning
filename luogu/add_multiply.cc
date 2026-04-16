#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int Max = 240;

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
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int l1, l2, l3, l4;
    l1 = s1.size();
    l2 = s2.size();
    int a1[Max]{0}, a2[Max]{0}, a3[Max]{0}, a4[Max]{0};
    for (int i = 0; i < l1; i++)
    {
        a1[i] = s1[l1 - i - 1] - '0';
    }
    for (int i = 0; i < l2; i++)
    {
        a2[i] = s2[l2 - i - 1] - '0';
    }
    add(a1, a2, a3, l1, l2, l3);
    for (int i = l3 - 1; i >= 0; i--)
        cout << a3[i];
    cout << endl;

    multiply(a1, a2, a4, l1, l2, l4);
    for (int i = l4 - 1; i >= 0; i--)
        cout << a4[i];

    cin.get();
    return 0;
}
