#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;
    int n = 0;
    long double sum = 0.0;
    while (sum <= k)
    {
        n++;
        sum += (long double)1.0 / n;
    }
    cout << n;

    return 0;
}