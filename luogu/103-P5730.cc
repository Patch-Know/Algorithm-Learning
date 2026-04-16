#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while (cin.get()!='\n')
        continue;
    vector<array<bool,5>> arr;
    char ch;
    int cnt=0;
    while(cin.get(ch)){
        switch(ch){
            case '0': arr.push_back({1,1,1,1,1});
                      arr.push_back({1,0,0,0,1});
                      arr.push_back({1,1,1,1,1});
                      break;
            case '1': arr.push_back({0,0,0,0,0});
                      arr.push_back({0,0,0,0,0});
                      arr.push_back({1,1,1,1,1});
                      break;
            case '2': arr.push_back({1,1,1,0,1});
                      arr.push_back({1,0,1,0,1});
                      arr.push_back({1,0,1,1,1});
                      break;
            case '3': arr.push_back({1,0,1,0,1});
                      arr.push_back({1,0,1,0,1});
                      arr.push_back({1,1,1,1,1});
                      break;
            case '4': arr.push_back({0,0,1,1,1});
                      arr.push_back({0,0,1,0,0});
                      arr.push_back({1,1,1,1,1});
                      break;
            case '5': arr.push_back({1,0,1,1,1});
                      arr.push_back({1,0,1,0,1});
                      arr.push_back({1,1,1,0,1});
                      break;
            case '6': arr.push_back({1,1,1,1,1});
                      arr.push_back({1,0,1,0,1});
                      arr.push_back({1,1,1,0,1});
                      break;
            case '7': arr.push_back({0,0,0,0,1});
                      arr.push_back({0,0,0,0,1});
                      arr.push_back({1,1,1,1,1});
                      break;
            case '8': arr.push_back({1,1,1,1,1});
                      arr.push_back({1,0,1,0,1});
                      arr.push_back({1,1,1,1,1});
                      break;
            case '9': arr.push_back({1,0,1,1,1});
                      arr.push_back({1,0,1,0,1});
                      arr.push_back({1,1,1,1,1});
                      break;
                    
        }
        if(cnt!=n-1){
            arr.push_back({0,0,0,0,0});
            cnt++;
        }else break;
    }
    for(int j=4;j>=0;j--){
        for(int i=0;i<n*4-1;i++){
            cout <<(arr[i][j]==1?'X':'.');
        }
        cout << endl;
    }
    return 0;
}