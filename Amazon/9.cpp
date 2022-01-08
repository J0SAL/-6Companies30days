// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=0034a63f4bc5372c1a0e5a8fea5c7e8d&pid=705293&user=josal

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        int row[9][9]={0}, col[9][9]={0}, box[9][9]={0};
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(mat[i][j]!=0){
                    row[i][mat[i][j]-1]++;
                    col[j][mat[i][j]-1]++;
                    box[(i/3)*3+j/3][mat[i][j]-1]++; //cancel's odd no (i/3)*3
                
                    if(row[i][mat[i][j]-1]>1 or col[j][mat[i][j]-1]>1 or box[(i/3)*3+j/3][mat[i][j]-1]>1)
                        return 0;
                }
            }
        }
        return 1;
    }
};