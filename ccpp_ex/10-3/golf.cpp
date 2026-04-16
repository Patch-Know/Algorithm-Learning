#include<iostream>
#include<cstring>
#include"golf.h"



int golf::setgolf()
{
    using std::cout;
    using std::cin;
    using std::getline;
    using std::endl;
    char name[Len];
    int hc=0;
    cout<<"Enter the fullname:\n";
    cin.getline(name,Len);
    if (name[0]=='\0') return 0;
    cout<<"Enter the handicap:\n";
    cin>>hc;
    while (getchar()!='\n') continue;
    *this=golf(name,hc);
    return 1;
}

void golf::sethandicap(int hc)
{
    handicap=hc;
}

void golf::showgolf() const
{
    std::cout<< fullname << " : " << handicap << std::endl;
}