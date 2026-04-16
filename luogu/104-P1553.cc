#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s,a,b;
    getline(cin,s);
    auto sign=s.find_first_of("./%");
    if(sign==string::npos){
        reverse(s.begin(),s.end());
        auto not_zero=s.find_first_not_of('0');
        if(not_zero==0) cout << s;
        else if(not_zero==string::npos) cout << 0;
        else{
            s.erase(0,not_zero);
            cout << s;
        }
    }else if(s[sign]=='%'){
        s.erase(sign);
        reverse(s.begin(),s.end());
        auto not_zero=s.find_first_not_of('0');
        if(not_zero==0) cout << s;
        else if(not_zero==string::npos) cout << 0;
        else{
            s.erase(0,not_zero);
            cout << s;
        }
        cout << '%';
    }else{
        a=s.substr(0,sign);
        b=s.substr(sign+1);
        reverse(a.begin(),a.end());
        auto not_zero=a.find_first_not_of('0');
        if(not_zero==0) cout << a;
        else if(not_zero==string::npos) cout << 0;
        else{
            a.erase(0,not_zero);
            cout << a;
        }
        cout << s[sign];
        reverse(b.begin(),b.end());
        auto not_zero_left=b.find_first_not_of('0');
        auto not_zero_right=b.find_last_not_of('0');
        if(not_zero_left==string::npos && not_zero_right==string::npos) cout << 0;
        else{
            if(not_zero_right!=b.size()-1) b.erase(not_zero_right+1);
            if(not_zero_left!=0) b.erase(0,not_zero_left);
            cout << b;
        }
    }
    return 0;
}