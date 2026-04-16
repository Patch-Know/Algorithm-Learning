#include<bits/stdc++.h>
using namespace std;

int a[26];

int main()
{
    int max=0,min=999;
    string temp;
    bool lucky=false;
    getline(cin,temp);
    for(char x:temp){
        a[x-'a']++;
    }
    int zhishu[25]=
    {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    //质数表，100以内足够用了
    for(int x:a){
        if(x!=0){
            if(x>max) max=x;
            if(x<min) min=x;
        }
    }
    for(int x:zhishu){
        if(x==max-min){
            lucky=true;
            break;
        }
    }
    if(lucky){
        cout << "Lucky Word\n" << max-min;
    }else{
        cout << "No Answer\n" << 0;
    }
    return 0;
}