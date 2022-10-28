
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
   vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,0)));
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            if(i!=j){
                dp[r-1][i][j]=(grid[r-1][j]+grid[r-1][i]);
            }else{
                dp[r-1][i][j]=grid[r-1][i];
            }
        }
    }
    for(int i=r-2;i>=0;i--){
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                int mx=-1e8;
                for(int c1=-1;c1<=1;c1++){
                    for(int c2=-1;c2<=1;c2++){
                        if(j1==j2){
                            if(j1+c1>=0 && j1+c1<c && j2+c2>=0 && j2+c2<c){
                                 dp[i][j1][j2]=max(dp[i][j1][j2],grid[i][j1]+dp[i+1][j1+c1][j2+c2]);
                            }
                             else{
                                  dp[i][j1][j2]=max(dp[i][j1][j2],grid[i][j1]+((int)-1e8));
                             }
                        }else{
                            if(j1+c1>=0 && j1+c1<c && j2+c2>=0 && j2+c2<c){
                                 dp[i][j1][j2]=max(dp[i][j1][j2],grid[i][j1]+grid[i][j2]+dp[i+1][j1+c1][j2+c2]);
                            }
                             else{
                                 dp[i][j1][j2]=max(dp[i][j1][j2],grid[i][j1]+grid[i][j2]+((int)-1e8));
                             }
                            
                        }
                    }
                }
            }
        }
    }
    return dp[0][0][c-1];
}
