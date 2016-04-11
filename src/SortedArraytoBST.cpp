/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node * insert(struct node *root, int data)
{
	struct node *p = root, *q = NULL, *n;
	n = (struct node*)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	while (p)
	{
		q = p;
		if (p->data > data)
			p = p->left;
		else p = p->right;
	}
	if (q == NULL)
		root = n;
	else if (q->data > data)
		q->left = n;
	else q->right = n;
	return root;
}
struct node * doit(struct node *root, int *arr, int start, int end)
{
	int mid = (start + end) / 2;
	root = insert(root, arr[mid]);
	if (end > start)
	{
		root = doit(root, arr, start, mid - 1);
		root = doit(root, arr, mid + 1, end);
	}
	return root;

}
struct node * convert_array_to_bst(int *arr, int len)
{
	if (arr == NULL || len<1)
		return NULL;
	struct node *root = NULL;
	root = doit(root, arr, 0, len - 1);
	return root;
}
