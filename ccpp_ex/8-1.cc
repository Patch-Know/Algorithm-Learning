#include<iostream>

void prstr(const char* str,int n=1);

int main()
{
    prstr("I love my mum.");
}

void prstr(const char* str,int n)
{
    for (int i=0;i<n;i++){
        std::cout<<str<<std::endl;
    }
}