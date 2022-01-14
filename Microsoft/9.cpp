// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=8acac87bacd03612dd78a374031d1ea6&pid=700689&user=josal

void calcSum(Node *root, int &cnt, int X){
    if(root==NULL) return;
    if(root->left) calcSum(root->left, cnt, X);
    if(root->right) calcSum(root->right, cnt, X);
    
    int x=0, y=0;
    if(root->left) x=root->left->data;
    if(root->right) y=root->right->data;
    
    root->data+=(x+y);
    if(root->data == X) cnt++;
}

int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int cnt=0;
	calcSum(root, cnt, X);
	return cnt;
}
