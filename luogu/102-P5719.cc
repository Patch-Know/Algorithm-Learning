#include <iostream>
using namespace std;

int main()
{
    int n, k;
    int sum_a = 0, sum_b = 0;
    int cnt_a = 0, cnt_b = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            sum_a += i;
            cnt_a++;
        }
        else
        {
            sum_b += i;
            cnt_b++;
        }
    }
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << (double)sum_a / cnt_a << " " << (double)sum_b / cnt_b;
    return 0;
}