#include<iostream>
#include<string>

using namespace std;

//统计数字时注意多位，注意全局where的改变

int where=-1;

string decodeString(string s);

int main()
{
    cout <<
     decodeString("100[leetcode]") << endl;
    return 0;
}


string decodeString(string s)
{
    // int n=s.length();
    int i=where+1;
    string ret;
    int cnt=0;
    while (i<static_cast<int>(s.length()) && s[i]!=']')
    {
        if(s[i]>='0' && s[i] <='9'){
            int k=s[i]-'0';
            cnt=cnt*10+k;
            if(s[i+1]!='['){
                i++;
                continue;
            }
            where=i+1;
            string s1=decodeString(s);
            // 不可以直接构建string(cnt,s1)
            // ret+=string(cnt,s1);
            for(int i=0;i<cnt;i++){
                ret+=s1;
            }
            cnt=0;
            i=where+1;
        }else{
            ret+=s[i++];
        }
    }
    where=i;
    return ret;
}