/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
void closest(struct node *t,int start,int *distance)
{
	if (!t->left && !t->right)
	{
		if (*distance == -1)
			*distance = start;
		else if (start < *distance)
			*distance = start;
		return;
	}
	if (t->left)
		closest(t->left,start+1,distance);
	if (t->right)
	    closest(t->right,start+1,distance);
}
int get_closest(struct node *t)
{
	int distance = -1;
		if (t)
			closest(t, 0, &distance);
		else return -1;
	return distance + 1;
}
void process(struct node *root, int data, int *dist)
{
	int v1, v2,v;
	if (root->data == data)
	{
		v1 = get_closest(root->left);
		v2 = get_closest(root->right);
		if (v1 == -1 && v2 == -1)
			v1 = 0;
		else if (v1 == -1 || (v2 < v1 && v2 != -1))
			v1 = v2;
		if (*dist > v1)
			*dist = v1;
	}
	else if (root->data < data)
	{
		v = get_closest(root->left) + 1;
		if ((*dist == -1 || *dist > v)&&v!=0)
			*dist = v;
		process(root->right, data, dist);
		
	}
	else{
		v = get_closest(root->right);
		if ((*dist == -1 || *dist > v) && v != 0)
			*dist = v;
		process(root->left, data, dist);
	}
	
}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL )
		return -1;
	int dist = -1;
	process(root, temp->data, &dist);
  return dist;
}