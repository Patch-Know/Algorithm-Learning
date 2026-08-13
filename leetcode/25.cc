/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode * firstnode,*lastnode,*nextgroup,*pnode,*prenode,*curnode,*lastgroupend;
    //第一组特殊考虑，不用排除特殊情况
    pnode=firstnode=head;
    for(int i=0;i<k-1;i++){
        pnode=pnode->next;
    }
    lastnode=pnode;
    nextgroup=lastnode->next;
    head=lastnode; //返回的头指针指向第一组尾位置
    prenode=nextgroup;
    pnode=firstnode;
    for(int i=0;i<k;i++){
        curnode=pnode;
        pnode=pnode->next; //at last,pnode==nextgroup
        curnode->next=prenode;
        prenode=curnode; 
    }
    lastgroupend=firstnode;
    //剩下的组循环
    while(1){
        //排除特殊情况并标记首尾位置
        firstnode=nextgroup;
        for(int i=0;i<k-1;i++){ //遇到不足k个的情况就跳出并返回
            if(!pnode) break;
            pnode=pnode->next;
        }
        if(!pnode) break;;
        lastnode=pnode;
        nextgroup=lastnode->next;
        //和第一组唯一不同的地方，调整指向首位置的指针，指向翻转后的首位置
        lastgroupend->next=lastnode; 
        //以下代码改变一组k个节点每一个的指向
        prenode=nextgroup;
        pnode=firstnode;
        for(int i=0;i<k;i++){
            curnode=pnode;
            pnode=pnode->next; //at last,pnode==nextgroup
            curnode->next=prenode;
            prenode=curnode; 
        }
        //下一组要用到的上一组尾位置
        lastgroupend=firstnode;
    }
    return head;
}