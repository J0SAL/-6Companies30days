// submission link: https://leetcode.com/submissions/detail/631051872/
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int> ans;
        sort(sums.begin(), sums.end());
        
        
        for(int i=0; i<n; i++){
            unordered_map<int, int> mp;
            
            int diff = sums[1]-sums[0];
            
            vector<int> v1, v2;
            
            bool flag=0;
            for(int j=0; j<sums.size(); j++){
                if(!mp[sums[j]]){
                    v1.push_back(sums[j]);
                    mp[sums[j]+diff]++;
                    if(sums[j]==0)
                        flag=true;
                }
                else{
                    v2.push_back(sums[j]);
                    mp[sums[j]]--;
                }
            }
            if(flag) {
                ans.push_back(diff); 
                sums = v1; 
            }
            else {
                ans.push_back(-1*diff); 
                sums = v2; 
            }
        }
        return ans;
    }
};