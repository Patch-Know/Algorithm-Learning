//移除最多的同行或同列石头

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
const int MAXN=1001;

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

int removeStones(vector<vector<int>>& stones) {
    int len=static_cast<int>(stones.size());
    build(len);
    // key : 某行
	// value : 第一次遇到的石头编号
    unordered_map<int,int> rowFirst;
    unordered_map<int,int> colFirst;
    for(int i=0;i<len;i++){
        int row=stones[i][0];
        int col=stones[i][1];
        if(rowFirst.count(row)==0){
            rowFirst[row]=i;
        }else{
            Union(i,rowFirst[row]);
        }
        if(colFirst.count(col)==0){
            colFirst[col]=i;
        }else{
            Union(i,colFirst[col]);
        }
    }
    return len-sets;
}