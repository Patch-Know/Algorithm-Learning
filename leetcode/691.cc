//贴纸拼词
//bfs+剪枝

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;

string Next(const string &t,const string &s) //算常用吧，记住！
{
    string ans;
    int len_t=t.length();
    int len_s=s.length();
    for(int i=0,j=0;i<len_t;){
        if(j==len_s){
            ans+=t[i++];
        }else{
            if(t[i]<s[j]){
                ans+=t[i++];
            }else if(t[i]>s[j]){
                j++;
            }else{
                i++;
                j++;
            }
        }
    }
    return ans;
}

int minStickers(vector<string>& stickers, string target) {
    const int MAXN=401;
    vector<string> que(MAXN);
    int l=0,r=0;
    vector<vector<string>> gragh(26); //能搞定当前字符的字符串
    unordered_set<string> visited;
    for(auto &s:stickers){
        sort(s.begin(),s.end());
        int len=s.length();
        for(int i=0;i<len;i++){
            if(i==0 || s[i]!=s[i-1]){
                gragh[s[i]-'a'].push_back(s);
            }
        }
    }
    sort(target.begin(),target.end());
    visited.insert(target);
    que[r++]=target;
    int level=1;
    while(l<r){
        //整层弹出
        int sz=r-l;
        for(int i=0;i<sz;i++){
            const auto &cur=que[l++];
            for(const auto &s:gragh[cur[0]-'a']){ //剪枝
                string nxt=Next(cur,s);
                if(nxt.empty()) return level;
                else if(visited.count(nxt)==0){ //不重复
                    visited.insert(nxt);
                    que[r++]=nxt;
                }
            }
        }
        level++;
    }
    return -1;
}