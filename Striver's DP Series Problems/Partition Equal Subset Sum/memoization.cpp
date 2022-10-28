int f(int index,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(target==0){
        return true;
    }
    if(index==0){
        return arr[0]==target;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    bool notTake=f(index-1,target,arr,dp);
    bool take = false;
    if(arr[index]<=target){
        take=f(index-1,target-arr[index],arr,dp);
    }
    return dp[index][target]= (take | notTake);
}

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
    vector<vector<int>> dp(n,vector<int>(sum/2 + 1,-1));
    return f(n-1,sum/2,arr,dp);
}
