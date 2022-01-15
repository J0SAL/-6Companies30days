// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=48c44c43b5f4be5fda20afa332db21a9&pid=700494&user=josal
#define v vector
void topoSort(int curr, v<int> grp[], v<bool> &vis, string &ans){
    if(vis[curr]) return;
    vis[curr] = 1;
    for(int i: grp[curr]){
        if(!vis[i])
            topoSort(i, grp, vis, ans);
    }
    char c = curr+'a';
    ans = c+ans;  //maintain reverse order
}

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        v<int> grp[K];
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            for(int j=0; j<min(s1.size(), s2.size()); j++){
                if(s1[j]!=s2[j]){
                    int u = s1[j]-'a';
                    int v = s2[j]-'a';
                    grp[u].push_back(v);
                    break;//only 1st diff char applicable
                }
            }
        }
        string ans;
        v<bool> vis(K, 0);
        for(int i=0; i<K; i++){
            if(!vis[i]){
                topoSort(i, grp, vis, ans);
            }
        }
        return ans;
    }   
};