//至少有k个重复字符的最长子串
//根据数据量猜解法

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#define PLUS
#ifndef PLUS

int longestSubstring_N(const string & s,int k,int top)
{
    int len=static_cast<int>(s.size());
    int cnts[26]{};
    int ans=0;
    for(int l=0,r=0,kind=0;r<len;r++){
        if(cnts[s[r]-'a']++==0) kind++;
        if(kind>top){
            while(--cnts[s[l++]-'a']>0);
            kind--;
        }
        if(kind==top){
            bool over_k=true;
            for(int i=0;i<26;i++){
                if(cnts[i]>0 && cnts[i]<k){
                    over_k=false;
                    break;
                }
            }
            if(over_k) ans=max(ans,r-l+1);
        }
    }
    return ans;
}

#else
int longestSubstring_N(const string & s,int k,int top)
{
    int len=static_cast<int>(s.size());
    int cnts[26]{};
    int ans=0;
    for(int l=0,r=0,kind=0,satisfy=0;r<len;r++){ //合理定义变量，节省判断时的计算
        if(cnts[s[r]-'a']++==0) kind++;
        if(cnts[s[r]-'a']==k) satisfy++;
        if(kind>top){
            while(1){
                if(cnts[s[l]-'a']==k) satisfy--;
                if(--cnts[s[l++]-'a']==0){
                    kind--;
                    break;
                }
            }
        }
        if(kind==top && satisfy==top){
            ans=max(ans,r-l+1);
        }
    }
    return ans;
}
#endif


int longestSubstring(string s, int k) {
    int ans=0;
    for(int i=1;i<=26;i++){
        ans=max(ans,longestSubstring_N(s,k,i));
    }
    return ans;
}