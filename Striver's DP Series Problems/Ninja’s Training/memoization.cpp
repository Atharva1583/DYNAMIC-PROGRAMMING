
int f(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    // base case
    if(day==0){
        int mx=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                mx=max(mx,points[0][i]);
            }
        }
        return mx;
    }
    if(dp[day][last]!=-1){
        return dp[day][last];
    }
    int mx=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point=points[day][i]+f(day-1,i,points,dp);
            mx=max(point,mx);
        }
    }
   return dp[day][last]=mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return f(n-1,3,points,dp);
}
