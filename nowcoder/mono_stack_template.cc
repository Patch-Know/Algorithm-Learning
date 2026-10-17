#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans_l(n),ans_r(n); //index
    vector<int> st(n); //index
    int r=0;
    for(auto &x:arr) cin >> x;
    for(int i=0;i<n;i++){ //遍历
        while(r>0 && arr[st[r-1]]>=arr[i]){
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
        if(ans_r[i]!=-1 && arr[ans_r[i]]==arr[i]) ans_r[i]=ans_r[ans_r[i]];
    }
    for(int i=0;i<n;i++){
        cout << ans_l[i] << ' ' << ans_r[i] << '\n'; 
    }
}