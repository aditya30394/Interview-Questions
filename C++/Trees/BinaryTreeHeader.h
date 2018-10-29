/* A binary tree Node has data, pointer to left child 
and a pointer to right child */
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
	node (int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 

typedef struct node node;

node* ConstructTestBST()
{
	/* Constructed binary tree is
			 3
			/ \
  		   1   5
		  / \
	    -1   2
	*/
	node *root = new node(3);
	root->left	 = new node(1);
	root->right	 = new node(5);
	root->left->left = new node(-1);
	root->left->right = new node(2);
	return root;
}
