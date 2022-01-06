// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=f481f9b23a03e0ba499fd00c5640dccf&pid=704532&user=josal
#define v vector
class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        v<v<int>> T(K+1, v<int>(N, 0));
        for(int i=1; i<=K; i++){
            int maxVal = INT_MIN;
            for(int j=1; j<N; j++){
                maxVal = max(maxVal, T[i-1][j-1]-A[j-1]);
                T[i][j] = max(T[i][j-1], maxVal+A[j]);
            }
        }
        return T[K][N-1];
    }
};