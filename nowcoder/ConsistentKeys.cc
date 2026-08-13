#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int MAXN=2e5+5;

int tree[MAXN][10+2];

int pass[MAXN];

int End[MAXN];

const char stop='#';

int ctopath(char ch)
{
    if(ch==stop) return 11;
    else if(ch=='-') return 10;
    return ch-'0';
}

class TrieTree{
private:
    int cnt;
public:
    TrieTree():cnt(1){}

    void insert(string word)
    {
        int cur=1;
        pass[cur]++;
        for(int i=0,path;i<static_cast<int>(word.length());i++){
            path=ctopath(word[i]);
            if(tree[cur][path]==0){
                tree[cur][path]=++cnt;
            }
            cur=tree[cur][path];
            pass[cur]++;
        }
        End[cur]++;
    }

    bool search(string word)
    {
        int cur=1;
        for(int i=0,path;i<static_cast<int>(word.length());i++){
            path=ctopath(word[i]);
            if(tree[cur][path]==0){
                return false;
            }
            cur=tree[cur][path];
        }
        return End[cur]>0; //有可能只是经过而非以word结尾！！
    }

    int prefixNumber(string word)
    {
        int cur=1;
        for(int i=0,path;i<static_cast<int>(word.length());i++){
            path=ctopath(word[i]);
            if(tree[cur][path]==0){
                return 0;
            }
            cur=tree[cur][path];
        }
        return pass[cur];
    }

    void erase(string word)
    {
        if(search(word)){
            int cur=1;
            for(int i=0,path;i<static_cast<int>(word.length());i++){
                path=ctopath(word[i]);
                if(--pass[tree[cur][path]]==0){
                    tree[cur][path]=0;
                    return;
                }
                cur=tree[cur][path];
            }
            End[cur]--;
        }
    }
};

vector<int> countConsistentKeys(vector<vector<int> >& b, vector<vector<int> >& a) { //未考虑差值为负的情况
    TrieTree box;
    for(auto &x:a){
        string word;
        int len=static_cast<int>(x.size());
        for(int i=0;i<len-1;i++){
            int num=x[i+1]-x[i];
            word+=to_string(num)+stop;
        }
        if(!word.empty()) box.insert(word);
    }
    vector<int> ans;
    for(auto &x:b){
        string word;
        int len=static_cast<int>(x.size());
        for(int i=0;i<len-1;i++){
            int num=x[i+1]-x[i];
            word+=to_string(num)+stop;
        }
        if(!word.empty()) ans.push_back(box.prefixNumber(word));
    }
    return ans;
}