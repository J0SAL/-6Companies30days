// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=c6065042e0f051fffdf1cb79ff5aa31d&pid=702959&user=josal

class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans;
        while(n>0){
            n-=1;
            int rem = n%26;
            ans = char('A'+rem) + ans;
            n/=26;
        }
        return ans;
    }
};