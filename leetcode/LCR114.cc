//火星词典

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string alienOrder(vector<string>& words) {
    vector<vector<int>> gragh(26); //邻接表
    vector<int> indegree(26,-1);    //入度表
    for(const string &word:words){
        for(char ch:word) indegree[ch-'a']=0;
    }
    //关键：根据词典典字符顺序建图
    for(int i=0;i<static_cast<int>(words.size())-1;i++){
        const string &cur=words[i];
        const string &next=words[i+1];
        int len=static_cast<int>(min(cur.length(),next.length()));
        int k=0;
        for(;k<len;k++){
            if(cur[k]!=next[k]){
                gragh[cur[k]-'a'].push_back(next[k]-'a');
                indegree[next[k]-'a']++;
                break;
            }
        }
        if(k<static_cast<int>(cur.length()) && k==static_cast<int>(next.length())){ //特判，不符合字典序第二条规则
            return "";
        }
    }
    vector<int> que(26);
    int l=0,r=0;
    int kinds=0;
    for(int i=0;i<26;i++){
        if(indegree[i]!=-1) kinds++;
        if(indegree[i]==0) que[r++]=i;
    }
    string ans;
    while(l<r){
        int u=que[l++];
        ans.push_back('a'+u);
        for(int v:gragh[u]){
            if(--indegree[v]==0) que[r++]=v;
        }
    }
    return static_cast<int>(ans.length())==kinds? ans : "";
}