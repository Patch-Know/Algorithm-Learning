//救生艇

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define LOOP2


int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(),people.end());
    int len=static_cast<int>(people.size());
    int l=0,r=len-1,ans=0,weight=0;
#ifndef LOOP2   
    while(l<=r){
        if(weight==0) weight=people[r--];
        else{
            if(weight+people[r]<=limit) r--;
            else if(weight+people[l]<=limit) l++;
            weight=0;
            ans++;
        }
    }
#else //这个方法简洁直观，值得借鉴！
    while(l<=r){
        int sum=l==r? people[l] : people[l]+people[r];
        if(sum>limit) r--;
        else{l++;r--;}
        ans++;
    }
#endif
    if(weight!=0) ans++;
    return ans;
}     

int main()
{
    vector<int> peo{5,1,4,2};
    int ans=numRescueBoats(peo,6);
    cout << ans;
    return 0;
}
