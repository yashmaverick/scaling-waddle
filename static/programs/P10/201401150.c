#include <stdio.h>
#include <stdlib.h>
#define node struct node

node
{
	char A[101];
	node* next;
};

int main()
{
	int N,n,i,j;char c;
	scanf("%d",&N);
	node* head=NULL,*end=NULL;
	node *back=NULL,*front=NULL;
	for(j=0;j<N;j++)
	{
		node* p=(node*)malloc(sizeof(node));
		if(j==0)
			end=p;
		p->next=head;
		head=p;
	}
	end->next=head;
	while(1)
	{
		scanf("%c",&c);
		if(c=='Q')
			break;
		else if(c=='A')
		{	
			scanf("%d",&n);//char temp[101];
			for(i=0;i<n;i++)
			{				
				
				if(back==NULL)
				{
					scanf("%s",head->A);
					front=back=head;
				}
				else
				{
					back=back->next;
					scanf("%s",back->A);
					if(back==front)
						front=front->next;
				}
				
			}
		}
		else if(c=='R')
		{
			scanf("%d",&n);	
			for(i=0;i<n;i++)
			{
				if(front==back)
					front=back=NULL;
				else
					front=front->next;	
			}
		}
		else if(c=='L')
		{
			if(back!=NULL)
			{
				node *t=front;
				while(t!=back)
				{
					printf("%s\n",t->A);
					t=t->next;
				}
				printf("%s\n",t->A);
			}
		}
	}

	return 0;
}