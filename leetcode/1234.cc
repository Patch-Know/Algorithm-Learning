//替换子串得到平衡字符串

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int topos(char ch)
{
    switch(ch){
        case 'Q': return 0;
        case 'W': return 1;
        case 'E': return 2;
        case 'R': return 3;
    }
    return 0;
}

int balancedString(string s) {
    int n=static_cast<int>(s.length());
    vector<int> cnts(4,-n/4);
    for(auto ch:s) cnts[topos(ch)]++;
    int debt=0;
    for(int i=0;i<4;i++){
        if(cnts[i]>0) debt+=cnts[i];
    }
    if(debt==0) return 0;
    int ans=n;
    for(int l=0,r=0,ch;r<n;r++){
        ch=s[r];
        if(cnts[topos(ch)]-->0){ //精简的写法
            debt--;
        }
        if(debt==0){ //可以省去一部分while判断
            while(cnts[topos(s[l])]<0){
                cnts[topos(s[l++])]++;
            }
            ans=min(ans,r-l+1);
        }
    }
    return ans;
}