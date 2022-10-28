#include<bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
    int ans=-1e9;
     vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<m;i++){
        dp[0][i]=matrix[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                continue;
            }
                int path1,path2,path3;
                path1=matrix[i][j];
                path2=matrix[i][j];
                path3=matrix[i][j];
                path1+=dp[i-1][j];
                if(j>0){
                    path2+=dp[i-1][j-1];
                }else{
                    path2+=-1e9;
                }
                if(j<m-1){
                    path3+=dp[i-1][j+1];
                }else{
                    path3+=-1e9;
                }
                dp[i][j]=max(path1,max(path2,path3));
            }
    }
    for(int i=0;i<m;i++){
        ans=max(ans,dp[n-1][i]);
    }
    return ans;
}
