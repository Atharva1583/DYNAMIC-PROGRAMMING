int f(int index,vector<int> a){
    if(index==0){
        return a[index];
    }
    if(index<0){
        return 0;
    }
    int pick=a[index]+f(index-2,a);
    int notPick=f(index-1,a);
    return max(pick,notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    
    int ans=f(nums.size()-1,nums);
    return ans;
}
