// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=f5d1298a6561d407b8e96f3d857a54c8&pid=700184&user=josal
class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           int sz = q.size();
           Node *curr=NULL, *prev=NULL;
           for(int i=0; i<sz; i++){
               curr = q.front();
               q.pop();
               if(prev!=NULL) prev->nextRight = curr;
               if(curr->left!=NULL) q.push(curr->left);
               if(curr->right!=NULL) q.push(curr->right);
               prev = curr;
           }
       }
    }    
      
};