//给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words， 返回所有二维网格上的单词 。
//单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
//同一个单元格内的字母在一个单词中不允许被重复使用。
/*
提示：
m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] 是一个小写英文字母
1 <= words.length <= 3 * 10^4
1 <= words[i].length <= 10
words[i] 由小写英文字母组成
words 中的所有字符串互不相同
*/

//将words构建为字典树
//剪枝很重要！！！
#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN=3e5+5;

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
        cnt=1; 
    }
};

int path[12][12];

const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

bool check(int m,int n,int x,int y)
{
    if(x<0 || y<0 || x>=m || y>=n || path[x][y]) return false;
    return true;
}

void f(const vector<vector<char>>& board,int m,int n,int x,int y,string & word,TrieTree & trie,vector<string> & ans)
{
    path[x][y]=1;
    word.push_back(board[x][y]);
    if(trie.search(word)){
        ans.push_back(word);
        trie.erase(word);
    }
    if(static_cast<int>(word.length())==10 || trie.prefixNumber(word)==0){
        path[x][y]=0;
        word.pop_back();
        return;
    }
    for(int i=0;i<4;i++){
        if(check(m,n,x+dir[i][0],y+dir[i][1])){
            f(board,m,n,x+dir[i][0],y+dir[i][1],word,trie,ans);
        }
    }
    path[x][y]=0;
    word.pop_back();
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    string temp;
    TrieTree trie;
    int m=static_cast<int>(board.size());
    int n=static_cast<int>(board[0].size());
    for(const auto & word : words){
        trie.insert(word);
    }
    vector<string> ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            f(board,m,n,i,j,temp,trie,ans);
        }
    }
    trie.clear();
    return ans;
}

//Java：dfs 返回 int（从当前节点收集到的单词数量），
//用于更新上层节点的 pass；递归时携带当前 Trie 节点编号 t，省去了每次从头查找前缀的步骤，效率更高。
//end数组存string
//学习！！