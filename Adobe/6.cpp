// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=4bedd16d55e97f54ccca37b89ca5250f&pid=702078&user=josal
void helper(int open, int close, string s, vector<string> &res){
    if(open == 0 and close==0){
        res.push_back(s);
        return;
    }
    if(open>0){
        helper(open-1, close, s+"(", res);
    }
    if(close>open){
        helper(open, close-1, s+")", res);
    }
}

class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> res;
        helper(n,n,"",res);
        return res;
    }
};