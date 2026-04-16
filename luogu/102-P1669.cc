#include <iostream>

using namespace std;

int main()
{
    int k, sum = 0;
    cin >> k;
    int i = 0, m = 1;
    while (i <= k)
    {
        if (i + m < k)
        {
            sum += m * m;
            i += m;
        }
        else
        {
            sum += m * (k - i);
            i += k - i;
            break;
        }
        m++;
    }
    cout << sum;

    return 0;
}