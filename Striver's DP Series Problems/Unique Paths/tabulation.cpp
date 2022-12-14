#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n));
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                continue;
            }else{
                if(i==0){
                    dp[i][j]=dp[i][j-1];
                }else if(j==0){
                    dp[i][j]=dp[i-1][j];
                }else{
                    int up=dp[i-1][j];
                    int left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
    }
    return dp[m-1][n-1];
    
}
