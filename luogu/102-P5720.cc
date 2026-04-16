#include <iostream>
using namespace std;

int main()
{
    int length;
    cin >> length;
    int day = 1;
    while (length != 1)
    {
        day++;
        length /= 2;
    }
    cout << day;
    return 0;
}