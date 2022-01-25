// submission link: https://leetcode.com/submissions/detail/627444588/

bool isPossible(vector<int> &piles, int mid, int h){
    int cnt= 0;
    int summ = 0;
    for(auto i: piles){
        if(i<=mid) cnt+=1;
        else{
            cnt+=(i/mid);
            if(i%mid!=0) cnt++;
        }
    }
    // cout<<"mid: "<<mid<<endl;
    // cout<<"cnt: "<<cnt<<endl;
    return cnt<=h;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end());
        
        int low = 1;
        int ans;
        while(low<=high){
            int mid = (low+high)>>1;
            if(isPossible(piles, mid, h)){
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