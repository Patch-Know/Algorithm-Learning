//并查集

#include<iostream>

const int MAXN=1e6+1;

int father[MAXN];

int size[MAXN];

int stack[MAXN];

int N,M;

void build()
{
    for(int i=1;i<=N;i++){
        father[i]=i;
        size[i]=1;
    }
}

int find(int i)
{
    int size=0;
    while(i!=father[i]){
        stack[size++]=i;
        i=father[i];
    }
    while (size>0){ //扁平化
        father[stack[--size]]=i;
    }
    return i;
}

bool isSameSet(int x,int y)
{
    return find(x)==find(y);
}

void Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){ //小挂大
        if(size[fx]>=size[fy]){
            size[fx]+=size[fy];
            father[fy]=fx;
        }else{
            size[fy]+=size[fx];
            father[fx]=fy;
        }
    }
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
        if(op==1){
            cout << (isSameSet(x,y)? "Yes" : "No") << '\n';
        }else{
            Union(x,y);
        }
    }
    return 0;
}