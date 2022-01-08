// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=5c3f5db5f8b58f9bf4c4b926c80bd7a6&pid=705397&user=josal
#define v vector
v<v<int>> bracket(501, v<int>(501,0));

class Solution{
public:
    void printSeq(int i, int j, string &ans){
        if(i>j) return;
        if(i==j){
            ans+=('A'+i-1);
            return;
        }
        ans+='(';
        printSeq(i, bracket[i][j], ans);
        printSeq(bracket[i][j]+1, j, ans);
        ans+=')';
    }
    int MCM(int arr[], int i, int j, v<v<int>> &dp){
        if(i==j or i==0 or j==0){
            bracket[i][j] = j;
            // cout<<"check: "<<i<<" "<<j<<endl;
            return 0;  
        } 
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        int bracket_temp;
        for(int k=i; k<j; k++){
            int val = min(ans, MCM(arr, i,k, dp)+MCM(arr, k+1,j, dp)+arr[i-1]*arr[k]*arr[j]);
            if(val<ans){
                ans = val;
                bracket_temp=k;
            }
        }
        bracket[i][j] = bracket_temp;
        // cout<<"check: "<<i<<" "<<j<<endl;
        return dp[i][j] = ans;
    }
    string matrixChainOrder(int p[], int n){
        // code here
        v<v<int>> dp(n+1,v<int> (n+1, -1));
        int cost = MCM(p, 1, n-1, dp);
        
        string ans;
        printSeq(1,n-1,ans);
        return ans;
    }

