//给你一个字符串化学式 formula ，返回 每种原子的数量

#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int where;

map<string,int> calculate(const string & f,int i,const int len)
{
    string element;
    int num=0;
    int mul=0;
    map<string,int> ans;
    map<string,int> sub;
    bool has_sub=false;
    while(i<len && f[i]!=')'){
        if(f[i]=='('){
            if(!has_sub){
                ans[element]+=num*(mul==0 ? 1 : mul);
                num=0;
                mul=0;
            }else{
                has_sub=false;
                for(auto [str,cnt]:sub){
                    ans[str]+=cnt*(mul==0 ? 1 : mul);
                }
                num=0;
                mul=0;
                sub.clear();
            }

            sub=calculate(f,i+1,len);
            has_sub=true;
            i=where;
        }else if(f[i]>='A' && f[i]<='Z'){
            if(!has_sub){
                ans[element]+=num*(mul==0 ? 1 : mul);
                num=1;
                mul=0;
            }else{
                has_sub=false;
                for(auto [str,cnt]:sub){
                    ans[str]+=cnt*(mul==0 ? 1 : mul);
                }
                num=1;
                mul=0;
                sub.clear();
            }
            element=f[i];
        }else if(f[i]>='0' && f[i]<='9'){
            mul=mul*10+(f[i]-'0');
        }else element+=f[i];
        i++;
    }
    where=i;
    if(!has_sub){
        ans[element]+=num*(mul==0 ? 1 : mul);
        num=0;
        mul=0;
    }else{
        has_sub=false;
        for(auto [str,cnt]:sub){
            ans[str]+=cnt*(mul==0 ? 1 : mul);
        }
        num=0;
        mul=0;
        sub.clear();
    }
    return ans;
}

string countOfAtoms(string formula) {
    string ans;
    for(auto [str,cnt]:calculate(formula,0,static_cast<int>(formula.length()))){
        ans.append(str);
        if(str!="" && cnt!=1) ans.append(to_string(cnt));
    }
    return ans;
}

int main()
{
    cout << countOfAtoms("K4(ON(SO3)2)2");
    return 0;
}