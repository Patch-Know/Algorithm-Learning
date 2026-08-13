//全O(1)的数据结构
#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<iterator>
#include<climits>

using namespace std;

class AllOne {
private:
    unordered_map<string,int> fm; //frequence_map
    list<pair<int,unordered_set<string>>> bl; //bucket_list
    unordered_map<string,decltype(bl)::iterator> im; //index_map
public:
    AllOne(){
        bl.push_back({0,{}});
        bl.push_back({INT_MAX,{}});
    }
    
    void inc(string key) {
        if(fm[key]==0){
            fm[key]=1;
            auto it=next(bl.begin());
            if(it->first!=1){
                bl.insert(it,{1,{key}});
            }else{
                it->second.insert(key);
            }
            im[key]=next(bl.begin());
            return;
        }
        fm[key]++;
        auto last=im[key];
        auto it=next(last);
        if(it->first!=last->first+1){
            bl.insert(it,{last->first+1,{key}});
        }else{
            it->second.insert(key);
        }
        im[key]=next(last);
        last->second.erase(key);
        if(last->second.empty()) bl.erase(last);
    }
    void dec(string key) {
        fm[key]--; //懒惰删除
        auto last=im[key];
        auto it=prev(last);
        if(last->first==1){
            last->second.erase(key);
            im.erase(key);
        }else{
            if(it->first!=last->first-1){
                bl.insert(last,{last->first-1,{key}});
            }else{
                it->second.insert(key);
            }
            im[key]=prev(last);
            last->second.erase(key);
        }
        if(last->second.empty()) bl.erase(last);
    }
    
    string getMaxKey() {
        auto it=prev(prev(bl.end()));
        return it->first==0 ? "" : *it->second.begin();
    }
    
    string getMinKey() {
        auto it=next(bl.begin());
        return it->first==INT_MAX ? "" : *it->second.begin();
    }
};