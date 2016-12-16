#include<stdio.h>
#include<stdlib.h>
#define N 1000230
typedef struct node
{
	int data;
	struct node *next;
}node;

int maxdepth=0,maxval,j;
int va[N];
node *a[N];
int state;
int root;

void dfs(int val,int depth)
{
	//printf("dfs val = %d\n",val);
			if(depth>=maxdepth)
			{
				//printf("depth = %d\n",depth);
				maxdepth=depth;
				maxval=val;
			}
	if(va[val]==1)return;
	va[val]=1;
	node *temp=a[val];
	while(temp!=NULL)
	{
		
		if(va[temp->data]!=1)
		{
			//printf("YAY\n");
			
		//	printf("%d\n",temp->data);
			dfs(temp->data,depth+1);
		}
		temp=temp->next;
			
	}

	return;
}

void adjInsert(int val1,int val2)
{
	if(a[val1]==NULL||a[val2]==NULL)
	{
		if(a[val1]==NULL && a[val2]==NULL){
			a[val1] = (node*)malloc(sizeof(node));
			a[val1]->data=val2;
			a[val1]->next = NULL;

			a[val2] = (node*)malloc(sizeof(node));
			a[val2]->data=val1;
			a[val2]->next = NULL;
		}
		else if(a[val1]==NULL)
		{
			a[val1]=(node*)malloc(sizeof(node));
			a[val1]->data=val2;
			a[val1]->next=NULL;
			node *t=(node*)malloc(sizeof(node));
			t->data=val1;
			t->next=a[val2];
			a[val2]=t;
		}
		else if(a[val2]==NULL)
		{
			a[val2]=(node*)malloc(sizeof(node));
			a[val2]->data=val1;
			a[val2]->next=NULL;
			node *t=(node*)malloc(sizeof(node));
			t->data=val2;
			t->next=a[val1];
			a[val1]=t;
		}
	}
	
	else
	{
		node *temp1=(node*)malloc(sizeof(node));
		node *temp2=(node*)malloc(sizeof(node));
		temp1->data=val2;
		temp1->next=NULL;
		temp2->data=val1;
		temp2->next=NULL;
		temp1->next=a[val1];
		a[val1]=temp1;
		temp2->next=a[val2];
		a[val2]=temp2;
	}		

	return;
}

int main()
{
	int i,x,n,val1,val2,T,t;
	scanf("%d",&T);
	//scanf("%d",&t);
	for(i=0;i<T;i++)
	{
		maxdepth=0;
		int k;
		for(k=0;k<N;k++)
		{
			va[k]=0;
		}
		for(k=0;k<N;k++)
		{
			//if(a[k]!=NULL)free(a[k]);
			a[k] = NULL;
		}
		maxval=0;
		scanf("%d",&t);
		maxdepth=0;
		
		for(j=1;j<=t-1;j++)
		{
			scanf("%d %d",&val1,&val2);
			adjInsert(val1,val2);
			//adjInsert(val2, val1);
		}
		/*for(x=0;x<t;x++)
		{
			node *temp=a[x+1];
			printf("%d",x+1);
			while(temp!=NULL)
			{
				printf("->%d",temp->data);
				temp=temp->next;
			}
			printf("\n");
		}*/

		//va[1]=1;
		//printf("%d \n",1);
		dfs(1,1);
		//printf("\n");
		maxdepth=0;
		for(k=0;k<N;k++)
		{
			va[k]=0;
		}
		
		//va[maxval]=1;
		dfs(maxval,1);
	//	printf("maxval= %d \n",maxval);
	//	printf("%d\n",maxval);

	//	printf("\n");
		printf("%d\n",maxdepth);
	}
	return 0;
}
