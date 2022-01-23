// submission link: https://leetcode.com/submissions/detail/625945521/

#define v vector

void dfs(v<v<int>>& heights, int i, int j, int prev, v<v<bool>> &ocean){
    if(i<0 or j<0 or i>=heights.size() or j>=heights[0].size()) return;
    if(ocean[i][j] == 1) return;
    if(heights[i][j]<prev) return;
    
    ocean[i][j] = 1;
    
    dfs(heights, i+1, j, heights[i][j], ocean);
    dfs(heights, i-1, j, heights[i][j], ocean);
    dfs(heights, i, j+1, heights[i][j], ocean);
    dfs(heights, i, j-1, heights[i][j], ocean);
}


class Solution {
public:
    v<v<int>> pacificAtlantic(v<v<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        v<v<int>> ans;
        v<v<bool>> pacific(n, v<bool>(m, 0));
        v<v<bool>> atlantic(n, v<bool>(m, 0));
        
        for(int i=0; i<m; i++){
            dfs(heights, 0, i, INT_MIN, pacific);
            dfs(heights, n-1, i, INT_MIN, atlantic);
        }
        for(int i=0; i<n; i++){
            dfs(heights, i, 0, INT_MIN, pacific);
            dfs(heights, i, m-1, INT_MIN, atlantic);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] and atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};