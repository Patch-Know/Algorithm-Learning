#include<bits/stdc++.h>
using namespace std;
string dan,ci,s;
int cur=-1,ans;
int main()
{
    cin>>ci;
    for(int i=0;i<ci.size();++i)ci[i]=tolower(ci[i]);
    getchar();
    getline(cin,s);
    s+=' ';//这行很重要，关系着最后一个单词会不会扫描到
    for(int i=0;i<s.size();++i)s[i]=tolower(s[i]);
    //因为是对每个字符判断，可以直接得出位置
    for(int i=0;i<s.size();++i)
    {
        //如果遇到空格，判断dan是否为给定单词并统计，清空dan
        if(s[i]==' '){
            if(dan==ci){
                ans++;
                if(cur==-1)cur=i-ci.size();
            }
            dan="";
        }
        //非空格则累加dan
        else dan+=s[i];
    }
    if(ans==0)printf("-1");
    else printf("%d %d",ans,cur);
    return 0;
}