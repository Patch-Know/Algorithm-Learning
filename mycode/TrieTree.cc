//前缀树（字典树）

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cmath>

using namespace std;

//数组实现
class Trie1{
private:
    struct TrieNode{
        int pass;
        int end;
        TrieNode * nexts[26]={};
        TrieNode():pass(0),end(0){}
    };

    TrieNode * root;
public:
    Trie1()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode * node=root;
        node->pass++;
        for(int i=0,path;i<static_cast<int>(word.length());i++){
            path=word[i]-'a';
            if(!node->nexts[path]){
                node->nexts[path]=new TrieNode();
            }
            node=node->nexts[path];
            node->pass++;
        }
        node->end++;
    }

    int countWordsEqualTo(string word)
    {
        TrieNode * node=root;
        for(int i=0,path;i<static_cast<int>(word.length());i++){
            path=word[i]-'a';
            if(!node->nexts[path]){
                return 0;
            }
            node=node->nexts[path];
        }
        return node->end;
    }

    int countWordsStartingWith(string pre)
    {
        TrieNode * node=root;
        for(int i=0,path;i<static_cast<int>(pre.length());i++){
            path=pre[i]-'a';
            if(!node->nexts[path]){
                return 0;
            }
            node=node->nexts[path];
        }
        return node->pass;
    }

    void erase(string word)
    {
        if(countWordsEqualTo(word)>0){
            TrieNode * node=root;
            for(int i=0,path;i<static_cast<int>(word.length());i++){
                path=word[i]-'a';
                if(--node->nexts[path]->pass==0){
                    node->nexts[path]=nullptr;
                    return ;
                }
                node=node->nexts[path];
            }
            node->end--;
        }
    }
};


//哈希表实现
class Trie2{
private:
    struct TrieNode{
        int pass;
        int end;
        unordered_map<char,TrieNode *> nexts;
        TrieNode():pass(0),end(0){}
    };

    TrieNode * root;
public:
    Trie2()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode * node=root;
        node->pass++;
        char path;
        for(int i=0;i<static_cast<int>(word.length());i++){
            path=word[i];
            if(!node->nexts.count(path)){
                node->nexts[path]=new TrieNode();
            }
            node=node->nexts[path];
            node->pass++;
        }
        node->end++;
    }

    int countWordsEqualTo(string word)
    {
        TrieNode * node=root;
        char path;

        for(int i=0;i<static_cast<int>(word.length());i++){
            path=word[i];
            if(!node->nexts.count(path)){
                return 0;
            }
            node=node->nexts[path];
        }
        return node->end;
    }

    int countWordsStartingWith(string pre)
    {
        TrieNode * node=root;
        char path;

        for(int i=0;i<static_cast<int>(pre.length());i++){
            path=pre[i];
            if(!node->nexts.count(path)){
                return 0;
            }
            node=node->nexts[path];
        }
        return node->pass;
    }

    void erase(string word)
    {
        if(countWordsEqualTo(word)>0){
            TrieNode * node=root;
            char path;
            for(int i=0;i<static_cast<int>(word.length());i++){
                path=word[i];
                if(--node->nexts[path]->pass==0){
                    node->nexts.erase(path);
                    return;
                }
                node=node->nexts[path];
            }
            node->end--;
        }
    }
};

int main()
{
    Trie1 a;
    a.insert("a");
    a.insert("ab");
    a.insert("ab");
    a.insert("abc");
    cout << a.countWordsEqualTo("abc") << endl;
    cout << a.countWordsStartingWith("a") << endl;
    a.erase("ab");
    cout << a.countWordsEqualTo("ab") << endl;
    Trie2 b;
    b.insert("a");
    b.insert("ab");
    b.insert("ab");
    b.insert("abc");
    cout << b.countWordsEqualTo("abc") << endl;
    cout << b.countWordsStartingWith("a") << endl;
    b.erase("ab");
    cout << b.countWordsEqualTo("ab") << endl;
    return 0;
}