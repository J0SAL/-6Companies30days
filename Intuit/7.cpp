// submission link: https://leetcode.com/submissions/detail/625871083/

bool isPossible(vector<int>& weights, int days, int mid){
    int cnt=1; 
    int total = 0;
    for(auto i: weights){
        total += i;
        if(total>mid){
            total=i;
            cnt++;
        }
    }
    
    return cnt<=days;
}

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxx = 0;
        int total = 0;
        for(auto i: weights){
            maxx=max(maxx, i);
            total+=i;
        }
        int low = maxx;
        int high = total;
        int ans;
        while(low<=high){
            int mid = (low+high)>>1;
            
            if(isPossible(weights, days, mid)){
                ans=mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};