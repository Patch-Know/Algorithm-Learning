#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> iniarr;
        for(auto node:lists){
            while(node){
                iniarr.push_back(node->val);
                node=node->next;
            }
        }
        priority_queue<int,vector<int>,greater<int>> heap(iniarr.begin(),iniarr.end());
        ListNode * head=nullptr,*pnode;
        if(!heap.empty()){
            head=new ListNode(heap.top());
            pnode=head;
            heap.pop();
        }
        while(!heap.empty()){
            pnode->next=new ListNode(heap.top()); //注意保存地址的位置不是pnode!!
            pnode=pnode->next;
            heap.pop();
        }
        return head;
    }
};