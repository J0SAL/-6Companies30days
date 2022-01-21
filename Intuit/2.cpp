// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=9b37e5282866f5c8fee7e1b8e761e429&pid=702088&user=josal
#define v vector

bool isValid(int n, int m, int i, int j){
    if(i<0 or j<0 or i>=n or j>=m) return 0;
    return 1;
}

bool dfs(v<v<char>>& board, string &word, int i, int j, int n){
    if(n==word.size()) return 1;
    
    if(!isValid(board.size(), board[i].size(), i, j)) return 0;
    if(word[n]!=board[i][j]) return 0;
    
    board[i][j] = '0';
    bool stats = (dfs(board, word, i+1, j, n+1) 
            or dfs(board, word, i-1, j, n+1) 
            or dfs(board, word, i, j+1, n+1) 
            or dfs(board, word, i, j-1, n+1));
    
    board[i][j] = word[n];
    return stats;
}

class Solution {
public:
    bool isWordExist(v<v<char>>& board, string word) {
        // Code here
        if(word == "") return 0;
        int n=board.size();
        int m=board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0] and dfs(board, word, i, j, 0))
                    return 1;
            }
        }
        return 0;
    }
};