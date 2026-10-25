#include<iostream>
#include<string>
#include <stdexcept>
#include<vector>
using namespace std;

template<typename T>
class Stack {
private:
    std::vector<T> data;   // 底层顺序存储

public:
    // 入栈：将元素压入栈顶
    void push(const T& value) {
        data.push_back(value);
    }

    // 出栈：删除栈顶元素（不返回）
    void pop() {
        if (data.empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        data.pop_back();
    }

    // 返回栈顶元素的引用（可修改）
    T& top() {
        if (data.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return data.back();
    }

    // const 版本，用于 const 对象
    const T& top() const {
        if (data.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return data.back();
    }

    // 判断栈是否为空
    bool empty() const {
        return data.empty();
    }

    // 返回栈中元素个数（辅助方法）
    size_t size() const {
        return data.size();
    }
};

string stringdeal(string s)
{
    Stack<char> st;
    for(auto it=s.crbegin();it!=s.crend();it++){
        if(st.empty()||st.top()!=*it){
            st.push(*it);
        }else st.pop();
    }
    string ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main() {

  string s;

  cin >> s;

  cout << stringdeal(s);

}