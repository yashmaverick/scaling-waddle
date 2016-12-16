#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	char s[101];
	int f;
	struct node* next;
}node;

int main()
{
	int n,N,i=0;
	char c;
	node *head=NULL,*tail,*x;
	scanf("%d%*c",&N);
	n=N;
	while(n--)
	{
		x=(node*) malloc(sizeof(node));
		x -> next = NULL;
		if(head == NULL) head = tail = x;
		else
		{
			tail -> next = x;
			tail -> f =0;
			tail = tail -> next;
		}
	}
	tail -> next = head;
	c = getchar();
	while(c != 'Q')
	{
		if(c == 'A')
		{
			scanf("%d",&n);
			while(n--)
			{
				if(head == tail) head = head -> next;
				scanf("%s",tail->s);
				tail -> f = 1;
 				tail = tail -> next;
			}
		}
		else if(c == 'R')
		{
			scanf("%d",&n);
			x=head;
			while(n)
			{
				if(head -> f == 1)
				{
					n--;
					strcpy(head -> s,"");
					head -> f = 0;
				}
				head = head -> next;
				if(x == head) break;
			}
		}
		else if(c != 'Q')
		{
			if(head -> f == 1) { printf("%s\n",head -> s); }
			x = head -> next;
			while(x != head)
			{
				if(x -> f == 1)
					printf("%s\n",x -> s);
				x = x -> next;
			}
		}
		else break;
		getchar();
		c=getchar();
	}
	return 0;
}
