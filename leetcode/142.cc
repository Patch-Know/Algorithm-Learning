//环形链表找入环节点

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    //特殊情况判断
    if(!head || !head->next) return NULL;
    if(head->next->next==head) return head;
    //快慢指针
    ListNode * fast=head, * slow=head;
    do{ //找第一次相遇位置
        slow=slow->next;
        if(!fast || !fast->next) return NULL;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(fast!=slow){ //第二次相遇即入环节点
        fast=fast->next;
        slow=slow->next;
    }
    return fast;
}