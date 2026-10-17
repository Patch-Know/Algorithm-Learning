#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<exception>
#include<limits>
#include<sstream>
using namespace std;

class SeqStack{
private:
    vector<string> s;
    int top;
public:
    SeqStack():s(),top(-1){} //init
    bool isEmpty(){return top==-1;}
    void clear()
    {
        top=-1;
        s.clear();
    }
    int size(){return top+1;}
    void push(string str)
    {
        s.push_back(str);
        top++;
    }
    bool pop()
    {
        if(top==-1) return false;
        s.pop_back();
        top--;
        return true;
    }
    string topValue() {
        if (top == -1) return "";
        return s[top];
    }
    double prefix(string prefix_ex[], int n) {
        clear();
        try {
            // 前缀表达式：从右往左扫描
            for (int i = n - 1; i >= 0; --i) {
                string tok = prefix_ex[i];

                // 判断是不是运算符
                if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                    // 运算符至少需要两个操作数
                    if (size() < 2) {
                        return numeric_limits<double>::quiet_NaN();
                    }

                    // 从右往左扫描时，先弹出的是左操作数，再弹出的是右操作数
                    double left = stod(topValue()); pop();
                    double right = stod(topValue()); pop();

                    double temp = 0;
                    switch (tok[0]) {
                        case '+': temp = left + right; break;
                        case '-': temp = left - right; break;
                        case '*': temp = left * right; break;
                        case '/':
                            if (right == 0) {
                                return numeric_limits<double>::quiet_NaN();
                            }
                            temp = left / right;
                            break;
                    }
                    push(to_string(temp));
                } else {
                    // 不是运算符，必须是合法数字
                    size_t pos;
                    double val = stod(tok, &pos);
                    if (pos != tok.size()) {
                        return numeric_limits<double>::quiet_NaN();
                    }
                    push(tok);
                }
            }

            // 最终栈里必须只剩下一个结果
            if (size() != 1) {
                return numeric_limits<double>::quiet_NaN();
            }
            return stod(topValue());
        }
        catch (...) {
            return numeric_limits<double>::quiet_NaN();
        }
    }
    void ex_error(){cout << "illegal expression";}
};

int main()
{
    SeqStack st;
    string temp;
    getline(cin,temp);
    istringstream iss(temp);
    vector<string> v;
    int cnt=0;
    while(iss >> temp){
        v.push_back(temp);
        cnt++;
    }
    string *pre_ex=new string[cnt];
    for(int i=0;i<cnt;i++){
        pre_ex[i]=v[i];
    }
    double res=st.prefix(pre_ex,cnt);
    if(res!=res) st.ex_error();
    else cout << res;

}