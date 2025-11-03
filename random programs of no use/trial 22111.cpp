#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*link;
}*top = NULL; 

struct node*stack = NULL;

void pop(int data)
{
    if(top==NULL)
    {
        printf("Stack Underflow");
    }
    else
    {
    	printf("%d is been deleted \n",top -> data);
        top = top -> link;
    }
}

void push(int data){
	struct node* newnode;
	newnode = (struct node*)malloc(4);
	if(newnode == NULL ){
		printf("bc stack me jaga nai hai");
		exit(1);
	}
	newnode -> data = data ;
	newnode -> link = NULL;
	
	newnode -> link = top;
	top = newnode;
}

void display()
{
	struct node *temp;
	temp = top;
	while(temp)
	{
		printf("%d \n",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main()
{
	int choice , data;
	while(1){
		printf("enter choice\n");
		printf("1.push\n2.display\n3.pop\n4.exit\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1 : printf("enter what data ?\n");
			         scanf("%d",&data);
					 push(data);
					 break ;
			case 2 : display(); break ;
			
			case 3 : pop(data);
			break;
			case 4 : exit(1);
			default : printf("error");
		break;
		}

	}
	return 0;
	
}