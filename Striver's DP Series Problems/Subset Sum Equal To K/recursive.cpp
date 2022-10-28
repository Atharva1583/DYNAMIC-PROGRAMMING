bool f(int index,int target,vector<int> &arr){
    if(target==0){
        return true;
    }
    if(index==0){
        return (arr[0]==target);
    }
    bool notTake=f(index-1,target,arr);
    bool take=f(index-1,target-arr[index],arr);
    return (take or notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return f(n-1,k,arr);
}
