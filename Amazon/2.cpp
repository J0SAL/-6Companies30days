class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();

        int ans = 0;
        for(int i=1; i<n-1; ){
            if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){
                int mountain=1;
                int j=i;
                while(j>0 and arr[j]>arr[j-1]){
                    j--; mountain++;
                }            
                while(i<n-1 and arr[i]>arr[i+1]){
                    i++; mountain++;
                }
                ans = max(ans, mountain);
            }
            else{
                i++;
            }
        }
        return ans;
    }
};