#include<iostream>
#include<numeric>

using namespace std;

long double fastpower(long double b,unsigned n);

int main()
{
    long double base;
    unsigned N;
    cin >> base >> N;
    cout << showpoint << fixed <<fastpower(base,N) << endl;

    return 0;
}

long double fastpower(long double b,unsigned n)
{
    if(n==0) return 1.0L;
    long double M=1.0L;
    while (n>1){
        if(n&1) M*=b;
        b*=b;
        n >>= 1;
    }
    return b*M;
}