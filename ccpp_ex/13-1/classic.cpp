#include<iostream>
#include<cstring>
#include<iomanip>
#include"classic.h"

CD::CD():performance("none"),label("none"),selections(0),playtime(0)
{
}

CD::CD(const CD & d):selections(d.selections),playtime(d.playtime)
{
    using std::strcpy;
    strcpy(performance,d.performance);
    strcpy(label,d.label);
}

CD::CD(const char * s1,const char * s2 , int n, double x) : selections(n),playtime(x)
{
    using std::strncpy;
    strncpy(performance,s1,50);
    strncpy(label,s2,20);
}

Classic::Classic():CD(),mainwork("none"){}

Classic::Classic(const Classic & d):CD(d),mainwork("none"){}
Classic::Classic(const char * s1,const char * s2 ,const char * s3, int n, double x):CD(s1,s2,n,x)
{
    std::strcpy(mainwork,s3);
}



void CD::Report() const 
{
    using namespace std;
    cout << setw(20) << left << "performance:" << setw(10) << right << performance <<endl;
    cout << setw(20) << left << "label:" << setw(10) << right << label <<endl;
    cout << setw(20) << left << "selections:" << setw(10) << right << selections <<endl;
    cout << setw(20) << left << "playtime:" << setw(10) << right << playtime <<endl;
}

void Classic::Report() const
{
    CD::Report();
    using namespace std;
    cout << setw(20) << left << "mainwork:" << setw(10) << right << mainwork <<endl;
}

CD & CD::operator=(const CD & d)
{
    if (this==&d) return *this;
    using std::strcpy;
    strcpy(performance,d.performance);
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
    return * this;
}

Classic & Classic::operator=(const Classic & d)
{
    if (this==&d) return *this;
    CD::operator=(d);
    using std::strcpy;
    strcpy(mainwork,d.mainwork);
    return * this;
}