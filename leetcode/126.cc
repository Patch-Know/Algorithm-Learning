//单词接龙II

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

unordered_set<string> dict;
unordered_set<string> curLevel;
unordered_set<string> nxtLevel;
unordered_map<string,vector<string>> gragh; 

vector<string> path;
vector<vector<string>> ans;

void build(const vector<string>& wordList)
{
    dict.clear();
    curLevel.clear();
    nxtLevel.clear();
    gragh.clear();
    path.clear();
    ans.clear();
    for(const auto &s:wordList) dict.insert(s);
}

bool bfs(const string &beginWord,const string & endWord)
{
    int len=beginWord.length();
    curLevel.insert(beginWord);
    while(!curLevel.empty()){
        for(const auto &curWord:curLevel){
            auto tmp=curWord;
            dict.erase(curWord);
            for(int i=0;i<len;i++){
                for(int j=0;j<26;j++){
                    if(j==curWord[i]-'a') continue;
                    tmp[i]='a'+j;
                    if(curLevel.count(tmp)==0 && dict.count(tmp)!=0){
                        nxtLevel.insert(tmp);
                        gragh[tmp].push_back(curWord); //这里我真的哭死,正向建图,反向回溯
                    }
                }
                tmp[i]=curWord[i];
            }
        }
        if(nxtLevel.count(endWord)!=0) return true;
        //curLevel=nxtLevel
        curLevel.swap(nxtLevel); //O(n)->O(1)
        nxtLevel.clear();
    }
    return false;
}

//find all
void dfs(const string &word,const string &aim)
{
    path.push_back(word);
    if(word==aim){
        ans.push_back({path.rbegin(),path.rend()});
    }else{
        for(const auto &s:gragh[word]){
            dfs(s,aim);
        }
    }
    path.pop_back();
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    build(wordList);
    if(dict.count(endWord)==0) return {};
    if(bfs(beginWord,endWord)) dfs(endWord,beginWord);
    return ans;
}