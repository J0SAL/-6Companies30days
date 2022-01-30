// submission link: https://leetcode.com/submissions/detail/631046034/
const int MOD = 1e9+7;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long maxx = 0;
        long long curr = 0;
        
        vector<pair<int,int>> p;
        for(int i=0; i<n; i++){
            p.push_back({efficiency[i], speed[i]});
        }
        
        sort(p.rbegin(), p.rend());
        
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        //--
        
        //---
        for(int i=0; i<n; i++){
            curr += p[i].second;
            pq.push(p[i].second);
            
            if(pq.size()>k){
                curr -= pq.top();
                pq.pop();
            }
            
            maxx = max(maxx, p[i].first*curr);
        }
        
        return maxx%MOD;
    }
};