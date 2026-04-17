#include<iostream>
#include<list>

using namespace std;

int a[100005];
list<int>::iterator pos[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n,m,num,side;
    list<int> stu;
    stu.push_back(1);
    pos[1]=stu.begin();
    cin >> n;
    for(int i=2;i<=n;i++){
        cin >> num >> side;
        if(side==0)
        pos[i]=stu.insert(pos[num],i);
        else pos[i]=stu.insert(next(pos[num]),i);
    }
    cin >> m;
    
    for(int i=0;i<m;i++){
        cin >> num;
        a[num]=1;
    }
    auto it = stu.begin();
    while(it!=stu.end()){
        if(!a[*it]) ++it;
        else{
            a[*it]=0;
            it=stu.erase(it);
        }
    }
    for(int x:stu) cout << x << ' ';
    return 0;
}