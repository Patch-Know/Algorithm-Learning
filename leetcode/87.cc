//扰乱字符串
#include<string>
using std::string;

const int MAX_LEN=30;

bool dp[MAX_LEN][MAX_LEN][MAX_LEN+1];

bool isScramble1(string s1, string s2) {
    int len=s1.length();
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            dp[i][j][1]= s1[i]==s2[j];
        }
    }
    for(int level=2;level<=len;level++){
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                dp[i][j][level]=false;
                for(int x=1;x<level;x++){
                    if((dp[i][j][x]&&i+x<len&&j+x<len&&dp[i+x][j+x][level-x]) 
                    || (j+level-x<len&&dp[i][j+level-x][x]&&i+x<len&&dp[i+x][j][level-x])){
                        dp[i][j][level]=true;
                        break;
                    }
                }
                
            }
        }  
    }
    return dp[0][0][len];
}

bool isScramble2(string s1, string s2) { //边界优化!!!
    int len=s1.length();
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            dp[i][j][1]= s1[i]==s2[j];
        }
    }
    for(int level=2;level<=len;level++){
        for(int i=0;i<=len-level;i++){
            for(int j=0;j<=len-level;j++){
                dp[i][j][level]=false;
                for(int x=1;x<level;x++){
                    if((dp[i][j][x]&&dp[i+x][j+x][level-x]) 
                    || (dp[i][j+level-x][x]&&dp[i+x][j][level-x])){
                        dp[i][j][level]=true;
                        break;
                    }
                }
                
            }
        }  
    }
    return dp[0][0][len];
}