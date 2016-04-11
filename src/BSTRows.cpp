/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void process(struct node *t, int *out, int *index, int *h, int l, int height, struct node *root)
{
	if (l > *h || *h == height)
		return;
	if (l == *h)
	{
		out[*index] = t->data;
		*index = *index + 1;
	}
	if (t->right)
		process(t->right, out, index, h, l + 1, height, root);
	if (t->left)
		process(t->left, out, index, h, l + 1, height, root);
	if (t == root)
	{
		*h = *h + 1;
		process(root, out, index, h, 0, height, root);
	}
}
int tree_height(struct node *h, int *size)
{
	int l = 0, r = 0;
	if (h->left)
		l = tree_height(h->left, size);
	*size = *size + 1;
	if (h->right)
		r = tree_height(h->right, size);
	if (l > r)
		return l + 1;
	else return r + 1;
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int size = 0, *out, h = 1, index = 1, height;
	height = tree_height(root, &size);
	out = (int*)malloc(size*sizeof(int));
	out[0] = root->data;
	process(root, out, &index, &h, 0, height, root);
	return out;
}