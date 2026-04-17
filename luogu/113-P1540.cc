#include<iostream>
#include<queue>

using namespace std;

int a[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    queue<int> q;
    size_t cap,length;
    int cnt=0,num;
    cin >> cap >> length;
    for(size_t i=0;i<length;i++){
        cin >> num;
        if(!a[num]){
            ++cnt;
            if(q.size()==cap){
                a[q.front()]=0;
                q.pop();
            }
            a[num]=1;
            q.push(num);
        }
    }
    cout << cnt;
    return 0;
}