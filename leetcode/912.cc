//sortArray
//heapSort
//big root
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    vector<int> arr;
    int size;

    //percolate up
    void heapInsert(int i)
    {
        while(arr[i]>arr[(i-1)/2]){
            arr[i]=arr[(i-1)/2];
            i=(i-1)/2;
        }
    }

    //percolate down
    void heapify(int i)
    {
        int num=arr[i];
        int child=i*2+1;
        while(child<size){
            if(child+1<size && arr[child+1]>arr[child]) child++;
            if(arr[child]>num){
                arr[i]=arr[child];
                i=child;
                child=i*2+1;
            }else break;
        }
        arr[i]=num;
    }

    void makeheap(const vector<int> &nums)
    {
        arr=nums;
        size=nums.size();
        for(int i=size/2;i>=0;i--) heapify(i);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        makeheap(nums);
        while(size>1){
            swap(arr[0],arr[--size]);
            heapify(0);
        }
        return arr;
    }
};