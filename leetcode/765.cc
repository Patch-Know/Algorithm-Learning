//并查集，情侣牵手

#include<iostream>
#include<vector>
using namespace std;
const int MAXN=35;

int father[MAXN];

int Size[MAXN];


void build(int N)
{
    for(int i=0;i<N;i++){
        father[i]=i;
        Size[i]=1;
    }
}

int find(int i) //递归版查找+扁平化
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
    father[find(x)]=find(y);
}

int minSwapsCouples(vector<int>& row) {
    int len=static_cast<int>(row.size());
    build(len/2);
    int cnt=0;
    for(int i=0;i<len;i+=2){
        if(!isSameSet(row[i]/2,row[i+1]/2)){
            ++cnt;
            Union(row[i]/2,row[i+1]/2);
        }
    }
    return cnt;
}

int main()
{
    vector<int> v{0,2,1,3};
    cout << minSwapsCouples(v);
}