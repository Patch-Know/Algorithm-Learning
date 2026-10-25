//用栈实现队列类

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class StackQueue{
private:
    vector<int> si,so;
public:
    bool empty(){return si.empty()&&so.empty();}

    StackQueue()=default;

    void push(int x)
    {
        si.push_back(x);
        if(so.empty()){
            while(!si.empty()){
                so.push_back(si.back());
                si.pop_back();
            }
        }
    }

    void pop()
    {
        if(!empty()){
            if(so.empty()){
                while(!si.empty()){
                    so.push_back(si.back());
                    si.pop_back();
                }
            }
            so.pop_back();
        }
    }

    int front()
    {
        if(empty()) return -1;
        if(!so.empty()) return so.back();
        return si[0];
    }

    int back()
    {
        if(empty()) return -1;
        if(!si.empty()) return si.back();
        return so[0];
    }
    
};

int main()
{
    StackQueue q;
    char ch;
    int num;
    while(cin >> ch && ch!='Q'){
        if(ch=='A'){
            cin >> num;
            q.push(num);
        }else if(q.empty()){
            cout << "Empty" << '\n';
        }else{
            int temp=q.front();
            q.pop();
            cout << temp << '\n';
        }
    }
}