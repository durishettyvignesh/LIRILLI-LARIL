#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
}*start=NULL,*t,*t1;

void insertbeg();
void insertend();
void insertmid();
void deletebeg();
void deleteend();
void deletemid();
void display();
void search();
int main() {
	int choice;
	while(1) {
		printf("\n\n**SINGLE LINKED LIST\n");
		printf("\n 1.insert at the beginning\n 2.insert at the end\n 3.insert at the specific location\n 4.delete at the beginning\n 5.delete at the end\n 6.delete at the specific location\n 7.display\n 8.search\n 9.exit\n");
		printf("enter your choice:\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				insertbeg();
				break;
			case 2:
				insertend();
				break;
			case 3:
				insertmid();
				break;
			case 4:
				deletebeg();
				break;
			case 5:
				deleteend();
				break;
			case 6:
				deletemid();
				break;
			case 7:
				display();
				break;
			case 8:
				search();
				break;
			case 9:
				exit(0);
			default:
				printf("wrong selection!!!try again!!!\n");
		}
	}
}
void insertbeg() {
	struct node*nn;
	int a;
	nn=(struct node*)malloc (sizeof(struct node));
	printf("enter data:");
	scanf("%d",&nn->data);
	a=nn->data;
	nn->next=NULL;
	if(start==NULL) {
		printf("\n list is empty,so new node inserted as stat node\n");
		start=nn;
	} else {
		nn->next=start;
		start=nn;
	}
	printf("\n %d successfully inserted\n",a);
}


void insertend() {
	struct node*nn,*t;
	int b;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("\n enter data:");
	scanf("%d",&nn->data);
	b=nn->data;
	nn->next=NULL;
	if(start==NULL) {
		printf("\n list is empty,so new node inserted as start node \n");
		start=nn;
	} else {
		t=start;
		while(t->next!=NULL) {
			t=t->next;
		}
		t->next=nn;
	}
	printf("%d is successfully inserted\n",b);
}
void insertmid() {
	struct node*nn,*t=start;
	int x,v;
	nn=(struct node*)malloc(sizeof(struct node));
	if (start==NULL) {
		printf("single linked list is empty\n");
		return;
	}
	printf("\n enter data:");
	scanf("%d",&nn->data);
	v=nn->data;
	nn->next=NULL;
	         printf("enter data after which number is to be inserted:\n");
	scanf("%d",&x);
	while(t!=NULL&&t->data!=x) {
		t=t->next;
	}
	if(t==NULL) {
		printf("\n data does not exist");
		return;
	} else {
		nn->next=t->next;
		t->next=nn;
		printf("%d succesfully inserted\n");
	}
}
void deletebeg() {
	struct node*t=start;
	if(start==NULL) {
		printf("\n single linked list is empty");
		return;
	} else {
		if(start->next==NULL) {
			start=NULL;

		} else {
			start=start->next;
			t->next=NULL;

		}
	}
	printf("\n %d is successfully deleted",t->data);
	free(t);

}



void deleteend() {
	struct node*t=start,*t1;
	int x;
	if(start==NULL) {
		printf("\n single linked list is empty");
	} else {
		if(start->next==NULL) {
			start=NULL;

		} else {
			t1=t->next;
			while(t1->next!=NULL) {
				t=t->next;
				t1=t1->next;
			}
			t->next=NULL;
			printf("\n %d is successfully deleted",t1->data);
			free(t1);
		}
	}
}


void deletemid() {
	struct node*t=start;
	*t1;
	int x;
	if(start==NULL) {
		printf("\n single linked list is empty");
	} else {
		if(start->next==NULL) {
			start=NULL;

		} else {
			printf("enter data to be deleted:");
			scanf("%d",&x);
			t1=start->next;
			while(t1!=NULL&&t1->data!=x) {
				t=t->next;
				t1=t1->next;

			}
			if(t1==NULL) {
				printf("\n data does not exist",x);

			} else {
				t->next=t1->next;
				t1->next=NULL;
				printf("\n %d is succesfully deleted",t1->data);
				free(t1);

			}
		}
	}
}
void display() {
	struct node*t;
	if(start==NULL) {
		printf("single linked list is empty\n");
		return;
	}
	printf("elements are :\n");
	t=start;
	while(t!=NULL) {
		printf("->%d",t->data);
		t=t->next;

	}
	return;
}
void search() {
	struct node*t;
	int item,i=0,flag;
	t=start;
	if(t==NULL) {
		printf("\n empty list\n");

	} else {
		printf("\n enter item which you want to search?\n");
		scanf("%d",&item);
		while(t!=NULL) {
			if(t->data==item) {
				printf("item found at location %d ",i+1);
				flag=0;
				break;

			} else {
				flag=1;

			}
			i++;
			t=t->next;

		}
		if(flag==1) {
			printf("item not found\n");

		}
		return;
	}
}
