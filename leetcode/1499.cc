//满足不等式的最大值

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

//思路:
//答案等于后点(y+x)+前点(y-x)的最大值
//--> 因此维护一个单调队列,使得当前合法的队列前端总是y-x最大 <--
//如此往复,便能得出总的最大值

int findMaxValueOfEquation(vector<vector<int>>& points,int k){
    int n=points.size();
    vector<vector<int>> q(n);
    int l=0,r=0;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        while(l<r && points[i][0]-q[l][0]>k) l++;
        if(l<r)ans=max(ans,points[i][0]-q[l][0]+points[i][1]+q[l][1]);
        while(l<r && q[r-1][1]-q[r-1][0]<=points[i][1]-points[i][0]) r--;
        q[r++]=points[i];
    }
    return ans;
}

int main()
{
    vector<vector<int>> points{{0,0},{3,0},{9,2}};
    int k=3;
    cout << findMaxValueOfEquation(points,k);
    
}
