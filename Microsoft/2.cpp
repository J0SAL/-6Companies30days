// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=f57d16998fb343c155fba65e751d1d8f&pid=702128&user=josal
#define v vector
#define ss second
#define ff first
#define pb push_back
class Solution {
public:
    
    bool cycle(int e, v<v<int>> &g, v<bool> &vis, v<bool> &order){
        vis[e]=1;
        order[e]=1;
        for(int i: g[e]){
            if(!vis[i]){
                if(cycle(i, g, vis, order)){
                    return 1; // cycle present
                }
            }else if(order[i]){
                return 1;
            }
        }
        order[e]=0;
        return 0; //cycle not present
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    v<v<int>> directed_graph(N);
	    v<bool> vis(N,0);
	    v<bool> order(N,0); //to check visited and no cycle
	    
	    for(auto p: prerequisites) directed_graph[p.ff].pb(p.ss);
	    
	    for(int i=0; i<N; i++){
	        if(!vis[i]){
	            if(cycle(i, directed_graph, vis, order)){
	                return 0;
	            }
	        }
	    }
	    return 1;
	}
};