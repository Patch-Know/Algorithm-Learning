//最小覆盖子串
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<limits.h>
using namespace std;

int cnts[128];

string minWindow(string s, string t) { //最小覆盖子串
    memset(cnts,0,sizeof(cnts));
    int len=static_cast<int>(s.length());
    int debt=0;
    for(auto ch:t){
        cnts[ch]--;
        debt++;
    }
    int l=0,r=0,ans=INT_MAX,ans_start;
    while(r<len){
        int ch=s[r++];
        if(cnts[ch]<0) debt--;
        cnts[ch]++;
    //原本不小心把外层while循环的末尾括号写这里，居然还能通过全部的测试用例
    //和一半的答案。只能说测试集太水了，太危险了···
        while(cnts[s[l]]>0) cnts[s[l++]]--;
        if(debt==0 && ans>r-l){
            ans=r-l;
            ans_start=l;
        }
    }//这是正确的位置
    return ans==INT_MAX?"":s.substr(ans_start,ans);
}