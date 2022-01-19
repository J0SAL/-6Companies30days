// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=08e1a01db42c2fa603eeba32f302a0a7&pid=702907&user=josal
class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string ans;
        for(auto c: s){
            if(c>='a' and c<='z')
                ans+=c;
            else{
                ans+=" ";
                ans+=(c+32);
            }
        }
        if(s[0]<97)
            ans = ans.substr(1);
        return ans;
    }
};