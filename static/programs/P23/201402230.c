#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *a[1000000];
void insert(int x,int y);
void insertheap(int n);
void delete();
void lexico(int n);
int inarray[1000000],heap[1000000],ans[1000000];
int size;
int top;
int main()
{
	int n,m,i,x,y;
	size=0,top=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		inarray[i]=0;
	for(i=1;i<=n;i++)
		a[i]=NULL;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		insert(x,y);
	}
//	for(i=1;i<=n;i++)
//		printf("%d ",inarray[i]);
	for(i=1;i<=n;i++)
	{
		if(inarray[i]==0)
		{	
//			printf("%d\n",i);
			insertheap(i);
		}
	}
//	printf("size%d\n",size);
//	printf("insert\n");
//	for(i=1;i<=size;i++)
//	printf("%d ",heap[i]);
//	printf("\n");
	lexico(heap[1]);
//	printf("top %d\n",top);
	for(i=0;i<top-1;i++)
	{	
		if(i!=top-2)
			printf("%d ",ans[i]);
		else
			printf("%d",ans[i]);
	}
//	delete();
//	for(i=1;i<=size;i++)
//		printf("%d ",heap[i]);
	printf("\n");
return 0;
}
void insert(int x,int y)
{
	node *temp;
	node *new=(node *)malloc(sizeof(node));
	new->data=y;
	inarray[y]++;
	if(a[x]==NULL)
	{
		a[x]=new;
		new->next=NULL;
	}
	else
	{
		temp=a[x];
		a[x]=new;
		new->next=temp;
	}
}
void insertheap(int n)
{
	size++;
	heap[size]=n;
	int now=size;
	while(now>1 && heap[now/2]>n )
	{
		heap[now]=heap[now/2];
		heap[now/2]=n;
		now=now/2;
	}
}
void delete()
{
	heap[1]=heap[size];
	size--;
	int now=1;
	int no=heap[1];
	while(now<=size/2 &&(heap[2*now]<no || heap[now*2+1]<no) )
	{
		int t;
		if(heap[2*now]>heap[2*now+1] && heap[2*now+1]!=0)
		{
			t=heap[now];
			heap[now]=heap[2*now+1];
			heap[2*now+1]=t;
			now=now*2+1;
		}
		else if(heap[2*now]<=heap[2*now+1] && heap[2*now]!=0)
		{
			t=heap[now];
			heap[now]=heap[2*now];
			heap[2*now]=t;
			now=now*2;
		}
	}
}
void lexico(int n)
{
	int i;
	int num=n;
	ans[top]=n;
	top++;
//	printf("top %d\n",top);
	delete();
//	printf("delete\n");
//	for(i=1;i<=size;i++)
//		printf("%d ",heap[i]);
//	printf("\n");
//	printf("size %d\n",size);
	if(size>=0)
	{
//		printf("entered\n");
		node *p=a[num];
		while(size>=0)
		{
			while(p!=NULL)
			{
//				printf("entered\n");
//				printf("p->data %d\n",p->data);
				inarray[p->data]--;
				if(inarray[p->data]==0)
				{	
//					printf("entered\n");
					insertheap(p->data);
//					printf("insert\n");
//					for(i=1;i<=size;i++)
//						printf("%d ",heap[i]);
//					printf("\n");
				}
				p=p->next;
			}
		//	if(size!=0)
//			for(i=1;i<=size;i++)
//				printf("%d ",heap[i]);
//			printf("\n");
			lexico(heap[1]);
		}
	}
}


