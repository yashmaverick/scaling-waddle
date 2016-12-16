#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int V;
typedef struct node
{
	int data;
	struct node * next;
}node;
void insert(node * a[],int s, int d)
{
	node * temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=s;
	temp->next=a[d]->next;
	//	temp->next=NULL;
	a[d]->next=temp;
}
void insert1(node * b[],int s, int d)
{
	node * temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=s;
	temp->next=b[d]->next;
	b[d]->next=temp;
}
int cnt;
int cnt2;
void  dfs(int i,node * a[],int *v)
{
	v[i]=1;
	//printf("i is %d\n", i);
	cnt++;
//	cnt2++;
	node * temp=a[i]->next;
	//	printf("cnt is %d \n",cnt);
	//printf("temp of data %d\n",temp->data);
	//cnt=cnt+1;
	//printf("cnt=%d\n",cnt);
	/*for(i=1;i<=V;i++)
	  printf("%d ",v[i]);*/
	while(temp!=NULL)
	{
		//	printf("a of data %d\n",a[i]->data);
		//	printf("temp of data %d\n",temp->data);
		//	printf("v[t->d]%d\n",v[temp->data]);
		if(v[temp->data]==0)
		{
			//		printf("temp-> data %d \n",temp->data);
			//printf("a\n");
			//	if(temp->data==b[])
			//	else{
			v[i]=1;
			dfs(temp->data,a,v);
			//	}
		}
		temp=temp->next;
	}
}
void  dfs2(int i,node * b[],int *v)
{
	v[i]=1;
	cnt++;
	cnt2++;
	node * temp=b[i]->next;
	while(temp!=NULL)
	{
		if(v[temp->data]==0)
		{
			v[i]=1;
			dfs2(temp->data,b,v);
		}
		temp=temp->next;
	}
}
int main()
{
	int i,n,j,k,t,m,count,l;
	scanf("%d",&t);
	while(t--)
	{	count=0;
		scanf("%d",&V);
		int v[V+1];
		node * a[V];
		node * b[V];
		for(i=1;i<=V;i++)
		{
			v[i]=0;
			a[i]=(node *)malloc(sizeof(node));
			b[i]=(node *)malloc(sizeof(node));
			a[i]->data=i;
			b[i]->data=i;
			a[i]->next=NULL;
			b[i]->next=NULL;
		}
		for(i=0;i<V;i++)
		{
			scanf("%d",&n);
			for(j=0;j<n;j++)
			{
				scanf("%d",&m);
				insert(a,i+1,m);
				insert1(b,m,i+1);
			}
		}
		node *temp;
		/*	for(i=1;i<=V;i++)
			{
			temp=b[i];
			while(temp!=NULL)
			{
			printf("%d ",temp->data);
			temp=temp->next;
			}
			printf("\n");
			}*/
		for(j=1;j<=V;j++)
		{
			cnt=0;
			for(k=1;k<=V;k++)
				v[k]=0;
			dfs(j,a,v);
			if(cnt==V)
			{
				count++;
				break;
			}
		}
		if(count==1){
		for(k=1;k<=V;k++)
			v[k]=0;
		cnt2=0;
		dfs2(j,b,v);
		
		printf("%d\n",cnt2);
		}
		else
			printf("0\n");
	}
	return 0;
}
