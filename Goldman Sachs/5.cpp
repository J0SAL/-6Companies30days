// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=6d8ee35d350d88a0b8f7e629735f32e6&pid=703093&user=josal
#define v vector

ull getMin(ull a, ull b, ull c){
    return min(a, min(b,c));
}
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    v<ull> dp(n, 0);
	    int u2(0), u3(0), u5(0);
	    dp[0]=1; // given
	    for(int i=1; i<n; i++){
	        dp[i] = getMin(2*dp[u2], 3*dp[u3], 5*dp[u5]);
	        if(dp[i] == 2*dp[u2]) u2++;
	        if(dp[i] == 3*dp[u3]) u3++;
	        if(dp[i] == 5*dp[u5]) u5++;
	    }
	    return dp[n-1];
	}
};