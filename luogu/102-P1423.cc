#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double final;
    cin >> final;
    int step = 0;
    double current = 0.0;
    while (current < final)
    {
        step++;
        current = 100.0 - 100.0 * pow(0.98, step);
    }
    cout << step;
    return 0;
}