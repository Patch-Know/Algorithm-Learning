//柱状图中最大的矩形

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int largestRectangleArea1(vector<int>& heights) {
    int max_area=0;
    int n=heights.size();
    vector<int> st(n);
    vector<int> ans_l(n),ans_r(n);
    int r=0;
    for(int i=0;i<n;i++){
        while(r>0 && heights[st[r-1]]>=heights[i]){
            ans_r[st[--r]]=i;
            ans_l[st[r]]=r==0?-1:st[r-1];
        }
        st[r++]=i;
    }
    while(r>0){ //清算
        ans_r[st[--r]]=-1;
        ans_l[st[r]]=r==0?-1:st[r-1];
    }
    for(int i=n-1;i>=0;i--){ //修正
        if(ans_r[i]!=-1 && heights[ans_r[i]]==heights[i]) ans_r[i]=ans_r[ans_r[i]];
    }

    for(int i=0;i<n;i++){
        if(ans_l[i]==-1 && ans_r[i]==-1){
            max_area=max(max_area,heights[i]*n);
        }else if(ans_l[i]==-1){
            max_area=max(max_area,heights[i]*(ans_r[i]));
        }else if(ans_r[i]==-1){
            max_area=max(max_area,heights[i]*(n-ans_l[i]-1));
        }else{
            max_area=max(max_area,heights[i]*(ans_r[i]-ans_l[i]-1));
        }
    }
    return max_area;
}

//弹出时结算!总有一个能算对!看视频!

int largestRectangleArea2(vector<int>& heights) {
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

int main()
{
    vector<int> v{2,1,5,6,2,3};
    cout << largestRectangleArea2(v);
}