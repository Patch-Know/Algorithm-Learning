//去除重复字母
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string removeDuplicateLetters(string s) {
    int cnt[26]{};
    for(char ch:s)cnt[ch-'a']++;
    int n=s.size();
    vector<int> st(n);
    int r=0;
    vector<bool> entered(n,false);
    for(char ch:s){
        int pos=ch-'a';
        if(!entered[pos]){
        while(r>0 && pos<=st[r-1] && cnt[st[r-1]]>0){
            entered[st[--r]]=false;
        }
        st[r++]=pos;
        entered[pos]=true;
        }
        cnt[pos]--;
    }
    string ret;
    ret.reserve(r);
    transform(st.begin(),st.begin()+r,back_inserter(ret),[](int x){return static_cast<char>(x+'a');});
    return ret;
}
