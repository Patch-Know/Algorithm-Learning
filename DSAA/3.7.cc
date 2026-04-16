#include<iostream>
#include<list>

using namespace std;


struct Node
{
    long long c;
    unsigned long long e;
};

typedef list<Node> Polynomial;

Polynomial mt_p(const Polynomial & a,const Polynomial & b);

int main()
{
    Polynomial a = {
        {3,0},
        {5,1},
        {6,2}
    };
    Polynomial b = {
        {2,1},
        {8,3},
        {1,5}
    };
    Polynomial c = mt_p(a,b);
    for(auto r = a.crbegin();r!=a.crend();r++){
        if(r!=a.crbegin()) cout << " + ";
        cout << r->c << "x^" << r->e;
    }
    cout << endl << "*" << endl;
    for(auto r = b.crbegin();r!=b.crend();r++){
        if(r!=b.crbegin()) cout << " + ";
        cout << r->c << "x^" << r->e;
    }
    cout << endl << "=" << endl;
    for(auto r = c.crbegin();r!=c.crend();r++){
        if(r!=c.crbegin()) cout << " + ";
        cout << r->c << "x^" << r->e;
    }
    cout << endl;   
    return 0;
}

Polynomial mt_p(const Polynomial & a,const Polynomial & b)
{
    const Polynomial & M = a.size() < b.size() ? a : b;
    const Polynomial & N = a.size() < b.size() ? b : a;
    Polynomial mt;
    Node tpnode;
    Polynomial::iterator pos;
    mt.push_back({M.front().c*N.front().c,M.front().e+N.front().e});
    for(auto i = M.begin();i!=M.end();i++){
        auto j = N.begin();
        if(i==M.begin()) j++;
        pos=mt.begin();
        while(j!=N.end()){
            tpnode.c=j->c*i->c;
            tpnode.e=j->e+i->e;
            while(pos!=mt.end() && tpnode.e>pos->e){
                pos++;
            }
            if(pos==mt.end()) mt.push_back(tpnode);
            else if(tpnode.e<pos->e) mt.insert(pos,tpnode);
            else pos->c+=tpnode.c;
            j++;
        }
    }
    return mt;
}


