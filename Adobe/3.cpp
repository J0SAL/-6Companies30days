// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=fdd0ddf280efcc30c0dca1f8a59fba39&pid=706392&user=josal
#define v vector
#define ll long long int
const ll MOD = 1000000007;

ll helper(int n, int k, int curr_k, v<v<ll>> &dp){
    if(n==0) return 1;
    if(dp[n][curr_k]!=-1) return dp[n][curr_k];
    
    if(curr_k == k){
        return dp[n][curr_k] = 21*helper(n-1, k, 0, dp)%MOD; //0 as it's continuous
    }

    return dp[n][curr_k] = (5*helper(n-1, k, curr_k+1, dp) + 21*helper(n-1, k, 0, dp))%MOD;
}
class Solution
{
  public:
    int kvowelwords(int N, int K) {
        // Write Your Code here
        v<v<ll>> dp(N+1, v<ll>(K+1, -1));
        return helper(N, K, 0, dp)%MOD;
    }
};