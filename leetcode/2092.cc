//找出知晓秘密的所有专家

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1e5+1;

int father[MAXN];

int Size[MAXN];

int sets;

void build(int N)
{
    for(int i=0;i<N;i++){
        father[i]=i;
        Size[i]=1;
    }
    sets=N;
}

int find(int i) 
{
    if(i!=father[i]){
        father[i]=find(father[i]);
    }
    return father[i];
}

bool isSameSet(int x,int y)
{
    return find(x)==find(y);
}

void Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){ 
        father[fx]=fy;
        sets--;
    }
}

void reset(int first,int i)
{
    if(!isSameSet(first,i) && i!=father[i]){
        father[i]=i;
        sets++;
    }
}

vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    vector<int> ans;
    sort(meetings.begin(),meetings.end(),[](const auto & a,const auto &b){return a[2]<b[2];});
    int time=-1,cur;
    int start=0,finish=-1;
    build(n);
    Union(0,firstPerson); //注意专家0一开始就知道秘密，并在0时刻与firstperson分享
    int len=static_cast<int>(meetings.size());
    for(int i=0;i<len;i++){
        cur=meetings[i][2];
        if(cur>time){
            finish=i-1;
            for(int k=start;k<=finish;k++){
                reset(0,meetings[k][0]);
                reset(0,meetings[k][1]);
            }
            start=i;
            time=cur;
        }
        Union(meetings[i][0],meetings[i][1]);
    }
    finish=len-1;
    for(int k=start;k<=finish;k++){
        reset(0,meetings[k][0]);
        reset(0,meetings[k][1]);
    }
    for(int i=0;i<n;i++){
        if(isSameSet(0,i)){
            ans.push_back(i);
        }
    }
    return ans;
}