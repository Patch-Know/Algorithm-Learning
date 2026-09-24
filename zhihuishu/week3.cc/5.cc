//输出单链表倒数第 K 个结点值

#include<iostream>

using namespace std;

struct Node{
    int num;
    Node * nxt;
    Node(int number):num(number),nxt(nullptr)
    {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    if(k<=0){
        cout << "Not Found";
        return 0;
    }

    int len=0;

    int num;
    if(cin >> num){
        len++;
    }else{
        cout << "Not Found";
        return 0;
    }
    Node *head=new Node(num),*pn=head;

    while(cin >> num){
        len++;
        pn->nxt=new Node(num);
        pn=pn->nxt;
    }

    pn=head;

    int forward_cnt=len-k;
    if(forward_cnt<0){
        cout << "Not Found";
        return 0;
    }
    while(forward_cnt>0){
        pn=pn->nxt;
        forward_cnt--;
    }
    cout << pn->num;
}