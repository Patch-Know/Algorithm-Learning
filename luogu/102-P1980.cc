#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        do
        {
            if (temp % 10 == x)
                cnt++;
        } while (temp /= 10);
    }
    cout << cnt;
    return 0;
}