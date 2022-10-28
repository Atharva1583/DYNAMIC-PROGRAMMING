bool f(int index,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(target==0){
        return true;
    }
    if(index==0){
        return (arr[0]==target);
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    bool notTake=f(index-1,target,arr,dp);
    bool take=false;
    if(arr[index]<=target){
        take=f(index-1,target-arr[index],arr,dp);
    }
    return dp[index][target]=(take || notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
   
   // vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    vector<bool> dp(k+1,false);
    // base cases
   dp[0]=true;
    dp[arr[0]]=true;
    for(int i=1;i<n;i++){
        vector<bool> temp(k+1,false);
        temp[0]=true;
        for(int j=1;j<=k;j++){
            bool notTake=dp[j];
            bool take=false;
            if(arr[i]<=j){
                take=dp[j-arr[i]];
            }
            temp[j]=(take or notTake);
        }
        dp=temp;
    }
    return dp[k];
}
