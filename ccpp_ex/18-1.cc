#include<iostream>
#include<initializer_list>

using namespace std;

template<typename T>
T average_list(initializer_list<T> li)
{
    T sum = 0;
    int i=0;
    for(auto x:li){sum+=x;i++;};
    return sum/i;
}

int main()
{
    auto q = average_list({15.4,10.7,9.0});
    cout << q <<endl;
    cout << average_list({20,30,19,17,45,38}) << endl;
    auto ad = average_list<double> ({'A',70,65.33});
    cout << ad << endl;
    return 0;
}