#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> a;
    vector<string> formal{"", "one" ,"two", "three" ,"four", "five",
         "six" ,"seven" ,"eight" ,"nine" ,"ten" ,"eleven" ,"twelve" ,"thirteen"
          "fourteen", "fifteen", "sixteen" ,"seventeen", "eighteen", "nineteen" ,"twenty"};
    vector<string> informal{"a","another","first","both","second","third"};
    string temp;
    while (cin >> temp && temp!=".")
    {
        if(formal.end()!=find(formal.begin(),formal.end(),temp)){
            a.push_back(static_cast<int>(find(formal.begin(),formal.end(),temp)-formal.begin()));
        }else if(informal.end()!=find(informal.begin(),informal.end(),temp)){
            int num=static_cast<int>(find(informal.begin(),informal.end(),temp)-informal.begin());
            if(num<3) num=1;
            else if(num<5) num=2;
            else num=3;
            a.push_back(num);
        }
        

    }
    for(int & x:a){
        x=x*x%100;
    }
    sort(a.begin(),a.end());
    int sum=0;
    for(int x:a){
        sum*=100;
        sum+=x;
    }
    cout << sum;
    
    // bool is_first = true;
    // for(int x:a){
    //     if(is_first){ 
    //         cout << x;
    //         is_first=false;
    //     }
    //     else cout << (x<10? '0':'\0') << x;

    // }
    
    return 0;
}