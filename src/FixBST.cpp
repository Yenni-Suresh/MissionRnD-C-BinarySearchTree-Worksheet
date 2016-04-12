/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node * location(struct node *root, int data)
{
	struct node *p = root, *q = NULL;
	while (p)
	{
		q = p;
		if (p->data == data)
			return p;
		if (p->data > data)
			p = p->left;
		else p = p->right;
	}
	return q;
}
void fix(struct node *p[])
{
	p[0]->data = p[0]->data + p[1]->data;
	p[1]->data = p[0]->data - p[1]->data;
	p[0]->data = p[0]->data - p[1]->data;
}
void find(struct node *t, struct node *p[], struct node *root)
{
	if (t->right && p[0] == NULL)
	{
		p[1] = location(root, t->right->data);
		if (t->right == p[1])
			find(t->right, p, root);
		else{
			   p[0] = t->right;
			   if (root->data > root->right->data && root->left->data < root->right->data)
				   p[1] = root;
		   }
	}
	if (t == root && p[0] == NULL && t->data < t->left->data)
	{
		p[1] = location(root->left, root->data);
		p[0] = root;
	}
   else if (t->left && p[0] == NULL)
	{
		p[1] = location(root, t->left->data);
		if (t->left == p[1])
			find(t->left, p, root);
		else p[0] = t->left;
	}
}

void fix_bst(struct node *root){

	struct node *p[2] = { NULL, NULL };
	if (root == NULL)
		return;
	find(root, p, root);	
	fix(p);
}
