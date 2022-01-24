// submission link: https://leetcode.com/problems/number-of-provinces/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n, 0);
        int cnt=0;
        for(int i=0;i<n; i++){
            if(vis[i] == 0){
                cnt++;    
                dfs(i, isConnected, vis);
            }
        }
        return cnt;
    }
    
    void dfs(int node, vector<vector<int>> &isConnected, vector<bool> &vis){
        if(vis[node]) return;
        
        vis[node] = 1;
        int n = isConnected.size();
        for(int i=0; i<n; i++){
            if(i!=node and isConnected[node][i]){
                dfs(i, isConnected, vis);
            }
        }
    }
};