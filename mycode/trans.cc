#include<iostream>
#include<string>

int main()
{
    using namespace std;
    string s;
    while (getline(cin,s)) cout<<'\"'<<s<<"\","<<endl;
    return 0;
}