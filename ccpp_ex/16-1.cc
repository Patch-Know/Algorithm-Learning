#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
bool is_pa(const string & s);

int main()
{
    string s0;
    cout << "Please enter a string: \n";
    while (getline(cin,s0) && s0[0]!='\0')
    {
        cout << s0 << ": " << boolalpha  << is_pa(s0) << endl;
        cout << "Please enter a string: \n";
    }
    cout << "Bye!\n";
    return 0;
}

bool is_pa(const string & s)
{
    string r(s.rbegin(),s.rend());
    return s == r ? true : false;
}