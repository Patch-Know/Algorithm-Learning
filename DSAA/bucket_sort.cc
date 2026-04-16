#include<vector>
#include<queue>
#include<iostream>
#include<ctime>
#include<random>
#include<climits>
#include<algorithm>

using namespace std;

const int NUM = 200000000;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // 随机数设备，用于种子
    std::random_device rd;
    // 使用 64 位梅森旋转引擎，并用随机设备种子初始化
    std::mt19937_64 gen(rd());
    // 定义分布：unsigned long long 的完整范围
    std::uniform_int_distribution<unsigned long long> dist(0, ULLONG_MAX);
    vector<queue<int>> bucket_arr(1000);
    vector<int> unsorted_arr(NUM),sorted_arr(NUM);
    cout << "unsorted: \n";
    for(int & x : unsorted_arr){ x = dist(gen)%1000000000;
        //cout << x << endl;
    }
    cout<<"Done.\n";
    cout << "\n\nsorted: \n";
    clock_t start,finish;
    cout << "Start!" << endl;
    start=clock();
    for(int x : unsorted_arr) bucket_arr[x%1000].push(x);
    int i=0;
    for(auto & bucket : bucket_arr){
        while (!bucket.empty())
        {
            sorted_arr[i++]=bucket.front();
            bucket.pop();
        }
        
    }
    for(int x : sorted_arr) bucket_arr[x/1000%1000].push(x);
    i=0;
    for(auto & bucket : bucket_arr){
        while (!bucket.empty())
        {
            sorted_arr[i++]=bucket.front();
            bucket.pop();
        }
        
    }
    for(int x : sorted_arr) bucket_arr[x/1000/1000%1000].push(x);
    i=0;
    for(auto & bucket : bucket_arr){
        while (!bucket.empty())
        {
            sorted_arr[i++]=bucket.front();
            bucket.pop();
        }
        
    }
    finish=clock();
    cout<<"Done.\n" << (double)(finish-start)/CLOCKS_PER_SEC << " s\n" << endl;
    //for(int x : sorted_arr) cout << x << endl;
    cout << "Start!" << endl;
    start=clock();
    sort(unsorted_arr.begin(),unsorted_arr.end());
    finish=clock();
    cout<<"Done.\n" << (double)(finish-start)/CLOCKS_PER_SEC << " s\n";
    return 0;
}