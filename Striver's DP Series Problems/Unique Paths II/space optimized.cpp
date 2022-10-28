int mod=1e9+7;


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<int> dp(m,0);
    for(int i=0;i<n;i++){
        vector<int> temp(m,0);
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1){
                  temp[j]=0;
            }else if(i==0 && j==0){
                temp[j]=1;
            }else if(i==0){
                temp[j]=(temp[j-1])%mod;
            }else if(j==0){
                temp[j]=(dp[j])%mod;
            }else{
                temp[j]=(dp[j]+temp[j-1])%mod;
            }
        }
        dp=temp;
    }
    return dp[m-1];
}
