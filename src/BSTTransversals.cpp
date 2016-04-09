/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void in(struct node *t, int *arr, int *index)
{   
	if (t->left)
		in(t->left, arr, index);
	arr[*index] = t->data;
	*index = *index + 1;
	if (t->right)
		in(t->right, arr, index);
}
void pre(struct node *t, int *arr, int *index)
{
	arr[*index] = t->data;
	*index = *index + 1;
	if (t->left)
		pre(t->left, arr, index);
	if (t->right)
		pre(t->right, arr, index);
}
void pos(struct node *t, int *arr, int *index)
{
	if (t->left)
		pos(t->left, arr, index);
	if (t->right)
		pos(t->right, arr, index);
	arr[*index] = t->data;
	*index = *index + 1;
}
void inorder(struct node *root, int *arr){
	if (root == NULL || arr == nullptr)
		return;
	struct node *t = root;
	int index = 0;
	in(t, arr, &index);
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == nullptr)
		return;
	struct node *t = root;
	int index = 0;
	pre(t, arr, &index);
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == nullptr)
		return;
	struct node *t = root;
	int index = 0;
	pos(t, arr, &index);
}

