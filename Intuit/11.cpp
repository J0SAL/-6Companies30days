// submission link: https://leetcode.com/submissions/detail/626674802/



/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
#define v vector

class Solution {
public:
    Node *construct_q(v<v<int>> &grid, int row_start, int row_end, int col_start, int col_end, int size){
        int summ = 0;
        for(int i=row_start; i<row_end; i++){
            for(int j=col_start; j<col_end; j++){
                summ+=grid[i][j];
            }
        }
        if(summ == 0){
            return new Node(0, 1);  //val, isLeaf
        }
        if(summ == size*size){
            return new Node(1, 1);  //val, isLeaf
        }
        Node* root = new Node(1, 0); // val (any->true), isLeaf
        size/=2;
        
        root->topLeft= construct_q(grid, row_start, row_start+size, col_start, col_start+size, size);
        root->topRight= construct_q(grid, row_start, row_start+size, col_start+size, col_end, size);
        root->bottomLeft= construct_q(grid, row_start+size, row_end, col_start, col_start+size, size);
        root->bottomRight= construct_q(grid, row_start+size, row_end, col_start+size, col_end, size);
        return root;
    }
    
    Node* construct(v<v<int>>& grid) {
        int n = grid.size();
        return construct_q(grid, 0, n, 0, n, n);
    }
};