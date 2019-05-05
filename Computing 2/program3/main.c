#include "tree.h"

int main()
{
	int x = 0;
	struct node *root = NULL;

	scanf_s("%d", &x);
	root = insert(root, x);
	while(x != -1)
	{
		scanf_s("%d", &x);
		if ( (search(root, x)) || (x == -1) ) 
		{

		}
		else
		{
			insert(root, x);
		}
	}


	inorder(root);
	scanf_s("%d", &x);
	return 0;
}
