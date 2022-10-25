int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int prev1=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int pick=nums[i]+prev2;
        int notPick=prev1;
        prev2=prev1;
        prev1=max(pick,notPick);
    }
    int ans=prev1;
    return ans;
}
