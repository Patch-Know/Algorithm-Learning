#include <iostream>
using namespace std;

int main()
{
    int n;
    int ct = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (ct < 10)
                cout << "0";
            cout << ct;
            ct++;
        }
        cout << endl;
    }
    return 0;
}