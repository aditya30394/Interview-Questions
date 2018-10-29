#include <iostream>
#include "BinaryTreeHeader.h"
#include <stack>
using namespace std;

bool isBST(node* root)
{
    if(root==NULL) return true;

    node* prev = NULL;
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

        if(prev!=NULL and prev->data >= root->data) return false;
        prev=root;
        root = root->right;
    }
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
	if(isBST(root))
    {

        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
	
    node *root2 = new node(1);
    root2->left   = new node(2);
    root2->right  = new node(3);
    root2->left->left = new node(4);
    root2->left->right = new node(5);
    if(isBST(root2))
    {

        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }

    return 0;
}
