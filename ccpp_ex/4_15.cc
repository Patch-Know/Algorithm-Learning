#include<iostream>

using namespace std;

struct fish
{
    string variety;
    int weight;
    double length;
};

int main(){
    fish* pf=new fish;
    pf->variety="crap";
    pf->weight=40;
    pf->length=36.7;
    cout<< pf <<endl<< sizeof *pf<<endl
    << pf->variety <<'\t' <<pf->length<<endl;
    return 0;
}