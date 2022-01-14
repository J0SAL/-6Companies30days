// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=dcb456812ade9486eee28f422d76f656&pid=701417&user=josal

#define v vector
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int helper(int arr[], int n, v<int> &dp){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int r1 = arr[n] + helper(arr, n-2, dp);
        int r2 = helper(arr, n-1, dp);
        
        return dp[n] = max(r1, r2);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        v<int> dp(n, -1);
        return helper(arr, n-1, dp);
    }
};