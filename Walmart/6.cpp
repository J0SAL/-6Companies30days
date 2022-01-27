// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=420a44c0e471cc1c4b8ee898cfaba5fc&pid=701195&user=josal
const int MOD = 1000000007;

class Solution{
    public:
    //You need to complete this fucntion
    long long power(int N,int R)
    {
        //Your code here
        long long ans=1;
        long long LN = N;
        while(R>0){
            if(R&1){
                ans = (ans * LN) % MOD;
            }
            
            LN = (LN * LN) % MOD;
            R = R>>1;
           
        }
        return ans % MOD;
    }
};