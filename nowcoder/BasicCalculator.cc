#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

int where;

int calculate(const string & s,int i,const int len)
{
    int ans=0;
    int num=0;
    stack<int> nums;
    stack<char> syms;
    while(i<len && s[i]!=')'){
        if(s[i]=='('){
            num=calculate(s,i+1,len);
            i=where;
        }else if(s[i]>='0' && s[i]<='9'){
            num=num*10+(s[i]-'0');
        }else if(syms.empty() || syms.top()=='+' || syms.top()=='-'){
            nums.push(num);
            syms.push(s[i]);
            num=0;
        }else{
            int lhs=nums.top();
            int rhs=num;
            num=0;
            nums.pop();
            nums.push(syms.top()=='*' ? lhs*rhs : lhs/rhs);
            syms.pop();
            syms.push(s[i]);
        }
        i++;
    }
    where=i;
    
    if(syms.empty() || syms.top()=='+' || syms.top()=='-') nums.push(num);
    else{
        int lhs=nums.top();
        int rhs=num;
        nums.pop();
        nums.push(syms.top()=='*' ? lhs*rhs : lhs/rhs);
        syms.pop();
    }
    
    while(!syms.empty()){
        ans+=syms.top()=='+' ? nums.top() : nums.top()*(-1);
        nums.pop();
        syms.pop();
    }
    ans+=nums.top();
    nums.pop();
    return ans;
}

int solve(string s) {
    return calculate(s,0,static_cast<int>(s.length()));
}

int main()
{
    string s="(2*(3-4))*5";
    int ans=calculate(s,0,static_cast<int>(s.length()));
    cout << ans << endl;
    return 0;
}