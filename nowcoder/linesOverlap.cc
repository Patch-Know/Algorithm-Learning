#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int,vector<int>,greater<int>> heap;
    int N;
    cin >> N;
    vector<pair<int,int>> lines(N);
    for(int i=0;i<N;i++){
        cin >> lines[i].first >> lines[i].second;
    }
    sort(lines.begin(),lines.end());
    int ans=0;
    for(const auto [l,r]:lines){
        while(!heap.empty() && heap.top()<=l){
            heap.pop();
        }
        heap.push(r);
        ans=max(ans,static_cast<int>(heap.size()));
    }
    cout << ans;
}