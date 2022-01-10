// solution link: https://leetcode.com/submissions/detail/616854016/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0;
        queue<pair<int, int>> rotten;
        int oranges = 0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0) oranges++;
                if(grid[i][j]==2) rotten.push({i,j});
            }
        }
        
        int dx[]={0,-1,0,1};
        int dy[]={-1,0,1,0};
        
        int cnt = 0;
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k;    
            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;   
                rotten.pop();
                for(int i=0;i<4; i++){
                    int xx = x+dx[i];
                    int yy = y+dy[i];
                    if(xx<0 or xx>=n or yy<0 or yy>=m or grid[xx][yy]!=1) continue;
                    // cout<<"x: "<<xx<<endl;
                    // cout<<"y: "<<yy<<endl;
                    rotten.push({xx,yy});
                    grid[xx][yy] = 2;
                }
            }
            if(!rotten.empty()) time++;
        }
        return (oranges == cnt) ? time : -1;
    }
};