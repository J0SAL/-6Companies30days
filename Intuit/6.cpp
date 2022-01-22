// submission link: https://leetcode.com/submissions/detail/625248331/


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int start = 0;
        int end = mountainArr.length()-1;
        
        while(start<end){
            int mid = (start+end)>>1;
            int mid_ele = mountainArr.get(mid);
            if(mid_ele > mountainArr.get(mid+1))
                end= mid;
            else 
                start=mid+1;
        }
        
        int peak = end;
        // got peak ele, now search on either sides
        
        int low = 0;
        int high = peak;
        
        while(low<=high){
            int mid = (low+high)>>1;
            int mid_ele = mountainArr.get(mid);
            
            if(mid_ele == target){
                return mid;
            }
            else if(mid_ele < target){
                low = mid +1;
            }
            else{
                high = mid-1;
            }
        }
        
        
        low = peak+1;
        high = mountainArr.length()-1;
        
        while(low<=high){
            int mid = (low+high)>>1;
            int mid_ele = mountainArr.get(mid);
            
            if(mid_ele == target){
                return mid;    
            }
            else if(mid_ele < target){
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        
        return -1;
    }
};