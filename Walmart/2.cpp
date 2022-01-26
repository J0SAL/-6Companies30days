// submission link: https://leetcode.com/submissions/detail/628301380/

int helper(vector<int> &piles, int i, int j, vector<vector<int>> &dp){
    if(i>j) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    return dp[i][j] = max(
        piles[i]+min(helper(piles, i+2, j, dp), helper(piles, i+1, j-1, dp)),
        piles[j]+min(helper(piles, i, j-2, dp), helper(piles, i+1, j-1, dp))
    );
}

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int alice = helper(piles,0, n-1, dp);
        int total = 0;
        for(int &i: piles) total+=i;
        int bob = total-alice;
        return alice>bob;
    }
};