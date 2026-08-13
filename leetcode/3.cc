//无重复字符的最长子串

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int lengthOfLongestSubstring1(string s) {
    int len=static_cast<int>(s.length());
    int l=0,r=0,ans=0;
    vector<int> last(256,-1); //每一种字符上次出现的位置
    while(r<len){
        int ch=s[r];
        if(last[ch]!=-1) l=max(l,last[ch]+1); //l不能后退！！
        last[ch]=r++;
        ans=max(ans,r-l);
    }
    return ans;
}

int last[256];

int lengthOfLongestSubstring2(string s) {
    int len=static_cast<int>(s.length());
    int l=0,r=0,ans=0;
    //vector<int> last(256,-1); //每一种字符上次出现的位置
    memset(last,-1,sizeof(last));
    while(r<len){
        int ch=s[r];
        if(last[ch]!=-1) l=max(l,last[ch]+1); //l不能后退！！
        last[ch]=r++;
        ans=max(ans,r-l);
    }
    return ans;
}