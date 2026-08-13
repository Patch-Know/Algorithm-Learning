//字符串的全部子序列，要求去重

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

void f(const string & s,int i,string & path,unordered_set<string> &set)
{
    if(i==static_cast<int>(s.length())){
        set.insert(path);
        return;
    }
    //不添加i位置元素
    f(s,i+1,path,set);
    //添加i位置元素
    path.push_back(s[i]);
    f(s,i+1,path,set);
    path.pop_back();
}

vector<string> generatePermutation(string s) {
    unordered_set<string> ans;
    string path;
    f(s,0,path,ans);
    return vector<string>(ans.begin(),ans.end());
}