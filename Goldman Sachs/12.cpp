// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=c6d68dd63869dcd0ff747350304287f9&pid=704775&user=josal
class Solution {
  public:
    long long squaresInChessBoard(long long n) {
        // code here
        // sum of squares of numbers up to n
        return n*(n+1)*(2*n+1)/6;
    }
};