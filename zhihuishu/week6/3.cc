#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    vector<int> v{1,3,5,7,9,11,13,15,17,19};
    stack<int> st;
    int a;
    cin >> a;
    bool has_insert=false;
    for(auto it=v.crbegin();it!=v.crend();it++){
        if(!has_insert&&a>=*it){
            st.push(a);
            has_insert=true;
        }
        st.push(*it);
    }
    if(!has_insert) st.push(a);
    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }
}