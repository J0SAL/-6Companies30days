// https://practice.geeksforgeeks.org/viewSol.php?subId=aaebe8feefa786eee609d510e6a58681&pid=700463&user=josal
void dfs(int curr, vector<int> adj[], vector<int> &vis, int c, int d){
    vis[curr]=1;
    for(int i: adj[curr]){
        if(curr==c and i==d) continue;
        if(!vis[i]) dfs(i, adj, vis, c, d);
    }
}
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> vis(V, 0);
        dfs(c,adj,vis, c, d);
        return !vis[d];
    }
};