#include <iostream>
using namespace std;
inline int to_palind(int temp)
{
    int k = 0;
    while (temp)
    {
        k *= 10;
        k += temp % 10;
        temp /= 10;
    }
    return k;
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
        cout << '0';
    else if (n > 0)
        cout << to_palind(n);
    else
        cout << -to_palind(-n);
    return 0;
}