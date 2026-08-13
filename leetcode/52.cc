//N皇后
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int path[15];

int cnt;

const string s="abcdefghijklmnopqrstuvwxyz";

bool check(int path[],int i,int j)
{
    for(int k=0;k<i;k++){
        if(j==path[k] || abs(i-k)==abs(j-path[k])) 
            return false;
    }
    return true;
}

const string file="N_queen.txt";


//control out
#define VISUAL
//#define FILE_OUT

#ifdef FILE_OUT
ofstream output(file);
#endif

int f1(int path[],int i,int n)
{
    if(i==n){
        //visualize
        #ifdef VISUAL
        #ifndef FILE_OUT
        cout << '<' << ++cnt << '>' << '\n';
        cout << ' ' << ' ';
        cout << s.substr(0,n) << '\n';
        cout << ' ' << ' ';
        cout << string(n,'-') << '\n';
        for(int j=0;j<n;j++){
            cout << to_string(j+1);
            if(j+1<10) cout << ' ';
            cout << string(path[j],' ') << '0' << '\n';
        }
        cout << ' ' << ' ';
        cout << string(n,'-') <<'\n' << '\n' << '\n';
        #else
        output << '<' << ++cnt << '>' << '\n';
        output << ' ' << ' ';
        output << s.substr(0,n) << '\n';
        output << ' ' << ' ';
        output << string(n,'-') << '\n';
        for(int j=0;j<n;j++){
            output << to_string(j+1);
            if(j+1<10) output << ' ';
            output << string(path[j],' ') << '0' << '\n';
        }
        output << ' ' << ' ';
        output << string(n,'-') <<'\n' << '\n' << '\n';
        #endif
        #endif
        return 1;
    }
    int ans=0;
    for(int j=0;j<n;j++){
        if(check(path,i,j)){
            path[i]=j;
            ans+=f1(path,i+1,n);
        }
    }
    return ans;
}

int totalNQueens1(int n) {
    if(n<1) return 0;
    return f1(path,0,n);
}

int f2(unsigned limit,unsigned col,unsigned left,unsigned right)
{
    if(col==limit) return 1;
    unsigned ban=col | left | right;
    unsigned candidate=limit&(~ban);
    unsigned place=0;
    int ans=0;
    while(candidate!=0){
        place=candidate&(-candidate); //提取最右侧的1，注意不能写错
        candidate^=place;
        ans+=f2(limit,col | place,(left | place)>>1,(right | place)<<1);
    }
    return ans;
}

int totalNQueens2(int n) {
    if(n<1) return 0;
    return f2((1u<<n)-1u,0,0,0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << totalNQueens1(10);
    return 0;
}