// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=2e37ff6a7aa1c03382294b1c1bff6d29&pid=701210&user=josal
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ans;
        int maxx = a[n-1];
        ans.push_back(maxx);
        for(int i=n-2; i>=0; i--){
            if(a[i]>=maxx){
                maxx = a[i];
                ans.push_back(maxx);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};