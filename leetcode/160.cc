/*
给你两个单链表的头节点 headA 和 headB ，
请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null 
*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int cnt_A=0,cnt_B=0;
    ListNode *pa=headA, *pb=headB;
    while(pa){
        ++cnt_A;
        pa=pa->next;
    }
    while(pb){
        ++cnt_B;
        pb=pb->next;
    }
    pa=headA;
    pb=headB;
    if(cnt_A>cnt_B){
        for(int i=0;i<cnt_A-cnt_B;i++){
            pa=pa->next;
        }
    }else{
        for(int i=0;i<cnt_B-cnt_A;i++){
            pb=pb->next;
        }
    }
    while(pa!=NULL && pa!=pb){
        pa=pa->next;
        pb=pb->next;
    }
    return pa;
}