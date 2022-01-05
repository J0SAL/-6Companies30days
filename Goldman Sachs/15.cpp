// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=2bc8ab51aa906904767a1c06d3bbf6a8&pid=704691&user=josal
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()&1) return 0;
        
        vector<int> freq(k, 0);
        for(int i: nums){
            freq[i%k]++;
        }
        if(freq[0]&1) return 0; // remainder 0 must be even times
        int i=1, j=k-1;
        while(i<j){
            if(freq[i]!=freq[j]) return 0;
            i++;
            j--;
        }
        if(i==j and freq[i]&1) return 0;
        return 1;
    }
};