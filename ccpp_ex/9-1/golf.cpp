#include<iostream>
#include<cstring>
#include"golf.h"

void setgolf(golf & g,const char * name , int hc)
{
    std::strncpy(g.fullname,name,Len);
    g.handicap=hc;
}

int setgolf(golf & g)
{
    using std::cout;
    using std::cin;
    using std::getline;
    using std::endl;
    cout<<"Enter the fullname:\n";
    cin.getline(g.fullname,Len);
    if (g.fullname[0]=='\0') return 0;
    cout<<"Enter the handicap:\n";
    cin>>g.handicap;
    while (getchar()!='\n') continue;
    return 1;
}

void handicap(golf & g,int hc)
{
    g.handicap=hc;
}

void showgolf(const golf & g)
{
    std::cout<< g.fullname << " : " << g.handicap << std::endl;
}