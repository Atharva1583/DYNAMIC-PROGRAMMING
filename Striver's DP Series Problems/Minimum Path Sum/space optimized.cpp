#include<bits/stdc++.h>

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    vector<int> dp(m,0);
    for(int i=0;i<n;i++){
        vector<int> temp(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                temp[j]=grid[i][j];
            }else{
                int up=grid[i][j],left=grid[i][j];
                if(i>0){
                    up+=dp[j];
                }else{
                    up+=1e9;
                }
                if(j>0){
                    left+=temp[j-1];
                }else{
                    left+=1e9;
                }
                temp[j]=min(up,left);
            }
        }
        dp=temp;
    }
      return dp[m-1];
}
