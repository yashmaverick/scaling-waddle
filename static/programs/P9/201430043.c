#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<ctype.h>
int mod; 

typedef struct node{
	int *c;
	int Sum;
	struct node *next;
}node ;

//node *a,*temp,*head=NULL,*start=NULL,*b;

/*void headstart(node *head,node *start,node *a)
  {
  if(head->Sum <= a->Sum)
  start->next=a;
  else
  {
  a->next=start;
  start=a;
  }
  }*/

void Printlist(node *a)
{
	int i;
	while(a!=NULL)
	{
		printf("%d\n",a->Sum);
		for(i=1;i<=a->c[0];i++)
			printf("%d\n",a->c[i]);
		a=a->next;
		printf("\n");
	}

}

int Summ(int A,int B)
{
	A=(A+B)%mod;
	return A;
}

int main()
{
	int j,n,m;
	scanf("%d",&n);
	scanf("%d",&mod);
	node *a,*temp,*head=NULL,*start=NULL,*b;
	while(n--)
	{
		scanf("%d",&m);
		a=(node *)malloc(sizeof(node));
		a->c=(int *)malloc((m+1)*sizeof(int));
		a->c[0]=m; a->Sum=0; a->next=NULL;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a->c[j]);
			a->Sum=Summ(a->Sum,a->c[j]);
		}
//		SortInsert(head,start,a,b,temp);
		if(start==NULL)
		{
			head=a;
			start=head;
		}
		else
		{
			head=start;
			while(head->Sum <= a->Sum && head->next != NULL)
			{
				b=head;
				head=head->next;
			}
			if(head==start)
			{
				//headstart(head,start,a);
				if(head->Sum <= a->Sum)
					start->next=a;
				else
				{
					a->next=start;
					start=a;
				}
			}
			else if(head->next == NULL && head->Sum <= a->Sum)
				head->next=a;
			else if(head->Sum > a->Sum)
			{
				temp=b->next;
				b->next=a;
				a->next=temp;
			}
			else
			{
				temp=head->next;
				head->next=a;
				a->next=temp;
			}
		}
	}
	a=start;
	Printlist(a);
	return 0;
}
