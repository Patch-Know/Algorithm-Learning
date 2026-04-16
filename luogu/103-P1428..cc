#include<iostream>
#include<vector>
using namespace std;

int main()
{
    size_t n;
    cin >> n;
    vector<int> v(n),out(n);
    for(int & x : v) cin >> x;
    for (size_t i = 0; i < n; i++)
    {
        int sum=0;
        for (size_t j = 0; j < i; j++)
        {
            sum+=v[j]<v[i]? 1 : 0;
        }
        out[i]=sum;
    }
    for(int & x : out) cout<< x<<' ';
    
    return 0;
}