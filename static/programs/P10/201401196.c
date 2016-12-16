#include<stdio.h>
#include<stdlib.h>

int size;
struct stack
{
	char data[100];
	struct stack *next;
};

typedef struct stack stack;
stack *start=NULL;stack *end=NULL;

void create(stack *top,int n)
{
	int c=0;
	stack *temp[n];
	while(c!=n)
	{
		temp[c]=(stack*)malloc(sizeof(stack));
		temp[c]->next=top;
		top=temp[c];
		if(c==0)
		{
			end=temp[c];
		}
		c++;
	}
	end->next=temp[c-1];
}
void pop(int n)
{
	int c=0;
	while(c!=n)
	{
		if(start==end)
		{
			start=NULL;
		}
		else
			start=start->next;
		c++;
	}
}


void print()
{
	stack *temp1=start,*temp2=end;
	if(start==NULL)
		return;
	else
	{
		while(temp1!=temp2)
		{
			printf("%s\n",temp1->data);
			temp1=temp1->next;
		}
		if(temp1==temp2)
			printf("%s\n",temp1->data);
	}
}

void append(int x)
{
	int c=0;
	while(c!=x)
	{
		end=end->next;
		scanf("%s",end->data);
		if(end==start)
			start=start->next;
		if(start==NULL)
			start=end;
		c++;
	}

}
int main()
{
	char y;
	int n;
	scanf("%d",&size);
	create(NULL,size);
	scanf(" %c",&y);
	while(y!='Q')
	{
		if(y=='A')
		{
			scanf("%d",&n);
			append(n);
		}
		if(y=='R')
		{
			scanf("%d",&n);
			pop(n);
		}
		if(y=='L')
			print();
		scanf(" %c",&y);
	}
	return 0;
}

