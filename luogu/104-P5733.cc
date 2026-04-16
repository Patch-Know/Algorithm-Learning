#include<string>
#include<cctype>
#include<iostream>
#include<algorithm>

using namespace std;

void ToUpper(char & ch);

int main()
{
    string s;
    getline(cin,s);
    for_each(s.begin(),s.end(),ToUpper);
    cout << s;
    return 0;
}

void ToUpper(char & ch)
{
    ch=toupper(ch);
}