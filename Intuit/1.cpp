// https://practice.geeksforgeeks.org/viewSol.php?subId=c05925cdc19df113682f1cbf54303cf4&pid=704140&user=josal
#define v vector

int helper(int arr[], int curr, int total, int n, v<v<int>> &dp){
    if(n<=0){
        return abs(total-2*curr);
    }
    if(dp[n][curr]!=-1) return dp[n][curr];
    return dp[n][curr] = min(
            helper(arr, curr+arr[n-1], total, n-1, dp),
            helper(arr, curr, total, n-1, dp)
        );
}

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int total = 0;
	    for(int i=0; i<n; i++) total+=arr[i];
	    v<v<int>> dp(n+1, v<int>(total+1, -1));
	    return helper(arr, 0, total, n, dp);
	} 
};
