#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct node{
    int x;
    node * nxt;
    node(int num):x(num),nxt(nullptr){}
};

int main()
{
    node * head = nullptr;
    int len = 0;
    string line;

    while(true){
        // ========== 1. 读取“链表现状行” ==========
        bool hasLine = false;
        while(getline(cin, line)){
            if(!line.empty()){ // 跳过空行
                hasLine = true;
            }
            break;
        }
        if(!hasLine) break; // 输入结束

        if(line == "-1"){
            // 沿用前一个单链表，head 和 len 保持不变
        } else {
            // 否则，不管数字个数，一律视为新链表，重新构建
            vector<int> nums;
            istringstream iss(line);
            string item;
            while(getline(iss, item, ',')){
                if(item.empty()) continue;
                nums.push_back(stoi(item));
            }
            // （可选：释放旧链表内存）
            // while(head){ node* t = head; head = head->nxt; delete t; }
            
            if(!nums.empty()){
                head = new node(nums[0]);
                node * pn = head;
                len = nums.size();
                for(int i = 1; i < len; i++){
                    pn->nxt = new node(nums[i]);
                    pn = pn->nxt;
                }
            } else {
                head = nullptr;
                len = 0;
            }
        }

        // ========== 2. 读取“操作指令行” ==========
        hasLine = false;
        while(getline(cin, line)){
            if(!line.empty()){
                hasLine = true;
                break;
            }
        }
        if(!hasLine) break; // 输入结束

        int a, b;
        char comma;
        istringstream opSS(line);
        opSS >> a >> comma >> b;

        if(!head) continue; // 防御：空链表无法操作

        // 输出原链表
        cout << head->x;
        node * pn = head->nxt;
        while(pn){
            cout << ',' << pn->x;
            pn = pn->nxt;
        }
        cout << endl;

        // ========== 3. 执行操作（原逻辑保留） ==========
        switch(a){
            case 1: {
                pn = head;
                for(int i = 0; i < len - b - 1; i++){
                    pn = pn->nxt;
                }
                node * next = pn->nxt;
                pn->nxt=nullptr; //注意断开连接
                for(int i = 0; i < b; i++){
                    node * nextnext = next->nxt;
                    next->nxt = pn;
                    pn = next;
                    next = nextnext;
                }
                node * ph = head;
                for(int i = 0; i < b; i++){
                    node * ph_nxt = ph->nxt;
                    node * pn_nxt = pn->nxt;
                    ph->nxt = pn;
                    pn->nxt = ph_nxt;
                    ph = ph_nxt;
                    pn = pn_nxt;
                }
                break;
            }
            case 2: {
                pn = head;
                for(int i = 0; i < b; i++){
                    pn = pn->nxt;
                }
                node * temp = pn->nxt;
                pn->nxt = nullptr;
                pn = temp;

                node * ph = head;
                while(ph && pn){
                    node * ph_nxt = ph->nxt;
                    node * pn_nxt = pn->nxt;
                    ph->nxt = pn;
                    pn->nxt = ph_nxt;
                    ph = ph_nxt;
                    pn = pn_nxt;
                }
                // 如果后半部分还有剩余，追加到链表末尾
                if(pn){
                    node * tail = head;
                    while(tail->nxt){
                        tail = tail->nxt;
                    }
                    tail->nxt = pn;
                }
                break;
            }     
            case 3: {
                pn = head;
                int cnt = 0;
                while(pn->nxt){
                    if(pn->nxt->x == b){
                        cnt++;
                        node * next = pn->nxt->nxt;
                        delete pn->nxt;
                        pn->nxt = next;
                        pn = next;
                    }else{
                        pn = pn->nxt;
                    }
                }
                for(int i = 0; i < cnt; i++){
                    pn->nxt = new node(b);
                    pn = pn->nxt;
                }
                break;
            }
        }

        // 输出调整后的链表
        cout << head->x;
        pn = head->nxt;
        while(pn){
            cout << ',' << pn->x;
            pn = pn->nxt;
        }
        cout << endl;
    }

    return 0;
}