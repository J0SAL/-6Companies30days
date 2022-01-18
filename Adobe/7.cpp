// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=8be0c1e536c7dcda0b0289f6ea85587b&pid=700428&user=josal
class Solution {
public:
    int helper(vector<int> &A, int i, int n, vector<vector<int>> &dp){
        if(i>n) return 0;
        
        if(dp[i][n] != -1) return dp[i][n];
        int left  = A[i] + min(helper(A, i+2, n, dp), helper(A, i+1, n-1, dp));
        int right = A[n] + min(helper(A, i, n-2, dp), helper(A, i+1, n-1, dp));
        
        return dp[i][n] = max(left, right);
    }
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    vector<vector<int>> dp(n, vector<int>(n,-1));
	    return helper(A,0, n-1, dp);
    }
};