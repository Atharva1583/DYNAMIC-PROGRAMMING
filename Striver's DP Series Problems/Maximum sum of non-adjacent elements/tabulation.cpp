int maximumNonAdjacentSum(vector<int> &nums){
    
    int n=nums.size();
    vector<int> dp(n+1,0);
    dp[0]=nums[0];
    dp[-1]=0;
    for(int i=1;i<n;i++){
        int pick=nums[i]+dp[i-2];
        int notPick=dp[i-1];
        dp[i]=max(pick,notPick);
    }
    int ans=dp[n-1];
    return ans;
}
