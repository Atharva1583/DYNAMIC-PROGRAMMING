#include<bits/stdc++.h>


int frogJump(int n, vector<int> &heights)
{
   
    vector<int> dp(n+1,-1);
    dp[0]=0;
    int prev1=0;int prev2=0;
    for(int i=1;i<n;i++){
        int left=prev1+abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1){
            right=prev2+abs(heights[i]-heights[i-2]);
        }
        prev2=prev1;
        prev1=min(left,right);
    }
    int ans=prev1;
    return ans;
}
