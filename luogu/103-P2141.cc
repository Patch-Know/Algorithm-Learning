#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,count=0;
    cin >> n;
    vector<int> v1(n);
    int v2[100][100];
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            v2[i][j]=v1[i]+v1[j];
        }
    }

    int temp;

    for (int k = 0; k < n; k++)
    {
        temp=v1[k];
        for (int i = 0; i < n; i++)
        {
            if(i==k) continue;
            for (int j = i+1; j < n; j++)
            {
                if(j==k) continue;
                if(v2[i][j]==temp){
                    count++;
                    goto here;
                }
            }
        }
        here: ;
    }
    cout<< count ;
    
    return 0;
}