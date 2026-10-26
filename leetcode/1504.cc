//统计全1子矩形

#include <vector>
#include <algorithm>

using namespace std;

int numMat(vector<int> &v){ //以每一行为底有多少矩形
    int n=v.size();
    vector<int> left_low(n); //index
    vector<int> st(n); //index
    int r=0;
    int blocks=0;
    for(int i=0;i<n;i++){
        while(r>0 && v[st[r-1]]>=v[i]){
            if(v[st[r-1]]==v[i]){
                break;
            }else{
                int pop=st[--r];
                int height=v[pop]-(left_low[pop]==-1?v[i]:max(v[left_low[pop]],v[i]));
                blocks+=height*(i-left_low[pop]-1)*(i-left_low[pop])/2;
            }
        }
        left_low[i]=r>0?st[r-1]:-1;
        st[r++]=i;
    }
    while(r>0){
        int pop=st[--r];
        int height=v[pop]-(left_low[pop]==-1?0:v[left_low[pop]]);
        blocks+=height*(n-left_low[pop]-1)*(n-left_low[pop])/2;
    }
    return blocks;
}

int numSubmat(vector<vector<int>> &mat){
    int m=mat.size();
    int n=mat[0].size();
    vector<int> v(n, 0);
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            v[j]=mat[i][j]==0?0:v[j]+1;
        }
        ans+=numMat(v);
    }
    return ans;
}
