// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=a70cdf1ce0ad78f90ce734cd634e2498&pid=701342&user=josal
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<pair<int,int>> st;
       vector<int> ans;
       for(int i=0; i<n; i++){
           int temp_cnt = 1;
           while(!st.empty() and st.top().first<=price[i]){
               temp_cnt+=st.top().second;
               st.pop();
           }
           st.push({price[i], temp_cnt});
           ans.push_back(temp_cnt);
       }
       
       return ans;
    }
};