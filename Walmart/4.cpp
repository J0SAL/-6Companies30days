// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=7439b8048d1207d42750ca849a184ac8&pid=701714&user=josal

void helper(int i, int j, int n, int m, int &moves){
    if(i==n and m==j){
        moves++;
    };
    if(i<=0 or i>n or j<=0 or j>m) return;
    
    helper(i+1, j, n, m, moves);
    helper(i, j+1, n, m, moves);
}

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        int moves = 0;
        helper(1,1,a,b, moves);
        return moves;
    }
};
