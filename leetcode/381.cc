//插入、删除和获取随机元素O(1)时间且允许有重复数字的结构
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<ctime>
#include<cstdlib>

using namespace std;


class RandomizedCollection {
private:
        unordered_map<int,unordered_set<int>> hm; // value -> index_set
        vector<int> v; // value
public:
    RandomizedCollection() {
        srand(time(0)); //这里初始化,否则getrandom会集中到一个时候
        //hm.reserve(200000);
        //v.reserve(200000);        
    }
    
    bool insert(int val) {
        if(hm.count(val)){
            hm[val].insert(static_cast<int>(v.size()));
            v.push_back(val);
            return false;
        }
        hm[val]=unordered_set<int>({static_cast<int>(v.size())});
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) { //其实要分3种情况讨论
        if(!hm.count(val)) return false;
        int idx=*hm[val].begin();
        int last=v.back();
        if(last==val){ //删掉最后一个即可，忽略idx
            hm[val].erase(static_cast<int>(v.size())-1);
        }else{
            v[idx]=last;
            hm[last].erase(static_cast<int>(v.size())-1);
            hm[last].insert(idx);
            hm[val].erase(idx); //(有可能是同一个数字的同一个下标，注意不能同时被删两遍)
        }
        v.pop_back();
        if(hm[val].empty()) hm.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%static_cast<int>(v.size())];
    }
};