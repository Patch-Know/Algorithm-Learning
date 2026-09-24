//有序表的差集

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
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
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int num;
    
    istringstream ss1(s1);
    ss1 >> num;
    Node *ha=new Node(num),*pa=ha;
    while(ss1 >> num){
        pa->nxt=new Node(num);
        pa=pa->nxt;
    }

    istringstream ss2(s2);
    ss2 >> num;
    Node *hb=new Node(num),*pb=hb;
    while(ss2 >> num){
        pb->nxt=new Node(num);
        pb=pb->nxt;
    }

    vector<int> res;

    pa=ha,pb=hb;
    while(pa){
        while(pb && pb->num<pa->num){
            pb=pb->nxt;
        }
        if(!pb || pb->num!=pa->num){
            res.push_back(pa->num);
        }
        pa=pa->nxt;
    }
    
    for(int num:res) cout << num << ' ';
    if(res.empty()) cout << "empty";
}