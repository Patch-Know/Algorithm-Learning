#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    size_t n,sum=0;
    cin >> n;
    vector<array<int,3>> ar(n);
    for(auto & a:ar)
        for(int & x:a)
            cin>>x;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i+1; j < n; j++)
        {
            bool is_cp = true;
            int sum1=0,sum2=0;
            for (size_t k = 0; k < 3; k++)
            {
                if(abs(ar[i][k]-ar[j][k])>5) is_cp = false;
                sum1+=ar[i][k];
                sum2+=ar[j][k];
            }
            if(abs(sum1-sum2)>10) is_cp = false;
            if(is_cp) sum++;
        }
    }
    cout << sum;
    return 0;
}