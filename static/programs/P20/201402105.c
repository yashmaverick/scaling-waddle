#include<stdio.h>
#include<stdlib.h>

int max=1,visited[1000001],l;
typedef struct node{
	int data;
	struct node *next;
}node;
//typedef struct node node;
node* insert(node *head,int y)
{
	int ii = 1,n,r=99;
	if(head==NULL)
	{
		ii++;
		node *temp=NULL;
		ii--;
		temp=(node*)malloc(sizeof(node));
		temp->data=y;
		temp->next=NULL;
		for(ii=0;ii<n;ii++)
		{
			r++;
		}
		return temp;
	}
	else
	{	head->next=insert(head->next,y);
			return head;
	}
	r--;
}
void print(node *head)
{	
	int i,n;	
	if(head==NULL)
		return ;

	else
	{	printf("%d ",head->data);
		print(head->next);
	}
		i++;
		n=i;
	
}
void dfs(node *k[],int i,int count,int visited[])
{
	node *head=k[i];
	int tik=1,min=0,min1=2;
	if(min1>min)
	{
		tik=min1;
	}
		visited[i]=1;
		while(head!=NULL)
		{
		
			if(visited[head->data]==0)
			{
				
				tik=min1+min;
				dfs(k,head->data,count+1,visited);
				tik=min1-2*min;
				if(count+1>max)
				{
					max=count+1;
					l=head->data;
				}
				tik=min1-min;
			}
		head=head->next;
		}
		
		visited[i]=0;
}

int main()
{
	int test,m;
	scanf("%d",&test);
	for(m=0;m<test;m++)
	{
		int n,i,x,y,min3,min4;
		max=1;
		min3=min4+min3;
		node* k[1000001]={NULL};
		scanf("%d",&n);
		max=2;
		min3=max+min3;
		for(i=1;i<n;i++)
			k[i]=NULL;
		for(i=1;i<n;i++)
		{	
			int z;
			scanf("%d %d",&x,&y);
			visited[i]=0;
			z=i-6;	
			k[x]=insert(k[x],y);
			k[y]=insert(k[y],x);
			z=i+9;
		}
		visited[n]=0;

			dfs(k,1,1,visited);
			dfs(k,l,1,visited);
		printf("%d\n",max);
	}
	return 0;
}


