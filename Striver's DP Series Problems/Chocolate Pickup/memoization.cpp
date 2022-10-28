int f(int i,int j1,int j2,vector<vector<int>> &grid,int n,int m,vector<vector<vector<int>>> &dp){
    if(j1<0 || j1>=m || j2<0 || j2>=m){
        return -1e8;
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    if(i==n-1){
        if(j1==j2){
            return grid[i][j1];
        }else{
            return grid[i][j1]+grid[i][j2];
        }
    }
    
    int mx=0;
    for(int c1=-1;c1<=+1;c1++){
        for(int c2=-1;c2<=+1;c2++){
            if(j1==j2){
                mx=max(mx,grid[i][j1]+f(i+1,j1+c1,j2+c2,grid,n,m,dp));
            }else{
                mx=max(mx,grid[i][j1]+grid[i][j2]+f(i+1,j1+c1,j2+c2,grid,n,m,dp));
            }
        }
    }
    return dp[i][j1][j2]=mx;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return f(0,0,c-1,grid,r,c,dp);
}
