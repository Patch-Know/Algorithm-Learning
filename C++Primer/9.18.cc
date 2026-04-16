#include<iostream>
#include<list>
#include<deque>
#include<string>
using namespace std;

int main()
{
    string temp;
    deque<string> d;
    cout << "Enter a string: ";          
    while (getline(cin,temp) && temp[0]!='\0')
    {
        d.push_back(temp);
        cout << "Enter a string: ";
    }
    for(auto  i = d.begin();i!=d.end();i++){
        cout << *i << endl;
    }
    return 0;
}
