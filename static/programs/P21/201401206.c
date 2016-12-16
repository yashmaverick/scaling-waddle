#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int no;
	int w;
	struct tree *next;
};
typedef struct tree tree;

int vis[100005]={0};
tree* insert(tree *new,int val,int w)
{
	if(new==NULL)
	{
		new=(tree*)malloc(sizeof(tree));
		new->no=val;
		new->next=NULL;
		new->w=w;
	}
	else
		new->next=insert(new->next,val,w);
	return new;
}
int dist[100009];
int heapw[100009],heapno[1000009],hsize=0;
int ind[100009];
int pre[100009]={0};
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void insheap(int w,int no)
{
	int i;
	if(hsize==0)
	{
		hsize++;
		heapw[hsize]=w;
		heapno[hsize]=no;
		ind[no]=hsize;
	}
	else
	{
		hsize++;
		heapw[hsize]=w;
		heapno[hsize]=no;
		ind[no]=hsize;
		int t=hsize;
		while(heapw[t] < heapw[t/2] && t!=1)
		{
			heapw[t]=heapw[t/2];
			heapw[t/2]=w;

			heapno[t]=heapno[t/2];
			heapno[t/2]=no;
			ind[no]=t/2;
			t=t/2;
		//	ind[no]=t/2;
//		for(i=1;i<=hsize;i++)
//			printf("%d ",heapno[i]);
//			printf("\n");
		}
	}
//		for(i=1;i<=hsize;i++)
//			printf("%d ",heapno[i]);
//		printf("\n");
}
void delete(int x)
{
	int min,t;
	if(2*x+1<=hsize)
	{
		if(heapw[2*x] < heapw[2*x+1])
			min=2*x;
		else
			min=2*x+1;
		if(heapw[x]>heapw[min])
		{
			swap(&heapw[x],&heapw[min]);
			swap(&heapno[x],&heapno[min]);
			swap(&ind[heapno[min]],&ind[heapno[x]]);
			delete(min);
		}
	}
	else if(2*x==hsize)
	{
		if(heapw[x] > heapw[2*x])
		{
			swap(&heapw[x],&heapw[2*x]);
			swap(&heapno[x],&heapno[2*x]);
			swap(&ind[heapno[2*x]],&ind[heapno[x]]);
		}
	}
}
int flag=0;
int shuffled()
{
	int x=1;
	if(hsize==0)
		return;
//	if(vis[heapno[1]]==1)
//		flag=1;
	pre[heapno[1]]=0;
	int t=heapno[1];
	heapw[1]=heapw[hsize];
	heapno[1]=heapno[hsize];
	hsize--;
	delete(x);
	return t;

//	if(flag==1)
//	{
//		flag=0;
//		shuffled();
//	}
}

int main()
{
	int v,e;
	scanf("%d %d",&v,&e);
	tree *node[100009]={NULL};
	heapno[0]=-1;
	heapw[0]=-1;
	while(e--)
	{
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		node[x]=insert(node[x],y,w);
	}
	int start,end,i;
	hsize=0;
	scanf("%d %d",&start,&end);
	for(i=1;i<=v;i++)
		dist[i]=1000000006;
	dist[start]=0;
	insheap(0,start);
	vis[start]=0;
	int n=start;
	int count=0,pop;
	pre[start]=1;
//	for(i=1;i<=5;i++)
//		printf("%d ",heapno[i]);
//	printf("\n");
	while(hsize!=0)
	{
		pop=shuffled();
		vis[pop]=1;
		count++;
//		printf("$%d$\n",pop);
		tree *temp=node[pop];
		while(temp!=NULL)
		{
//		printf("%d\n",temp->no);
			if(dist[temp->no] > dist[pop] + temp->w)
			{
	//			printf("IN HERE\n");
				dist[temp->no]=dist[pop]+temp->w;
				if(pre[temp->no]==0)
				{
			//		printf("IN HERE 2\n");
					insheap(dist[temp->no],temp->no);
					pre[temp->no]=1;
			/*		for(i=1;i<=hsize;i++)
						printf("%d ",heapno[i]);
					printf("\n");
					for(i=1;i<=hsize;i++)
						printf("%d ",heapw[i]);
					printf("\n");*/
				}
				else
				{
					if(heapw[ind[temp->no]]>dist[temp->no]);
						heapw[ind[temp->no]]=dist[temp->no];
				}
			}
			temp=temp->next;
		}
	/*	printf("***\n");
		for(i=1;i<=hsize;i++)
			printf("%d ",heapno[i]);
		printf("\n");
		for(i=1;i<=hsize;i++)
			printf("%d ",heapw[i]);
		printf("\n");
		printf("$$$\n");*/
		if(count==v)
		{
		//	printf("BROKE HERExxxx\n");
		//	printf("^^^%d^^^\n",vis[end]);
		//	for(i=1;i<=hsize;i++)
		//		printf("%d ",heapno[i]);
		//	printf("\n");
			break;
		}
	}
	if(vis[end]==0)
		printf("NO\n");
	else
		printf("%d\n",dist[end]);
	return 0;
}
