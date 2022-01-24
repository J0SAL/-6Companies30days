// submission link: https://leetcode.com/submissions/detail/626684453/
#define v vector

class Solution {
public:
    
    bool cycle(int curr, v<v<int>> &g, v<bool> &vis, v<bool> &order, v<int> &ans){
        vis[curr] = 1;
        order[curr] = 1;
        for(auto i: g[curr]){
            if(!vis[i]){
                if(cycle(i, g, vis, order, ans)){
                    return 1;
                }
            }
            else if(order[i]){
                return 1;
            }
        }
        order[curr] = 0;
        ans.push_back(curr);
        return 0;
    }
    v<int> findOrder(int numCourses, v<v<int>>& prerequisites) {
        int p = prerequisites.size();
        v<v<int>> directed_g(numCourses);
        for(int i=0; i<p; i++){
            directed_g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        v<bool> vis(numCourses, 0);
        v<bool> order(numCourses, 0);
        v<int> ans;
        
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(cycle(i, directed_g, vis, order, ans)){
                    return {};
                }
            }
        }
        
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};