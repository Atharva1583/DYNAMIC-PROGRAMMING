#include<bits/stdc++.h>
int f(int i,int j,vector<vector<int>> &matrix,int n,int m,vector<vector<int>> &dp){
    if(j<0 || j>=m){
        return -1e9;
    }
    if(i==0){
        return matrix[0][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int path1=matrix[i][j]+f(i-1,j,matrix,n,m,dp);
    int path2=0,path3=0;
        path2=matrix[i][j]+f(i-1,j+1,matrix,n,m,dp);
        path3=matrix[i][j]+f(i-1,j-1,matrix,n,m,dp);
    return dp[i][j]=max(path1,max(path2,path3));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
    int ans=-1e9;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int i=0;i<m;i++){
        int res=f(n-1,i,matrix,n,m,dp);
        ans=max(ans,res);
    }
    return ans;
}
