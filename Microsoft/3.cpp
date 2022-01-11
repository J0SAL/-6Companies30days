// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=b52b524425a2b490360c7df2fd2f16f9&pid=701989&user=josal

void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    // transpose and upside-down
    int n=matrix.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n; j++){
            swap(matrix[i][j], matrix[n-i-1][j]);
        }
    }
}