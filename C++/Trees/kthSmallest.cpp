#include <iostream>
#include "BinaryTreeHeader.h"
#include <stack>
using namespace std;

int kthSmallest(node* root, int k)
{
    stack<node*> s;

    while(root!=NULL || !s.empty())
    {
        while(root!=NULL)
        {
            s.push(root);
            root = root->left;
        }

        root = s.top();
        s.pop();

        if(--k==0) return root->data;
        root = root->right;
    }
    return -1;
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

    cout<<kthSmallest(root,1)<<endl;
    cout<<kthSmallest(root,2)<<endl;
    cout<<kthSmallest(root,5)<<endl;

    return 0;
}
