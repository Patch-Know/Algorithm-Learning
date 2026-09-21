//字符串次序调整

#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a=0,b=0,c=0;
    string s;
    getline(cin,s);
    for(char ch:s){
        switch(ch){
            case 'a':a++;break;
            case 'b':b++;break;
            case 'c':c++;break;
        }
    }
    cout << string(b,'b') << string(a,'a') << string(c,'c');
}