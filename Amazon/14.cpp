// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=78f3d7879bbd8952f02b1ac54c70c8c4&pid=702131&user=josal
// using DFS
class Solution {
  public:
    int min_time=0;
    void burnTree(Node *root, Node *block_node, int time){
        if(root==NULL or root==block_node) return;
        min_time = max(min_time, time);
        burnTree(root->left, block_node, time+1);
        burnTree(root->right, block_node, time+1);
    }
    int minTime_(Node* root, int target) 
    {
        // Your code goes here
        if(root == NULL) return -1; //shows end of tree
        if(target==root->data){
            burnTree(root,NULL,0);
            return 1;//for all parents it'll take 1
        }
        
        int left = minTime_(root->left, target);
        if(left!=-1){
            burnTree(root, root->left, left);   
            return left+1;
        }
        int right = minTime_(root->right, target);
        if(right!=-1){
            burnTree(root, root->right, right);
            return right+1;
        }
        return -1;
    }
    
    int minTime(Node* root, int target){
        int not_needed = minTime_(root, target);
        return min_time;
    }
};