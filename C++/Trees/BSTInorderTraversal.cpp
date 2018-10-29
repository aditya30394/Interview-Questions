// C++ program to print inorder traversal
// using stack.
#include <iostream>
#include "BinaryTreeHeader.h"
#include <stack>
#include <vector>
using namespace std;

/* Iterative function for inorder tree
traversal */

vector<int> inOrder(node* root)
{
    vector<int> inorder;
    stack<node*> nodes;
    if(root == NULL) return inorder;

    while(root!=NULL || !nodes.empty())
    {
        while(root!=NULL)
        {
            nodes.push(root);
            root = root->left;
        }

        root = nodes.top();
        nodes.pop();
        inorder.push_back(root->data);
        root=root->right;

    }
    return inorder;
}

/* Driver program to test above functions*/
int main()
{

	/* Constructed binary tree is
			 3
			/ \
  		   1   5
		  / \
	    -1   2
	*/
	node *root = ConstructTestBST();
	vector<int> inorder = inOrder(root);

	for(int d : inorder)
    {
        cout<<d<<" ";
    }
	return 0;
}
