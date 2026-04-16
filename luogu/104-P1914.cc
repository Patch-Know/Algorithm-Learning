#include<string>
#include<cctype>
#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
    int n;
    cin >>n;
    cin.get();
    char ch;
    while (cin.get(ch) && ch!='\n')
    {
        ch ='a' + (ch-'a'+n)%26;
        cout <<ch;
    }
    
    return 0;
}
