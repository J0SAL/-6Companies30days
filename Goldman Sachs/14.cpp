// solution link: https://leetcode.com/submissions/detail/613522232/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int start = 0;
        int curr = 0;
        int size = n+1;
        for(int end=0; end<n; end++){
            curr+=nums[end];
            while(curr>=target){
                size = min(size, end-start+1);
                curr -= nums[start++];
            }
        }
        if(size == n+1) return 0;
        return size;
    }
};