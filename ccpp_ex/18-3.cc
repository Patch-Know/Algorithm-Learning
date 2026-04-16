#include<iostream>

using namespace std;

long double sum_value() {return 0;}

template<typename T>  //one parameter(optional)
long double sum_value(T value)
{
    return value;
}

template<typename T,typename ... Args>
long double sum_value(T value,Args... args)
{
    long double sum=0;
    sum+=value;
    sum+=sum_value(args...);
    return sum;
}

int main()
{
    cout << sum_value(1,2,3,4,5,6,23,62,72,762,72) <<endl;
    return 0;
}
