#include<stdio.h>
#include<stdlib.h>
#define N 1000023
typedef struct node
{
	long long int data;
	struct node *next;
}node;

node *a1[N];
node *a2[N];
long long int va[N];
long long int count1=0,count2=0;
void dfs1(long long int val)
{
	va[val]=1;
	count1++;
	node *temp=a1[val];
	while(temp!=NULL)
	{
		if(va[temp->data]!=1)
		{
			dfs1(temp->data);

		}
		temp=temp->next;
	}
	return;
}
void dfs2(long long int val)
{
	va[val]=1;
	count2++;
	node *temp=a2[val];
	while(temp!=NULL)
	{
		if(va[temp->data]!=1)
		{
			dfs2(temp->data);

		}
		temp=temp->next;
	}
}

void adjInsert1(long long int val1,long long int val2)
{
	if(a1[val1]==NULL)
	{
		a1[val1]=(node*)malloc(sizeof(node));
		a1[val1]->data=val2;
		a1[val1]->next=NULL;
	}

	else
	{
		node *temp1=(node*)malloc(sizeof(node));
		temp1->data=val2;
		temp1->next=a1[val1];
		a1[val1]=temp1;
	}		
}
void adjInsert2(long long int val1,long long int val2)
{
	if(a2[val1]==NULL)
	{
		a2[val1]=(node*)malloc(sizeof(node));
		a2[val1]->data=val2;
		a2[val1]->next=NULL;
	}


	else
	{
		node *temp1=(node*)malloc(sizeof(node));
		temp1->data=val2;
		temp1->next=a2[val1];
		a2[val1]=temp1;
	}		
}

int main ()
{
	long long int i,j,k,T,t,n,x,state;
	scanf("%lld",&T);
	long long int f;
	for(i=0;i<T;i++)
	{

		scanf("%lld",&t);
		int state=0;
		for(j=1;j<=t;j++)
		{
			scanf("%lld",&n);
			for(k=0;k<n;k++)
			{
				long long int val;
				scanf("%lld",&val);
				adjInsert1(val,j);
				adjInsert2(j,val);
			}
		}
		
		for(x=1;x<=t;x++)
		{
			dfs1(x);
			long long int z;
			for(z=0;z<=t;z++)
				va[z]=0;
			if(count1==t)
			{
				state=1;
				break;
			}
			else 
				count1=0;

		}
		if(state!=1)
		{
			printf("%d\n",0);
			count1=0;
			count2=0;
			long long int q;
			for(q=0;q<t+1;q++)
			{
				a1[q]=NULL;
				a2[q]=NULL;
			}
			continue;
		}
		dfs2(x);
		printf("%lld\n",count2);
		count2=0;
		count1=0;
		long long int q;
		for(q=0;q<t+1;q++)
		{
			a1[q]=NULL;
			a2[q]=NULL;
		}
		int z;

		for(z=0;z<=t;z++)
			va[z]=0;
	}
	return 0;
}
	

