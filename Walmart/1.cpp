// submission link: https://leetcode.com/submissions/detail/628290275/
#define pii pair<int,double>


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pii> adj[n]; // from_node: {<to_node, success> , }
        int sz = edges.size();
        for(int i=0; i<sz; i++){
            auto e = edges[i];
            adj[e[0]].push_back({e[1], succProb[i]});
            adj[e[1]].push_back({e[0], succProb[i]});
        }
        
        // for(int i=0; i<n; i++){
        //     cout<<i<<" -> ";
        //     for(auto pp: adj[i]){
        //         cout<<pp.first<<" "<<pp.second<<" | ";
        //     }
        //     cout<<endl;
        // }
        
        
        vector<double> prio(n);
        queue<int> q;
        
        q.push(start);
        prio[start] = 1;
                
        while(!q.empty()){
            int curr_n = q.front(); q.pop();
            
            for(auto [m, p]: adj[curr_n]){
                if(prio[curr_n]*p > prio[m]){
                    prio[m] = prio[curr_n]*p;
                    q.push(m);
                }
            }  
        }   
        
        return prio[end];
    }
};