#include <iostream>
using namespace std;

int main()
{
    int n;
    int num;
    int min = 1000;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num < min)
            min = num;
    }
    cout << min;
    return 0;
}