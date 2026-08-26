//Word Ladder

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>

using namespace std;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict={wordList.begin(),wordList.end()};
    if(dict.count(endWord)==0) return 0;
    unordered_set<string> smallLevel={beginWord};
    unordered_set<string> bigLevel={endWord};
    unordered_set<string> nxtLevel;
    int len=beginWord.length();
    int step=0;
    while(!smallLevel.empty()){
        step++;
        for(const auto &Word:smallLevel) dict.erase(Word);
        for(const auto &Word:bigLevel) dict.erase(Word);
        for(const auto &curWord:smallLevel){
            auto tmp=curWord;
            for(int i=0;i<len;i++){
                for(int j=0;j<26;j++){
                    if(j==curWord[i]-'a') continue;
                    tmp[i]='a'+j;
                    if(bigLevel.count(tmp)!=0) return step+1;
                    if(dict.count(tmp)!=0){
                        nxtLevel.insert(tmp);
                    }
                }
                tmp[i]=curWord[i];
            }
        }
        if(nxtLevel.size()<bigLevel.size()){
            smallLevel.swap(nxtLevel);
        }else{
            smallLevel.swap(bigLevel);
            bigLevel.swap(nxtLevel);
        }
        nxtLevel.clear();
    }
    return 0;
}

