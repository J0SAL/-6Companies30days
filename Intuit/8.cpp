// submission link: https://leetcode.com/submissions/detail/625906075/

double calcDist(int x1, int x2, int y1, int y2){
    int xdiff = x2-x1;
    int ydiff = y2-y1;
    
    double dist = sqrt(xdiff*xdiff + ydiff*ydiff);
    return dist;
}

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        unordered_map<int, unordered_map<double, int>> mp; //{point, {dist, cnt}}
        int n=points.size();
        
        if(n<3) return 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    double dist = calcDist(points[i][0], points[j][0], points[i][1], points[j][1]);
                    mp[i][dist]++;
                }
            }
        }
        
        int cnt= 0;
        for(auto &dist: mp){
            for(auto &m: dist.second){
                cnt+=(m.second*(m.second-1));
            }
        }
        
        return cnt;
        
    }
};