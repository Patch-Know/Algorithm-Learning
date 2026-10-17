#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<sstream>
using namespace std;

class SeqStack{
private:
    vector<int> s;
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
    void push(int str)
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
    int topValue() {
        if (top == -1) return -1;
        return s[top];
    }
};

class SeqStack_Card{
private:
    vector<int> s;
    int top;
    unordered_map<int,int> num_pos;
public:
    SeqStack_Card():s(),top(-1),num_pos(){} //init
    bool isEmpty(){return top==-1;}
    void clear()
    {
        top=-1;
        s.clear();
    }
    int size(){return top+1;}
    void push(int x)
    {
        s.push_back(x);
        top++;
        num_pos[x]=top;
    }
    bool pop()
    {
        if(top==-1) return false;
        num_pos.erase(s[top]);
        s.pop_back();
        top--;
        return true;
    }
    int topValue() {
        if (top == -1) return -1;
        return s[top];
    }
    int pop_cnt(int x)
    {
        if(num_pos.find(x)==num_pos.end()) return 0;
        else return size()-num_pos[x];
    }
};

class SeqQueue {
private:
    vector<int> q;
    int front;   // 队头元素下标
    int rear;    // 队尾元素的下一个位置
public:
    SeqQueue() : q(), front(0), rear(0) {}   // init

    bool isEmpty() { return front == rear; }

    void clear() {
        front = 0;
        rear = 0;
        q.clear();
    }

    int size() { return rear - front; }

    void push(int str) {
        q.push_back(str);
        rear++;
    }

    bool pop() {
        if (front == rear) return false;   // 队空
        front++;
        // 队列空了，顺便回收空间，避免 vector 一直增长
        if (front == rear) {
            q.clear();
            front = 0;
            rear = 0;
        }
        return true;
    }

    int frontValue() {
        if (front == rear) return -1;
        return q[front];
    }

    
};

int main()
{
    string temp;
    SeqQueue A,B;
    getline(cin,temp);
    istringstream issa(temp);
    while(issa >> temp){
        A.push(stoi(temp));
    }
    getline(cin,temp);
    istringstream issb(temp);
    while(issb >> temp){
        B.push(stoi(temp));
    }
    if(A.isEmpty() || B.isEmpty()) return 0;

    SeqStack_Card cardpool;
    SeqStack midpool;
    bool turn=true;
    while(true){
        if(turn){
            int num=A.frontValue();
            int cnt=cardpool.pop_cnt(num);
            if(cnt==0){
                cardpool.push(num);
                A.pop();
            }else{
                for(int i=0;i<cnt;i++){
                    midpool.push(cardpool.topValue());
                    cardpool.pop();
                }
                A.pop();
                for(int i=0;i<cnt;i++){
                    A.push(midpool.topValue());
                    midpool.pop();
                }
                A.push(num);
            }
            if(A.isEmpty()){
                cout << "B Win!";
                return 0;
            }
        }else{
            int num=B.frontValue();
            int cnt=cardpool.pop_cnt(num);
            if(cnt==0){
                cardpool.push(num);
                B.pop();
            }else{
                for(int i=0;i<cnt;i++){
                    midpool.push(cardpool.topValue());
                    cardpool.pop();
                }
                B.pop();
                for(int i=0;i<cnt;i++){
                    B.push(midpool.topValue());
                    midpool.pop();
                }
                B.push(num);
            }
            if(B.isEmpty()){
                cout << "A Win!";
                return 0;
            }
        }
        turn=!turn;
    }

}