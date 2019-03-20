/**********************************************************************
Program: <reverse linked list>
Author: <Thiago Lima>
Date: <2/8/2019>
Time spent: <1 hour>
Purpose: The purpose of this program is to have a linked list to to 
reverse the data inside it 
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//declare your function here.
void reverse(struct node **head);

int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	//call your function to reverse the list (should work for any list given the head node).
	
	temp = head;
	printf("This is the first linked list: ");
	while (temp != NULL)
	{
		
		printf("%d ", temp->data);
		temp = temp->next;
	}


	reverse(&head);
	//print the reversed list.
	temp = head;
	printf("\nThis is the new linked list:   ");
	while (temp != NULL)
	{
		
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return 0;
}

//Define your function here
void reverse(struct node **head)
{
	struct node *place1;
	struct node *spot2;
	struct node *location3;
	 
	place1 = spot2 = location3 = *head;
	spot2 = spot2->next;
	place1 = place1->next->next;
	location3 ->next = NULL;
	spot2->next = location3;

	while (place1 != NULL)
	{
		location3 = spot2;    //location is set to one behind location in spot
		spot2 = place1;   // spot become next or place
		place1 = place1->next;  // place becomes next
		spot2->next = location3;  // spot next become location or one behind spot in location
	}
	*head = spot2; 
}