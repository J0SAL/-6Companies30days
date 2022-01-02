// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=52a3cfae6bdfd1608129acd327d561a1&pid=703804&user=josal
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        // sliding window 
        long long int i=0,j=0,prod=1,cnt=0;
        while(j<n){
            prod*=a[j];
            while(i<=j and prod>=k){
                prod/=a[i++];
            }
            if(prod<k){
                cnt += j-i+1;
                j++;
            }
        }
        
        return cnt;
    }
};