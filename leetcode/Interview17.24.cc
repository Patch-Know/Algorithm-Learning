//最大子矩阵

#include<vector>
#include<algorithm>

using namespace std;

vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
    int m=matrix.size(),n=matrix[0].size();
    int max_val=INT_MIN;
    vector<int> ret{0,0,0,0};
    for(int up=0;up<m;up++){
        vector<int> nums(n,0);
        for(int down=up;down<m;down++){
            for(int i=0;i<n;i++){
                nums[i]+=matrix[down][i];
            }
            int pre=nums[0];
            int ans=nums[0];
            int max_l=0,max_r=0;
            for(int l=0,r=1;r<n;r++){
                if(nums[r]>pre+nums[r]){
                    pre=nums[r];
                    l=r;
                }else{
                    pre=pre+nums[r];
                }
                if(ans<pre){
                    ans=pre;
                    max_l=l;
                    max_r=r;
                }
            }
            if(max_val<ans){
                max_val=ans;
                ret={up,max_l,down,max_r};
            }
        }
    }
    return ret;
}