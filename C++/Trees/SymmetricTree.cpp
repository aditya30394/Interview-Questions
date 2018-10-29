/*

LeetCode 101 Symmetric tree https://leetcode.com/problems/symmetric-tree/

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

*/

#include <iostream>
#include "BinaryTreeHeader.h"
#include <queue>
using namespace std;


bool isMirror(node* root1, node* root2)
{
    if(root1 == NULL and root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;

    return root1->data == root2->data && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}

bool isSymmetricRecursive(node* root)
{
    return isMirror(root,root);
}

bool isSymmetricIterative(node* root)
{
    queue<node *>q;
    q.push(root);
    q.push(root);

    while(!q.empty())
    {
        node* t1 = q.front(); q.pop();
        node* t2 = q.front(); q.pop();

        if(t1==NULL and t2==NULL)
            continue;
        if(t1==NULL || t2==NULL)
            return false;
        
        if(t1->data != t2->data)
            return false;

        q.push(t1->right);
        q.push(t2->left);
        q.push(t1->left);
        q.push(t2->right);

    }

    return true;
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
	if(isSymmetricRecursive(root))
    {

        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }

    node *root2 = new node(1);
    root2->left   = new node(2);
    root2->right  = new node(2);
    root2->left->left = new node(3);
    root2->left->right = new node(4);
    root2->right->left = new node(4);
    root2->right->right = new node(3);
    if(isSymmetricRecursive(root2))
    {

        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }

    if(isSymmetricIterative(root))
    {

        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    
    if(isSymmetricIterative(root2))
    {

        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }    
    return 0;
}
