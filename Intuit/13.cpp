// submission link: https://leetcode.com/submissions/detail/627375465/

void rotate(vector<int> &v, int i, int j){
    while(j>i){
        swap(v[j], v[j-1]);
        j--;
    } 
}
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> end_zeros(n, 0);
        for(int i=0; i<n; i++){
            int j=n-1;
            while(j>=0 and grid[i][j] == 0){
                j--;
                end_zeros[i]++;
            }
        }
        // for(int i=0; i<n; i++) cout<<end_zeros[i]<<" "; cout<<endl;
        int swaps=0;
        for(int i=0; i<n; i++){
            int req = n-i-1;
            int j;
            for(j=i; j<n; j++){
                if(end_zeros[j] >= req) break;
            }
            if(j==n) return -1;
            swaps+=(j-i);
            rotate(end_zeros, i, j);
        }
        
        return swaps;
    }
};