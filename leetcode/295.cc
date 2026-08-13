//中位数

#include<iostream>
#include<functional>
#include<queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> lq; //大根堆
    priority_queue<int,vector<int>,greater<int>> hq; //小根堆，应该传入比较器类型
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(lq.empty()) lq.push(num);
        else if(static_cast<int>(lq.size())>static_cast<int>(hq.size())){
            if(num<lq.top()){
                hq.push(lq.top());
                lq.pop();
                lq.push(num);
            }else hq.push(num);
        }else{
            if(num>hq.top()){
                lq.push(hq.top());
                hq.pop();
                hq.push(num);
            }else lq.push(num);
        }
    }
    
    double findMedian() {
        if(static_cast<int>(lq.size())>static_cast<int>(hq.size())) return lq.top();
        return (lq.top()+hq.top())/2.0;
    }
};