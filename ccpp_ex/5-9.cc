#include<iostream>
#include<string>
using namespace std;
const int Size=30;

int main(){
    string temp;
    int num=0;
    cout<<"Enter words (to stop, type the word done):\n";
    cin>>temp;
    while (temp!="done")
    {
        ++num;
        cin>>temp;
    }
    cout <<"You entered a total of "<<num<<" words.\n";
    
    return 0;
}