// stacks using array

#include<stdio.h>
#include<stdlib.h>

int starr[4] ;
int top = -1;

void push(int data)
{
	top = top +1;
	starr[top] = data;
}

void display()
{
	for(int i = 0; i<=top ; i++)
	{
	
		printf("%d \n",starr[i]);}
	
}

int pop();

int main()
{
	if(1){
	
    push(9);
    push(34);
    push(23);
	push(3343);
	display();
	int data = pop();
	
	printf("%d is deleted\n",data);	}
	else{
		printf("if statement was false\n");
	}
}

int pop(){
	int value ;
	value = starr[top];
	top = top - 1;
	return value;
}

