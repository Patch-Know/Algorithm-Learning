#include <iostream>

using namespace std;

int main()
{
    const int Len = 100000;
    int arr_prime[Len]{2};
    int top = 1;
    int sum = 2;
    int cnt = 1;
    int L;
    cin >> L;
    for (int i = 3; i <= L; i++)
    {
        bool is_prime = true;
        for (int j = 0; j < top; j++)
        {
            if (i % arr_prime[j] == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            if (sum + i > L)
                break;
            arr_prime[top] = i;
            top++;
            sum += i;
            cnt++;
            if (sum == L)
                break;
        }
    }

    if (L == 1)
        cout << '0';
    else
    {
        for (int i = 0; i < top; i++)
        {
            cout << arr_prime[i] << endl;
        }
        cout << cnt;
    }

    return 0;
}