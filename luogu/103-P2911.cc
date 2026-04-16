#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t[81]{0};
    int a,b,c;
    cin>>a>>b>>c;
    int i,j,k;
    for (i = 1; i <= a; i++)
    {
        for (j = 1; j <= b; j++)
        {
            for (k = 1; k <= c; k++)
            {
                t[i+j+k]++;
            }
        }
    }
    int pmax=0;
    int max=0;
    for (int i = 3; i <=a+b+c; i++)
    {
        if(t[i]>max){
            max=t[i];
            pmax=i;
        }
    }
    
    cout << pmax;

    return 0;
}