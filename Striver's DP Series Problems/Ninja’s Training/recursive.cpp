
int f(int day,int last,vector<vector<int>> &points){
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
    int mx=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point=points[day][i]+f(day-1,i,points);
            mx=max(point,mx);
        }
    }
    return mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return f(n-1,3,points);
}
