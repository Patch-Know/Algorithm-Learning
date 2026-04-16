#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int pieces;
    cin>>pieces;
    array<int,7> right,temp,result{0,0,0,0,0,0,0};
    for(auto & x :right) cin>>x;
    for(int p=0;p<pieces;p++){
        for(auto & x :temp) cin>>x;
        int sum=0;
        for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                if(right[i]==temp[j]){
                    sum++;break;
                }
            }
        }
        if(sum>0) result[7-sum]++;
    }
    for(auto & x :result) cout<< x << ' ';

    return 0;
}