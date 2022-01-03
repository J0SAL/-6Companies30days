// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=50d6c6c6b34354a872f86007b56c2b6b&pid=704216&user=josal

class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        if(N==1) return N;
        int ans = (M%N+K-1);
        if(ans == N) return ans;
        return ans%N;
    }
};