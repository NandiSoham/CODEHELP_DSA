int findMaxSubarraySum(int arr[], int n){
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}