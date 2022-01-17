// https://practice.geeksforgeeks.org/viewSol.php?subId=0d2f2b0af651ebea2be92177ed964254&pid=704573&user=josal

#define v vector
class Solution{
public:
    int helper(int arr[], int n, int req_sum, int curr_sum, v<v<int>> &dp){
        if(curr_sum == req_sum) return 1;
        if(n==0) return 0;
        if(dp[n][curr_sum]!=-1) return dp[n][curr_sum];
        return dp[n][curr_sum] =(helper(arr, n-1,req_sum,curr_sum+arr[n-1], dp) or helper(arr, n-1,req_sum,curr_sum, dp));
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int summ=0;
        for(int i=0; i<N; i++) summ+=arr[i];
        if(summ%2!=0) return 0;
        int req_sum = summ/2;
        v<v<int>> dp(N+1, v<int> (summ+1, -1));
        return helper(arr, N, req_sum,0, dp);
    }
};