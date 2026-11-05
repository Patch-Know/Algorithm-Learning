//问source变成dest所有的出入栈可能
//DFS带路径递归
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> ans_arr;

int in_cnt,out_cnt;
string s,d;
int len;
string path;
stack<char> st;
string io_list;

void dfs()
{
    if(out_cnt==len/*&& path==d*/ ){
        ans_arr.push_back(io_list);
        return;
    }

    if(in_cnt<len){
        st.push(s[in_cnt]);
        in_cnt++;
        io_list.push_back('i');
        dfs();
        st.pop();
        in_cnt--;
        io_list.pop_back();
    }

    if(out_cnt<in_cnt && st.top() == d[out_cnt]){ //要求栈顶元素等于 dest 当前需要的字符,检查同时剪枝
        char ch=st.top();
        st.pop();
        //path.push_back(ch);
        out_cnt++;
        io_list.push_back('o');
        dfs();
        st.push(ch);
        //path.pop_back();
        out_cnt--;
        io_list.pop_back();
    }
}

int main()
{
    cout << "source: ";
    getline(cin, s);
    cout << "dest: ";
    getline(cin, d);

    
    if(s.length() != d.length()){
        cout << "输入错误" << endl;
        return 0; 
    }

    len = s.length();
    dfs();
    
    if(ans_arr.empty()) {
        cout << "输入错误" << endl;
    } else {
        for(const auto &str : ans_arr){
            cout << str << '\n';
        }
    }
}
