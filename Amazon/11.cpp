// submission link : https://practice.geeksforgeeks.org/viewSol.php?subId=4016f78998692fb81b858c2a6a32dc96&pid=700281&user=josal
void helper1(Node *root, vector<int> &arr){
   
    if(root==NULL){
        arr.push_back(-1); //child has NULL i.e. can be a complete binary tree
        return;  
    } 
    arr.push_back(root->data);
    helper1(root->left, arr);
    helper1(root->right, arr);
}

Node* helper2(vector<int> &A, int &i){
    if(i>=A.size() or A[i] == -1){
        i++; // case to handle incomplete binary tree
        return NULL;    
    } 
    Node* root = new Node(A[i++]);
    root->left = helper2(A, i);
    root->right = helper2(A, i);
}
class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        /*
            1
           / \
          2   3
        */
        vector<int> arr;
        helper1(root, arr);
        return arr;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
        int i=0;
        return helper2(A, i);
    }

};