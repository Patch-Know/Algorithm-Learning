#include <iostream>
using namespace std;
inline bool is_palind(int n)
{
    int k = 0;
    int temp = n;
    while (temp)
    {
        k *= 10;
        k += temp % 10;
        temp /= 10;
    }
    if (n == k)
        return true;
    else
        return false;
}

inline bool is_prime(int x)
{
    for (int i = 2; i <= x / i /*防止爆int*/; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = a / 2 * 2 + 1; i <= b; i += 2)
    {
        if (is_palind(i) && is_prime(i))
            printf("%d\n", i);
    }

    return 0;
}