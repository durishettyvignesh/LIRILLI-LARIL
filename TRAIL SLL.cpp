#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node*link;
};

int main()
{
	struct node *head = (struct node*)malloc(100);
	head -> data = 'a';
	head -> link = NULL;
	
	struct node *tail = (struct node*)malloc(4);
	tail -> data = 'b';
	head -> link = tail;
	tail -> link = NULL;
	
	struct node *curr = (struct node*)malloc(4);
	curr -> data = 'c';
	head -> link -> link = curr;
	curr -> link = NULL;
	
	struct node *curr1 = (struct node*)malloc(4);
	curr1 -> data = 'd';
	head -> link -> link -> link = curr1;
	curr1 -> link = NULL;
	
	struct node *temp;
	temp = head;
	while(temp)
	{
		printf("%c->",temp->data);
		temp = temp->link;
	}
	printf("\n");
	printf("\n");
	
	int count = 0;
	struct node *pt = NULL;
	pt = head;
	while(pt != NULL)
	{
		count ++;
		//printf("%d->",pt->data);
		pt = pt -> link ;
	}
	
	printf("\n\n%d is count",count);
	printf("\n%d",sizeof(char));
	return 0;
}
