#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int N;
    cin >>N;
    vector<vector<int>> arr(N,vector<int>(N,0));
    int pr=0,pc=N/2;
    arr[pr][pc]=1;
    for(int i=2;i<=N*N;i++){
        if(pr==0 && pc!=N-1){
            pr=N-1;pc++;
        }else if(pr!=0 && pc==N-1){
            pc=0;pr--;
        }else if(pr==0 && pc==N-1){
            pr++;
        }else{
            if(arr[pr-1][pc+1]==0){
                pr--;pc++;
            }else{
                pr++;
            }
        }
        arr[pr][pc]=i;
    }
    for(auto & row : arr){
        for(int x : row) cout << x << ' ';
        cout<<endl;
    }
    return 0;
}