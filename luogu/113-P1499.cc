#include<iostream>
#include<stack>
#include<cctype>

using namespace std;

int main()
{
    char ch;
    stack<int> num_sign;
    int sum=0,tmp1,tmp2;
    while(cin.get(ch) && ch!='@'){
        if(ch=='.'){
            num_sign.push(sum);
            sum=0;
        }else if(isdigit(ch)){
            sum*=10;
            sum+=ch-'0';
        }else{
            tmp2=num_sign.top();
            num_sign.pop();
            tmp1=num_sign.top();
            num_sign.pop();
            switch(ch){
                case '+':num_sign.push(tmp1+tmp2);break;
                case '-':num_sign.push(tmp1-tmp2);break;
                case '*':num_sign.push(tmp1*tmp2);break;
                case '/':num_sign.push(tmp1/tmp2);break;
            }
        } 
    }
    cout << num_sign.top();
    return 0;
}