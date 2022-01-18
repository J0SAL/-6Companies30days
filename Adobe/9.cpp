// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=66f477e54019ba4d1e47cb5f404c3b00&pid=703481&user=josal
class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        int n = N.size();
        if(n<=3) return "-1";
        string first = N.substr(0,n/2);
        if(next_permutation(first.begin(), first.end())){
            string ans = first;
            if(n&1) ans+=N[n/2];
            reverse(first.begin(), first.end());
            ans+=first;
            return ans;
        }
        return "-1";
    }
};