/*
https://www.youtube.com/watch?v=13m9ZCB8gjw
*/

node* LCA(node* root, node* a, node*b)
{
	if(root==NULL || root==a||root==b)
	{
		return root;
	}

	node* left = LCA(root->left, a, b);
	node* right = LCA(root->right, a, b);

	if(left!=NULL && right!=NULL)
		return root;

	return (left!=NULL)?left:right;
}