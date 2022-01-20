// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=f50cad4ad7aadd7ada38528794a3916c&pid=706334&user=josal
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp;
    
    for (auto num : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), num); //logN
        if (it == dp.end()) dp.push_back(num);
        else *it = num;
    }
    
    return dp.size();
}

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        
        vector<int> v;
        unordered_map<int, int> mp;
        for(int i=0; i<M; i++){
            mp[B[i]]++;
        }
        
        for(int i=0; i<N; i++){
            if(mp.find(A[i])!=mp.end()){
                v.push_back(A[i]);
            }
        }
        // for(int i: v) cout<<i<<" "; cout<<endl;
        int lcs = lengthOfLIS(v);
        // cout<<lcs<<endl;
        int modify=min(N,M)-lcs;
        // cout<<modify<<endl;
        int del = max(N,M) - (lcs+modify);
        // cout<<del<<endl;
        int ans = 2*modify+del;
        return ans;
    }
};