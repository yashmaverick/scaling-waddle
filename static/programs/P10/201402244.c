#include<stdio.h>
#include<stdlib.h>
int N;
typedef struct node
{
	char val[110];
	struct node* next;
}node;
node *head=NULL;
node *start=NULL;
node *end=NULL;
void delete(int value)
{
	if(start!=end&&value>0)
	{
		int i;
		node *p=start;
		for(i=0;i<value;i++)
		{
			start=p->next;
			free(p);
			p=start;
			//end->next=start;
		}
		return;
	}
	if(value<=0)
	{
		return;
	}
	free(start);
	start=NULL;
	end=NULL;
	return;
}
void insert()
{
	if(N>0)
	{
		node *new=(node*)malloc(sizeof(node));
		scanf("%s",new->val);
		new->next=start;
		if(start==NULL)
		{
			start=new;
			end=new;
			return;
		}
		else
		{
			end->next=new;
			end=new;
		}
	}
	else
	{
		head=start;
		start=start->next;
		scanf("%s",head->val);
		end=head;

	}
	return;
}
void print()
{
	if(start==end&&start!=NULL)
	{
		node *p=start;
		printf("%s\n",p->val);
		return;
	}
	if(!(start==NULL&&end==NULL))
	{
		node *p=start;
		while(p!=end)
		{
			printf("%s\n",p->val);
			p=p->next;
		}
		printf("%s",end->val);
		printf("\n");
		return;
	}
	else
		return;
}
int main()
{
	int sun;
	scanf("%d",&N);
	sun=N;
	if(N>1)
	{
		while(1)
		{
			char a;
			scanf("%c",&a);
			if(a=='R')
			{
				int b;
				scanf("%d",&b);
				if(b<sun-N)
				{
					delete(b);
					N=N+b;
				}
				else
				{
					delete(sun-N-1);
					delete(1);
					N=sun;
				}
			}
			if(a=='A')
			{
				int b,c,i;
				scanf("%d",&b);
				for(i=0;i<b;i++)
				{
					insert();
					if(N>0)
						N--;
				}

				//insert(b);
				//if(N>0)
				//N--;
			}
			if(a=='L')
			{
				print();
			}
			if(a=='Q')
			{
				break;
			}
		}
	}
	else if(N==1)
	{
		while(1)
		{
			char a;
			char app[110];
			int aty;
			scanf("%c",&a);
			if(a=='A')
			{
				int b,c,i;
				scanf("%d",&b);
				for(i=0;i<b;i++)
				{
					scanf("%s",app);
					aty=1;
				}

			}
			if(a=='R')
			{
				int b;
				scanf("%d",&b);
				aty=0;
			}
			if(a=='L')
			{
				if(aty==1)
					printf("%s\n",app);
			}
			if(a=='Q')
			{
				break;
			}

		}

	}
	else if(N==0)
	{
		while(1)
		{
			char a;
			char app[110];
			int aty;
			scanf("%c",&a);
			if(a=='A')
			{
				int b,c,i;
				scanf("%d",&b);
				for(i=0;i<b;i++)
				{
					scanf("%s",app);
				}

			}
			if(a=='R')
			{
				int b;
				scanf("%d",&b);
			}
			if(a=='L')
			{
			}
			if(a=='Q')
			{
				break;
			}

		}

	}
	return 0;
}
