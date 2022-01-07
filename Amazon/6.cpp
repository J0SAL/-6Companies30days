// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=cc16ca26732ec6fd4e2c799f783acd04&pid=701349&user=josal
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        deque<int> dq; // store elements in decreasing order
        vector<int> ans;
        int i=0;
        for(;i<k; i++){
            while(!dq.empty() and arr[dq.back()]<arr[i]) dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);
        for(;i<n; i++){
            if(dq.front()==i-k) dq.pop_front(); //we are only conserned about the window
            
            while(!dq.empty() and arr[dq.back()]<arr[i]) dq.pop_back();
            dq.push_back(i);
            
            ans.push_back(arr[dq.front()]);
        }
        return ans;
    }

    
};