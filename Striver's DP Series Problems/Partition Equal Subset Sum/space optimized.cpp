
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
    vector<bool> dp(sum/2 + 1,false);
    dp[0]=true;
    dp[arr[0]]=true;
    for(int i=1;i<n;i++){
        vector<bool> temp(sum/2 + 1, false);
        temp[0]=true;
        for(int target=1;target<=(sum/2);target++){
            bool notTake=dp[target];
            bool take=false;
            if(arr[i]<=target){
                take=dp[target-arr[i]];
            }
            temp[target]=(take | notTake);
        }
        dp=temp;
    }
    return dp[sum/2];
}
