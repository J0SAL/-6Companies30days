// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=8c3ab70512d07d961f9f989b0f885d37&pid=701264&user=josal

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int start_r = 0, start_c = 0;
        int end_r = r, end_c = c;
        
        vector<int> ans;
        while(start_r<end_r and start_c<end_c){
            for(int i=start_c; i<end_c; i++){
                ans.push_back(matrix[start_r][i]);
            }
            start_r++;
            for(int i=start_r; i<end_r; i++){
                ans.push_back(matrix[i][end_c-1]);
            }
            end_c--;
            if(start_r<end_r){
                for(int i=end_c-1; i>=start_c; i--){
                    ans.push_back(matrix[end_r-1][i]);
                }
                end_r--;
            }
            if(start_c<end_c){
                for(int i=end_r-1; i>=start_r; i--){
                    ans.push_back(matrix[i][start_c]);
                }
                start_c++;
            }
        }
        
        return ans;
    }
};