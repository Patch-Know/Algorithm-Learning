//常数时间插入，删除和获取随机元素

#include<iostream>
#include<unordered_map>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int,int> hm; // value -> index
    vector<int> v; // value
public:
    RandomizedSet() {
        srand(time(0)); //这里初始化,否则getrandom会集中到一个时候
        hm.reserve(200000);
        v.reserve(200000);
    }
    bool insert(int val) {
        if(hm.contains(val)) return false;
        hm.insert({val,static_cast<int>(v.size())});
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!hm.contains(val)) return false;
        int idx=hm[val];
        int last=v.back();
        v[idx]=last;
        hm[last]=idx; //记得修改被最后元素被移动后的索引值
        v.pop_back();
        hm.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%static_cast<int>(v.size())];
    }
};