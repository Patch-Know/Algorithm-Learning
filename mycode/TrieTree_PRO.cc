// 用固定数组实现前缀树，空间使用是静态的。推荐！ 牛客

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int MAXN=2e5+5;

int tree[MAXN][26];

int pass[MAXN];

int End[MAXN];

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
            path=word[i]-'a';
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
            path=word[i]-'a';
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
            path=word[i]-'a';
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
                path=word[i]-'a';
                if(--pass[tree[cur][path]]==0){
                    tree[cur][path]=0;
                    return;
                }
                cur=tree[cur][path];
            }
            End[cur]--;
        }
    }

    void clear()
    {
        for(int i=1;i<=cnt;i++)
        {
            pass[i]=0;
            End[i]=0;
            memset(tree[i],0,sizeof(tree[i]));
        }
        cnt=1; //记得重置
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    TrieTree a;
    string word;
    int op;
    for(int i=0;i<n;i++){
        cin >> op >> word;
        switch(op){
            case 1:a.insert(word);break;
            case 2:a.erase(word);break;
            case 3:cout << (a.search(word) ? "YES" : "NO") << endl;break;
            case 4:cout << a.prefixNumber(word) << endl;
        }
    }
    return 0;
}

