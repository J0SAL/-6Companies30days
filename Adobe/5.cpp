// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=2180279802b48a03d54c7afad9510c84&pid=705641&user=josal
#define ll long long

ll helper(int n, int x, int curr, vector<vector<ll>> &dp) {
    if(n == 0) return 1;
    if(curr == 0) return 0;
    
    if(dp[n][curr] != -1) return dp[n][curr];
    
    ll temp = pow(curr, x);
    ll a(0), b(0);
    
    if(temp<=n) a = helper(n - temp, x, curr - 1, dp);
    b = helper(n, x, curr - 1, dp);
    
    return dp[n][curr] = a+b;
}

class Solution{
    public:
    ll numOfWays(int n, int x)
    {
        // code here n->10, x->2(power)
        int curr = pow(n, 1.0/x);
        vector<vector<ll>> dp(n+1, vector<ll>(curr+1, -1));
        return helper(n, x, curr, dp);
    }
};