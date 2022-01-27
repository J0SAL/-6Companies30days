// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=52216f99f9249f44482621a146508aab&pid=700185&user=josal
int my_inorder(Node *root){
    if(!root) return 0;
    if(root->left == NULL and root->right == NULL){
        int d = root->data;
        root->data = 0;
        return d;
    }
    int left = my_inorder(root->left);
    int right = my_inorder(root->right);
    
    int d=root->data+left+right;
    root->data = left+right;
    
    return d;
}

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        my_inorder(node);
    }
};	