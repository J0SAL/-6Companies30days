// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=c61d25b1b2eddf6d1e95ca0478bd987f&pid=701290&user=josal
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        int maxx = -1;
        map<string, int> mp;
        for(int i=0; i<n; i++){
            string s = arr[i];
            mp[s]++;
            maxx = max(maxx, mp[s]);
        }
        
        for(auto i: mp){
            if(i.second == maxx){
                return {i.first, to_string(i.second)};
            }
        }
        return {"-1", "-1"};
    }
};