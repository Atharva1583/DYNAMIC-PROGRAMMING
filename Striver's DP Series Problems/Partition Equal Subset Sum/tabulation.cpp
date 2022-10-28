
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2){
        return false;
    }
    vector<vector<bool>> dp(n,vector<bool>(sum/2 + 1,false));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int target=1;target<=(sum/2);target++){
            bool notTake=dp[i-1][target];
            bool take=false;
            if(arr[i]<=target){
                take=dp[i-1][target-arr[i]];
            }
            dp[i][target]=(take | notTake);
        }
    }
    return dp[n-1][sum/2];
}
