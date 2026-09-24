//reverse singly linked list

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
    int n;
    cin >> n;
    if(n<=0){
        cout << "empty";
        return 0;
    }

    int num;
    cin >> num;
    Node *head=new Node(num),*pn=head;
    for(int i=1;i<n;i++){
        cin >> num;
        pn->nxt=new Node(num);
        pn=pn->nxt;
    }

    Node *cur_node=nullptr,*nxt_node=head;
    while(nxt_node){
        Node *nxtnxt=nxt_node->nxt;
        nxt_node->nxt=cur_node;
        cur_node=nxt_node;
        nxt_node=nxtnxt;
    }
    while(cur_node){
        cout << cur_node->num << ' ';
        cur_node=cur_node->nxt;
    }
}