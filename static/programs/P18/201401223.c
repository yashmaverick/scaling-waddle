#include<stdio.h>
#include<stdlib.h>
/*
   struct queue;
   {
   int data[100];
   int r,f;
   };
   typedef struct queue q;
   int isempty(q* Q)
   {
   if(Q->r=='-1')
   return 1;
   return 0;
   }
   int isfull(q* Q)
   {
   if(Q->=='max')
   return 1;
   return 0;
   }
 */
struct node
{
	int data;
	struct node* next;
};
struct node* a[1001];
struct node* b[1001];
void inserta(int i,int j)
{
	struct node* new;
	new = (struct node*)malloc(sizeof(struct node));
	new->next = a[i];
	new->data = j;
	a[i] = new;
	return ;
}
void insertb(int i,int j)
{
	struct node* new;
	new = (struct node*)malloc(sizeof(struct node));
	new->next = b[i];
	new->data = j;
	b[i] = new;
	return ;
}
int count=0;
int visited[1001];
void dfsa(int i)
{
	struct node* temp;
	temp=a[i];
	count++;
	visited[i]=1;
	while(temp!=NULL)
	{
		i=temp->data;
		if(visited[i]!=1)
			dfsa(i);
		temp=temp->next;
	}
}
void dfsb(int i)
{
	struct node* temp;
	temp=b[i];
	count++;
	visited[i]=1;
	while(temp!=NULL)
	{
		i=temp->data;
		if(visited[i]!=1)
			dfsb(i);
		temp=temp->next;
	}
}
int main()
{
	int tc,i,j,k,l,n,m,x;
	struct node* tmp;
	scanf("%d",&tc);
	while(tc--)
	{
		for(i=1;i<=1000;i++)
			a[i] = NULL;
		for(i=1;i<=1000;i++)
			b[i] = NULL;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&x);
				inserta(i,x);
				insertb(x,i);
			}
		}
		//	for(i=0;i<n;i++)
		//	{
		//		tmp = a[i];
		//		if(tmp!=NULL)
		//		{
		//			printf("%d->",i+1);
		//			while(tmp!=NULL)
		//			{
		//				printf("%d ",tmp->data);
		//				tmp = tmp->ptr;
		//			}
		//			printf("\n");
		//		}
		//	}
		int index,flag=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=1000;j++)
				visited[j]=0;
			count=0;
			dfsb(i);
		//	printf("c-%d i-%d",count,i);
			if(count==n)
			{
//				printf("c-%d i-%d",count,i);
				index=i;
				flag=1;
				break;
			}
		}
		count=0;
		for(i=1;i<=1000;i++)
			visited[i]=0;
		dfsa(index);
	if(flag==0)
		printf("0\n");
	else
		printf("%d\n",count);
	}
	return 0;
}
