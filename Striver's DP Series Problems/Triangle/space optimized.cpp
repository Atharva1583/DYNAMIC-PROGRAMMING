
int minimumPathSum(vector<vector<int>>& triangle, int n){
    int m=triangle[n-1].size();
    vector<int> dp(n,0);
    for(int i=0;i<n;i++){
        dp[i]=triangle[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        vector<int> temp(n,0);
        for(int j=i;j>=0;j--){
            int down=triangle[i][j]+dp[j];
            int diagonal=triangle[i][j]+dp[j+1];
            temp[j]=min(down,diagonal);
        }
        dp=temp;
    }
    return dp[0];
}
