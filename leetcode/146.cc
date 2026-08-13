//LRU缓存

#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class LRUCache {
private:
    typedef list<pair<int,int>> lp;
    lp tl; //time_list
    unordered_map<int,lp::iterator> hm; //hash_map
    int cap;
    int cnt;    
public:
    LRUCache(int capacity) {
        cap=capacity;
        cnt=0;
    }
    
    int get(int key) {
        int ans=-1;
        if(hm.contains(key)){
            ans=hm[key]->second;
            tl.splice(tl.end(),tl,hm[key]);
        }
        return ans;
    }
    
    void put(int key, int value) {
        if(hm.contains(key)){
            hm[key]->second=value;
            tl.splice(tl.end(),tl,hm[key]);
        }else{
            if(cnt==cap){
                hm.erase(tl.begin()->first);
                tl.pop_front();
                --cnt;
            }
            ++cnt;
            tl.push_back({key,value});
            hm.insert({key,--tl.end()});
        }
    }
};