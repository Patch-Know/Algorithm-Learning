/*
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
构造这个链表的 深拷贝。 
深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
复制链表中的指针都不应指向原链表中的节点 。
*/

#include<iostream>
#include<unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList1(Node* head) { //solution 1,hash_map
    unordered_map<Node *,Node *> m;
    Node * pnode=head;
    while(pnode){
        m[pnode]=new Node(pnode->val);
        pnode=pnode->next;
    }
    pnode=head;
    while (pnode){
        m[pnode]->next=m[pnode->next];
        m[pnode]->random=m[pnode->random];
        pnode=pnode->next;
    }
    return m[head];
}

//solution 2
// 1 -> 2 -> 3 -> ...
// 变成 : 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> ...

Node* copyRandomList2(Node* head) { 
    if(head==NULL) return NULL;
    Node * next,*pnode=head;
    while(pnode){
        next=pnode->next;
        pnode->next=new Node(pnode->val);
        pnode->next->next=next;
        pnode=next;
    }
    pnode=head;
    Node * ans = head->next;
    while(pnode){
        pnode->next->random=pnode->random ? pnode->random->next : NULL;
        pnode=pnode->next->next;
    }
    pnode=head;
    while(pnode){
        next=pnode->next->next;
        pnode->next->next=next ? next->next : NULL;
        pnode->next=next;
        pnode=next;
    }
    return ans;
}