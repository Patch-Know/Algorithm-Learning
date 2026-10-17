#include<iostream>
#include<string>
#include<stack>

using namespace std;

int pair_match(string s)
{
    stack<char> st;
    for(char ch:s){
        if(ch=='(' || ch=='[' || ch=='{'){
            st.push(ch);
        }else{
            char temp;
            switch(ch){
                case ')':temp='(';break;
                case ']':temp='[';break;
                case '}':temp='{';break;
                default:continue;
            }
            if(st.empty()||st.top()!=temp) return 0;
            st.pop();
        }
    }
    if(!st.empty()) return 0;
    return 1;
}

int main() {

  string s;

  cin >> s;

  cout << pair_match(s);

}