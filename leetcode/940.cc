// 不同的子序列 II
// 给定一个字符串 s，计算 s 的 不同非空子序列 的个数
// 因为结果可能很大，答案对 1000000007 取模
// 字符串的 子序列 是经由原字符串删除一些（也可能不删除）
// 字符但不改变剩余字符相对位置的一个新字符串
// 例如，"ace" 是 "abcde" 的一个子序列，但 "aec" 不是

//all:包含空串在内所有的不同子串
//cnts[i]:以i+'a'字符结尾的不同子串（当前字符上次效果）
//newadd=all-cnts[i],表示以i+'a'字符结尾的不同子串

//核心思想是去重

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

const int mod=1e9+7;

int cnts[26];

int distinctSubseqII(string s) {
    memset(cnts,0,sizeof(cnts));
    int all=1,newadd;
    for(char ch:s){
        newadd=(all-cnts[ch-'a']+mod)%mod;
        cnts[ch-'a']=(cnts[ch-'a']+newadd)%mod;
        all=(all+newadd)%mod;
    }
    return (all-1+mod)%mod;
}