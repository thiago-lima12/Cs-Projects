#include<stdio.h> 
#include<stdlib.h> 
#include <stdbool.h>


struct node
{
	int key;
	struct node *left, *right;
};


struct node *newNode(int item);
bool search(struct node *root, int key);
void inorder(struct node *root);
struct node* insert(struct node* node, int key);