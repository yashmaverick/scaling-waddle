#include <stdio.h>
#include <stdlib.h>
#define MAX 1000010

typedef struct node {
	int x;
	struct node* next;
} node;

node* arr[MAX];
int arv[MAX];
int h,one;

void dfs(int i,int d)
{
	if(arv[i]==0)
	{
		arv[i]=1;
		if(d>h)
		{
			h=d;
			one=i;
		}
		//printf("%d ",i);
		node* temp=arr[i];
		while(temp!=NULL)
		{
			dfs(temp->x,d+1);
			temp=temp->next;
		}
	}
	else
		return;
}

int main()
{
	int i,j,k,l,n,test,a,b,c,m;
	scanf("%d",&test);
	for(m=0;m<test;m++)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
		  arr[i]=NULL;
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&j,&k);
			//for(l=0;l<k;l++)
			//{
			node* temp=(node*)malloc(sizeof(node));
			node* rtemp=(node*)malloc(sizeof(node));
			temp->x=k;
			temp->next=arr[j];
			arr[j]=temp;
			rtemp->x=j;
			rtemp->next=arr[k];
			arr[k]=rtemp;
			//}
		}
		for(i=0;i<n+1;i++)
			arv[i]=0;
		h=0;
		dfs(1,1); 
		for(i=0;i<n+1;i++)
			arv[i]=0;
		h=0;
		dfs(one,1);
		printf("%d\n",h);
	}
	return 0;
}
