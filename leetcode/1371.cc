#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int findTheLongestSubstring1(string s) {
    unordered_map<int,int> map;
    map[0]=-1;
    int len=static_cast<int>(s.length());
    int ans=0;
    for(int i=0,sym=0;i<len;i++){
        switch(s[i]){
            case 'a': sym^=1<<0;break;
            case 'e': sym^=1<<1;break;
            case 'i': sym^=1<<2;break;
            case 'o': sym^=1<<3;break;
            case 'u': sym^=1<<4;break;
        }
        if(map.count(sym)!=0){
            ans=max(ans,i-map[sym]);
        }else map[sym]=i;
    }
    return ans;
}

//另一种做法,数组代替哈希，更快

int findTheLongestSubstring2(string s) {
    vector<int> map(32,-2);
    map[0]=-1;
    int len=static_cast<int>(s.length());
    int ans=0;
    for(int i=0,sym=0;i<len;i++){
        switch(s[i]){
            case 'a': sym^=1<<0;break;
            case 'e': sym^=1<<1;break;
            case 'i': sym^=1<<2;break;
            case 'o': sym^=1<<3;break;
            case 'u': sym^=1<<4;break;
        }
        if(map[sym]!=-2){
            ans=max(ans,i-map[sym]);
        }else map[sym]=i;
    }
    return ans;
}