//相似字符串组

//并查集，情侣牵手

#include<iostream>
#include<vector>
using namespace std;
const int MAXN=301;

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
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){ 
        father[fx]=fy;
        sets--;
    }
}

int numSimilarGroups(vector<string>& strs) {
    int n=static_cast<int>(strs.size());
    int m=static_cast<int>(strs[0].length());
    build(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(!isSameSet(i,j)){ //提前判断优化
                int diff=0;
                for(int k=0;k<m && diff<3;k++){ //判别优化！！减少循环！！
                    if(strs[i][k]!=strs[j][k]){
                        diff++;
                    }
                }
                if(diff==0 || diff==2){
                    Union(i,j);
                }
            }
        }
    }
    return sets;
}