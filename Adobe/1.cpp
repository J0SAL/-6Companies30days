// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=d44ef0d1711418360c15eb0a3f73ada1&pid=701236&user=josal
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        long long curr = 0;
        int st=0;
        for(int i=0; i<n; i++){
            curr+=arr[i];
            while(curr>s and st<i){
                curr-=arr[st++];
            }
            if(curr == s) {
                return {st+1, i+1};
            }
        }
        return {-1};
    }
};