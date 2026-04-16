#include<iostream>
#include<forward_list>
#include<string>
using namespace std;

void replace_string(forward_list<string> & fl,string a,string b);

int main()
{
    forward_list<string> fs = {"hehedaren","vscode","devcpp","hehedaren","bangdream"};
    replace_string(fs,"hehedaren","hhd666");
    for(auto & x : fs) cout << x << endl;
    return 0;
}

void replace_string(forward_list<string> & fl,string a,string b)
{
    auto prev = fl.before_begin();
    auto curr = fl.begin();
    bool has_found = false;
    while (curr != fl.end())
    {
        if(*curr == a){
            fl.erase_after(prev);
            curr = fl.insert_after(prev,b);
            has_found = true;
        }
        else{
            prev = curr;
            ++curr;
        }
    }
    if(!has_found) fl.insert_after(prev,b);
}