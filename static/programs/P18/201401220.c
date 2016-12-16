#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int d;
	struct node* next;
}node;
node *head[1000001];
node *rev[1000001];
int nn,count=0,f=0,flg=1;
int vis[1000001],rvis[1000001];
void insert(int i,int j,node** h)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->d=j;
	temp->next=NULL;
	if(h[i]==NULL)
	{
		h[i]=temp;
		return;
	}
	else
	{
		temp->next=h[i];
		h[i]=temp;
		return;
	}
}
/*int stack[1000];
int top=0;
void push(int i)
{	

	stack[top]=i;
	//printf("pushed:%d\n",stack[top]);
	top++;	
}
int pop(int *visi)
{
	top--;
	int popped=stack[top];
	//	printf("popped:%d\n",popped);
	visi[stack[top]]=1;
	return popped;
}*/
/*void dfs(int i,int n,int *visi)
  {
  visi[i]=1;
  printf("%d ",i);
  node* temp=head[i];
  while(temp!=NULL)
  {
  if(vis[temp->d]!=1)
  push(temp->d);
  temp=temp->next;
  }
  }*/
void dfs(int i,int visi[],node **h)
{
	node* temp;
	temp=h[i];
	visi[i]=1;
	/*if(count==nn)
	{
		f=1;
	}*/
	while(temp!=NULL)
	{
		i=temp->d;
		if(!visi[i])
		{
			//count++;
			dfs(i,visi,h);
			/*if(count==nn-1)
				flg=0;*/
		}
		temp=temp->next;
	}
}

/*void dfs1(int ff,int dd)
{
	push(ff);
	int i;
	vis[ff]=1;
	if(ff==dd)
		return;
	node* temp=head[ff];
	while(temp!=NULL)
	{
		if(vis[temp->d]!=1)
			return dfs1(temp->d,dd);
		temp=temp->next;
	}
	i=pop(vis);
}*/
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		int m,ij;
		//flg=1;
		scanf("%d",&nn);
		for(i=1;i<=nn;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&ij);
				insert(i,ij,rev);
				insert(ij,i,head);
			}	
		}
		/*for(i=1;i<=nn;i++)
		{
			node *temp=head[i];
			printf("HEAD:%d : ",i);
			while(temp!=NULL)
			{
				printf("%d ",temp->d);
				temp=temp->next;
			}
			printf("\n");
		}
		for(i=1;i<=nn;i++)
		{
			node *temp=rev[i];
			printf("REV:%d : ",i);
			while(temp!=NULL)
			{
				printf("%d ",temp->d);
				temp=temp->next;
			}
			printf("\n");
		}*/

		/*int tt,in1,in2;
		  scanf("%d",&tt);
		  while(tt--)
		  {
		  for(i=1;i<=nn;i++)
		  vis[i]=0;
		  scanf("%d",&in1,&in2);
		  dfs1(in1,in2);
		  while(top>=0)
		  {
		  printf("%d->",stack[top]);
		  top--;
		  }
		  }*/
		int k,j=0;
		for(i=1;i<=nn;i++)
		{
		//	printf("i  %d\n",i);
		//	count=0;
			dfs(i,vis,head);
			for(k=1;k<=nn;k++)
			{
				if(vis[k]==0)
				{
					break;
				}
			}
			//printf("\n");
			if(k==nn+1)
			{
				j=i;
				break;
			}
			/*if(flg==0)
			{
				j=i;
				break;
			}*/
			for(k=1;k<=nn;k++)
				vis[k]=0;
		}
		k=i;
		count=0;
		dfs(j,rvis,rev);
		for(i=1;i<=nn;i++)
		{
			if(rvis[i]==1)
				count++;
		}
		if(k==nn+1)
		{
			printf("0\n");
		}
		else
			printf("%d\n",count);
		count=0;
		for(i=0;i<=nn;i++)
		{
			head[i]=NULL;
			rev[i]=NULL;
			vis[i]=0;
			rvis[i]=0;
		}
	}
	return 0;
}
