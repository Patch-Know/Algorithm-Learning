#include<iostream>
#include<algorithm>
using namespace std;

template<typename T>
class CirLinkList{
private:
    int size;
    struct node{
        T val;
        node *next;
        node(int x):val(x),next(nullptr){}
    };

    node *head;
public:
    CirLinkList():size(0),head(nullptr){}

    void Insert(int pos,T x)
    {
        if(pos==1){
            head=new node(x);
            head->next=head;
        }else{
            node *pn=head;
            for(int i=1;i<pos-1;i++){
                pn=pn->next;
            }
            node *new_next=pn->next;
            pn->next=new node(x);
            pn->next->next=new_next;
        }
        size++;
    }

    void PrintOrdered_clear()
    {
        node *pn=head;
        while(size>0){
            int min_val=pn->val;
            int cnt=0;
            while(cnt++<size){
                min_val=min(min_val,pn->val);
                pn=pn->next;
            }
            cnt=0;
            while(cnt++<size){
                node *nxt_pn=pn->next;
                if(nxt_pn->val==min_val){
                    pn->next=nxt_pn->next;
                    cout << min_val << ' ';
                    delete nxt_pn;
                    size--;
                    cnt--;
                }else{
                    pn=nxt_pn;
                }
            }
        }
    }
};

int main() { 

  int n, x;    

  CirLinkList<int> L;
  cin >> n;   

  for (int i = 1; i <= n; i++) { 

       cin >> x;       

       L.Insert(i, x);    }       

  L.PrintOrdered_clear();   

 return 1;
}