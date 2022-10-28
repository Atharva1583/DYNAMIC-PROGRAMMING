int f(int i,int j,vector<vector<int>> &triangle,int n){
    if(i==n-1){
        return triangle[n-1][j];
    }
    int down=triangle[i][j]+f(i+1,j,triangle,n);
    int diagonal=triangle[i][j]+f(i+1,j+1,triangle,n);
    return min(down,diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    return f(0,0,triangle,n);
}
