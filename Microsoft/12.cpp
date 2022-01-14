// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=21f8e2d7fabce76ba98cfa3c8f66cdf5&pid=702139&user=josal
#define v vector
#define ll long long
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        set<v<int>> my_set;
        int n=arr.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int st = j+1; int en = n-1;
                while(st<en){
                    ll summ = (ll) arr[i]+arr[j]+arr[st]+arr[en];
                    if(summ == k) {
                        my_set.insert({arr[i], arr[j], arr[st], arr[en]});
                        st++;
                        en--;
                    }
                    else if(summ<k) st++;
                    else en--;
                }
            }
        }
        v<v<int>> ans(my_set.begin(), my_set.end());
        return ans;
    }
    
};