#include<iostream>

using namespace std;

int main()
{
    int count=0;
    while(cin.peek()!=EOF && cin.peek()!='$'){
        count++;
        cin.get();
    }
    cout << endl<< count <<" character(s)";
    return 0;
}