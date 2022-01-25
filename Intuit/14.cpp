// submission link: https://leetcode.com/submissions/detail/627402024/
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int summ  = 0;
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                summ+=grid[i][j];
                if(grid[i][j] == 1) q.push({i,j});
            } 
        }
        if(summ == 0 or summ == n*n) return -1;
        
        int level = -1;
        
        int d[] = {0, 1, 0, -1, 0}; // left - top - right - bottom
        while(!q.empty()){
            int t= q.size();
            while(t--){
                auto [x,y] = q.front(); q.pop();
                // int x = top.first;
                // int y = top.second;
                for(int i=0; i<4; i++){
                    int dx = x+d[i], dy = y+d[i+1];
                    if(dx<0 or dy<0 or dx>=n or dy>=n or grid[dx][dy] == 1) continue;
                    q.push({dx, dy});
                    grid[dx][dy] = 1;
                }   
            }
            level++;
        }     
        return level;
    }
};