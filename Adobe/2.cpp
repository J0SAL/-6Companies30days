// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=52c0c6bb7140c23b30b0b811875bc389&pid=703290&user=josal
#define v vector

/*
    1 2 3
    
    3-2 = 1
    but 2 has 1 from (2-1) 
    so ans = (2+1)->3;

*/
class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n<=2) return n;
        v<v<int>> dp(n, v<int>(10001));
        int ans = 2;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int diff = A[j] - A[i];
                dp[j][diff] = max(dp[i][diff]+1,2);
                ans = max(dp[j][diff], ans);
            }
        }
        
        return ans;
    }
};