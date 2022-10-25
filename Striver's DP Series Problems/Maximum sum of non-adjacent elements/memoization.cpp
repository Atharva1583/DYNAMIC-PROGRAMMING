int f(int index,vector<int> a,vector<int> &dp){
    if(index==0){
        return a[index];
    }
    if(index<0){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int pick=a[index]+f(index-2,a,dp);
    int notPick=f(index-1,a,dp);
    return dp[index]=max(pick,notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    int ans=f(nums.size()-1,nums,dp);
    return ans;
   
}
