// submission link: https://leetcode.com/submissions/detail/625222274/

bool isPossible(vector<int> &nums, int mid, int m){
    int cnt = 1;
    int temp = 0;
    for(auto i: nums){
        temp+=i;
        if(temp>mid){
            cnt++;
            temp = i;
        }
    }
    
    return cnt<=m;
}

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int total=0;
        int maxx=0;
        for(auto i: nums){
            total+=i;
            maxx = max(maxx, i);
        }
        int low=maxx;
        int high = total;
        int ans = 0;

        while(low<=high){
            int mid= (low+high)>>1;
            if(isPossible(nums, mid, m)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};