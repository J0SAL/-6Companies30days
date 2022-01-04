// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=5144fba658197e8ff9a3576cff8489ed&pid=702678&user=josal

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int x = 0; //missing
        int y = 0; //duplicate
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            if(mp[arr[i]]) y = arr[i];
            mp[arr[i]]++;
        }
        for(int i=1; i<=n; i++){
            if(!mp[i]){
                x=i; break;
            }
        }
        int *ans = new int[2];
        ans[0] = y;
        ans[1] = x;
        return ans;
    }
};