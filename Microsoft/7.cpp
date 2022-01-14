// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=5604db2a0d38948b4f32315b29e73f13&pid=701276&user=josal
#define v vector
int dfs(v<v<int>>& grid, v<v<int>>& vis,int i, int j, int n, int m){
    if(i<0 or j<0 or i>=n or j>=m or vis[i][j] or grid[i][j]==0) return 0;
    vis[i][j] = 1;
    return 1 + dfs(grid, vis, i, j-1, n, m)
             + dfs(grid, vis, i-1, j-1, n, m)
             + dfs(grid, vis, i-1, j, n, m)
             + dfs(grid, vis, i-1, j+1, n, m)
             + dfs(grid, vis, i, j+1, n, m)
             + dfs(grid, vis, i+1, j+1, n, m)
             + dfs(grid, vis, i+1, j, n, m)
             + dfs(grid, vis, i+1, j-1, n, m);
}
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(v<v<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        v<v<int>> vis(n, v<int>(m, 0));
        int maxx = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    maxx = max(maxx, dfs(grid, vis, i, j,  n, m));
                }
            }
        }
        return maxx;
    }
};
