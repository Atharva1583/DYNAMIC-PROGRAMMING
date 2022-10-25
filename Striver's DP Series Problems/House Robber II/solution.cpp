long long int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    long long int prev1=nums[0];
    for(int i=1;i<n;i++){
        long long int pick=nums[i]+prev2;
        long long int notPick=prev1;
        prev2=prev1;
        prev1=max(pick,notPick);
    }
    return prev1;
   
}

long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int> temp1,temp2;
    int n=valueInHouse.size();
    if(n==1){
        return valueInHouse[0];
    }
    for(int i=0;i<n;i++){
        if(i!=0){
            temp1.push_back(valueInHouse[i]);
        }
        if(i!=n-1){
            temp2.push_back(valueInHouse[i]);
        }
    }
        return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
    
}
