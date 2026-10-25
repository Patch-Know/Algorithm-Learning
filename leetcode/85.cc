//最大矩形
//用的是84.cc的函数

#include<vector>
#include<algorithm>

using namespace std;

int largestRectangleArea2(const vector<int>& heights) {
    int max_area=0;
    int n=heights.size();
    vector<int> st(n);
    int r=0;
    for(int i=0;i<n;i++){
        while(r>0 && heights[st[r-1]]>=heights[i]){
            int pop=st[--r];
            int l_bd=r>0?st[r-1]:-1;
            max_area=max(max_area,(i-1-l_bd)*heights[pop]);
        }
        st[r++]=i;
    }
    while(r>0){ //清算
        int pop=st[--r];
        int l_bd=r>0?st[r-1]:-1;   
        max_area=max(max_area,(n-1-l_bd)*heights[pop]);
    }
    
    return max_area;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> heights(n,0);
    int max_area=0;
    for(int i=0;i<m;i++){
        const auto &v=matrix[i];
        for(int j=0;j<n;j++){
            heights[j]=v[j]=='0'?0:heights[j]+1;
        }
        max_area=max(max_area,largestRectangleArea2(heights));
    }
    return max_area;
}