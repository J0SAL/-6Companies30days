// submission link: https://leetcode.com/submissions/detail/629532039/
int helper(int low, int high, vector<vector<int>> &dp){
    if(low>=high) return 0;
    if(dp[low][high]!=-1) return dp[low][high];
    
    int ans = INT_MAX;
    for(int i=low; i<=high; i++){
        //max of curr+ left or right
        int flag=i+max(helper(low, i-1, dp), helper(i+1, high, dp));
        
        //min from where to go from left/right         
        ans = min(ans, flag);
    }
    
    return dp[low][high] = ans;
}
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return helper(1, n, dp);
    }
};