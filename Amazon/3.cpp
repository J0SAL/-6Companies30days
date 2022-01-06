// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=b5f48341b05929d4d8eeb920220d6032&pid=707042&user=josal
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        unordered_map<int, int> mp; // for removing elements outside range
        deque<int> dq; // for maintaining peak element -> {max, less(max) ..}
        int i=0;
        for(; i<k; i++){
            mp[arr[i]]++;
            while(!dq.empty() and dq.back()<=arr[i]) dq.pop_back();
            dq.push_back(arr[i]);
        }
        ans.push_back(dq.front());
        for(;i<n;i++){
            int st = i-k;
            mp[arr[st]]--;
            
            while(!dq.empty() and dq.back()<=arr[i]) dq.pop_back();
            dq.push_back(arr[i]);
            mp[arr[i]]++;
            while(!dq.empty() and mp[dq.front()]==0) dq.pop_front();
            ans.push_back(dq.front());
        }
        
        return ans;
        
    }
};