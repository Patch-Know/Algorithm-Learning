#include<iostream>
using namespace std;
#include<cstring>
struct stringy
{
    char* str;
    int ct;
};

void set(stringy & s1,const char*);
void show(stringy & s1,int n=1);
void show(const char* s0,int n=1);

int main(){
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany,testing);
    show(beany);
    show(beany,2);
    testing[0]='D';
    testing[1]='u';
    show(testing);
    show(testing,3);
    show("Done!");
    return 0;
}

void set(stringy & s1,const char* str)
{
    s1.ct=strlen(str);
    s1.str=new char[s1.ct+1];
    strcpy(s1.str,str);
}

void show(stringy & s1,int n)
{
    for (int i=0;i<n;i++){
        cout<<s1.str<<endl;
    }
}

void show(const char* s0,int n)
{
    for (int i=0;i<n;i++){
        cout<<s0<<endl;
    }
}