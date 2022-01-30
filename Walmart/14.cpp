// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=6a48dcd08a709eff49294fe3345c32c8&pid=701369&user=josal
void helper(string &str, int k, string &maxx, int pos){
    if(k==0) return;
    int n=str.size();
    
    char max_c = str[pos];
    for(int i=pos+1; i<n; i++){
        max_c = max(max_c, str[i]);
    }
    
    if(max_c!=str[pos]) k--;
    
    for(int i=n-1; i>=pos; i--){
        if(str[i] == max_c){
            swap(str[i], str[pos]);
            maxx = max(maxx, str);
            helper(str, k, maxx, pos+1);
            swap(str[i], str[pos]);
        }
    }
}
class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string &str, int k)
    {
        // code here.
        string maxx = str;
        helper(str, k, maxx, 0);
        return maxx;
    }
};