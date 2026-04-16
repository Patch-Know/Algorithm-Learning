#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<algorithm>

using namespace std;
bool is_pa(const string & s);
string & be_simple(const string & s1,string & s2);
bool is_PA(const string & s);

int main()
{
    string s0;
    cout << "Please enter a string: \n";
    while (getline(cin,s0) && s0[0]!='\0')
    {
        cout << s0 << ": " << boolalpha  << is_PA(s0) << endl;
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

string & be_simple(const string & s1,string & s2)
{
    copy_if(s1.begin(),s1.end(),s2.begin(),[](char ch){return (bool)isalnum(ch);});
    size_t newSize = s2.find_last_not_of('\0'); // 下标从零开始，最后一个字符位置比length或size小1
    s2.resize(newSize+1);
    transform(s2.begin(),s2.end(),s2.begin(),::tolower);
    return s2;
}

bool is_PA(const string & s)
{
    string r;
    r.resize(s.size());
    return is_pa(be_simple(s,r));
}

