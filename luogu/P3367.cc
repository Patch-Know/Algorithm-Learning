//并查集只做扁平化（精简版）

//并查集

#include<iostream>

const int MAXN=2e5+1;

int father[MAXN];

int size[MAXN];

int N,M;

void build()
{
    for(int i=1;i<=N;i++){
        father[i]=i;
        size[i]=1;
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

int main()
{
    using std::cin,std::cout;
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    build();
    int op,x,y;
    for(int i=0;i<M;i++){
        cin >> op >> x >> y;
        if(op==2){
            cout << (isSameSet(x,y)? 'Y' : 'N') << '\n';
        }else{
            Union(x,y);
        }
    }
    return 0;
}