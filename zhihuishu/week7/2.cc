//奇数逆置
//自定义循环队列和栈
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class CirQueue{
private:
    int maxsize;
    vector<T> q;
    int front;
    int rear;
    int cnt;
public:
    CirQueue(int n):maxsize(n),q(vector<T>(maxsize)),front(0),rear(n-1),cnt(0){}

    void push(T x)
    {
        if(cnt<maxsize){
            rear=(rear+1)%maxsize;
            q[rear]=x;
            cnt++;
        }
    }

    T top()
    {
        return q[front];
    }

    void pop()
    {
        front=(front+1)%maxsize;
        cnt--;
    }

    bool empty(){return cnt==0;}

    int size(){return maxsize;}
};

void reverseOdd(CirQueue<int>& sq)
{
    int n=sq.size();
    vector<int> st(n);
    int r=0;
    for(int i=0;i<n;i++){
        int temp=sq.top();
        sq.pop();
        sq.push(temp);
        if(temp%2==1) st[r++]=temp;
    }
    for(int i=0;i<n;i++){
        int temp=sq.top();
        sq.pop();
        if(temp%2==0) sq.push(temp);
        else sq.push(st[--r]);
    }
}

int main()
{
    int n;
    cin >> n;
    CirQueue<int> cq(n);
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        cq.push(temp);
    }
    reverseOdd(cq);
    while(!cq.empty()){
        cout << cq.top() << ' ';
        cq.pop();
    }
}
