#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    size_t cut,x,y,z;
    size_t x1,y1,z1,x2,y2,z2;
    cin >> x >> y >> z >> cut;
    vector<vector<vector<bool>>> v(x,vector<vector<bool>>(y,vector<bool>(z,true)));
    for (size_t c = 0; c < cut; c++)
    {
        cin >>x1 >>y1 >>z1 >> x2 >>y2 >>z2;
        for (size_t i = x1-1; i <=x2-1; i++)
        {
            for (size_t j = y1-1; j <=y2-1; j++)
            {
                for (size_t k = z1-1; k <=z2-1; k++)
                {
                    v[i][j][k]=false;
                }
            }
        }
    }
    int sum=0;
    for(auto & i:v) 
    for(auto & j:i) 
    for(bool k:j) 
    if(k) sum++;
    cout<< sum;
    return 0;
}