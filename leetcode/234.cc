//判断回文链表，找中点法

//注意链表前后分离，都指向nullptr

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    ListNode * slow = head,*fast=slow->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode * pre,*cur,*next;
    ListNode * second=slow->next;
    slow->next=nullptr;
    pre=nullptr;
    cur=second;
    while(cur){
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    ListNode * front=head,* back=pre;
    while(back){
        if(front->val!=back->val) return false;
        front=front->next;
        back=back->next;
    }
    cur=pre;
    pre=nullptr;
    while(cur)
    {
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    slow->next=pre;
    return true;
}