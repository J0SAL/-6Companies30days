// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=09efd531b608d4d806e6c683d78ae358&pid=705327&user=josal
#define v vector
const int mod = 1000000007;
int to_int(string s){
    stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}
class Solution {
	public:
	    int helper(string s, int n, v<int> &dp){
	        if(n<=1) return 1;
	        if(dp[n]!=-1) return dp[n];
	        int x=0,y=0;
	        
	        if(s[n-1]!='0'){
	            x=helper(s, n-1, dp);
	        }
	        if(n>=2 and to_int(s.substr(n-2,2))<=26 and to_int(s.substr(n-2,2))>=10){
	            y=helper(s,n-2, dp);
	        }
	        return dp[n]=((x+y)%mod);
	    }
		int CountWays(string str){
		    // Code here
		    int n=str.size();
		    if(str[0]=='0') return 0;
		    v<int> dp(n+1, -1);
		    return helper(str, n, dp);
		}

};