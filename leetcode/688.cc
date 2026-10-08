//骑士在棋盘上的概率

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN=25;
const int MAXK=100;

double dp[MAXK+1][MAXN+4][MAXN+4];

double knightProbability(int n, int k, int row, int column) {
    const int dir[8][2]{{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
    for(int cnt=0;cnt<=k;cnt++){
        for(int i=2;i<n+2;i++){
            for(int j=2;j<n+2;j++){
                dp[cnt][i][j]=0.0;
            }
        }
    }
    dp[0][row+2][column+2]=1.0;
    for(int cnt=1;cnt<=k;cnt++){
        for(int i=2;i<n+2;i++){
            for(int j=2;j<n+2;j++){
                double add_num=dp[cnt-1][i][j]/8;
                if(add_num>0){
                    for(int dir_n=0;dir_n<8;dir_n++){
                        dp[cnt][i+dir[dir_n][0]][j+dir[dir_n][1]]+=add_num;
                    }
                }
            }
        }
    }
    double ans=0.0;
    for(int i=2;i<n+2;i++){
        for(int j=2;j<n+2;j++){
            ans+=dp[k][i][j];
        }
    }
    return ans;
}