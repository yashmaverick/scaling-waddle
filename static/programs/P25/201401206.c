#include<stdio.h>

int heap[3][100009];

int hsize=0;
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void insheap(int w,int x,int y) 
{
	int i;
	if(hsize==0)
	{
		hsize++;
		heap[0][hsize]=w;
		heap[1][hsize]=x;
		heap[2][hsize]=y;
	}
	else
	{
		hsize++;
		heap[0][hsize]=w;
		heap[1][hsize]=x;
		heap[2][hsize]=y;
		int t=hsize;
		while(heap[0][t] < heap[0][t/2] && t!=1)
		{
			heap[0][t]=heap[0][t/2];
			heap[1][t]=heap[1][t/2];
			heap[2][t]=heap[2][t/2];

			heap[0][t/2]=w;
			heap[1][t/2]=x;
			heap[2][t/2]=y;

			t=t/2;
			//      ind[no]=t/2;
			//              for(i=1;i<=hsize;i++)
			//                      printf("%d ",heapno[i]);
			//                      printf("\n");
		}
	}
	//              for(i=1;i<=hsize;i++)
	//                      printf("%d ",heapno[i]);
	//              printf("\n");
}
void delete(int x)
{
	int min,t;
	if(2*x+1<=hsize)
	{
		if(heap[0][2*x] < heap[0][2*x+1])
			min=2*x;
		else
			min=2*x+1;
		if(heap[0][x]>heap[0][min])
		{
			swap(&heap[0][x],&heap[0][min]);
			swap(&heap[1][x],&heap[1][min]);
			swap(&heap[2][x],&heap[2][min]);
			delete(min);
		}
	}
	else if(2*x==hsize)
	{
		if(heap[0][x] > heap[0][2*x])
		{
			swap(&heap[0][x],&heap[0][2*x]);
			swap(&heap[1][x],&heap[1][2*x]);
			swap(&heap[2][x],&heap[2][2*x]);
		}
	}
}
int lw,v1,v2;

void shuffled()
{
	int x=1;
	if(hsize==0)
		return;
	//      if(vis[heapno[1]]==1)
	//              flag=1;
	lw=heap[0][1];
	v1=heap[1][1];
	v2=heap[2][1];
	heap[0][1]=heap[0][hsize];
	heap[1][1]=heap[1][hsize];
	heap[2][1]=heap[2][hsize];
	hsize--;
	delete(x);

	//      if(flag==1)
	//      {
	//              flag=0;
	//              shuffled();
	//      }
}
int par[100009];
int findp(int a)
{
	if(par[a]==a)
		return a;
	par[a]=findp(par[a]);
	return par[a];
}

int main()
{
	int v,e;
	scanf("%d %d",&v,&e);
	int f=e;
	heap[0][0]=-1;
	heap[1][0]=-1;
	heap[2][0]=-1;
	int sum=0,count=0;
	int check=0,flag=0;
	int exist[100005]={0};
	while(f--)
	{
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		insheap(w,x,y);
		if(exist[x]==0)
		{
			exist[x]=1;
			check++;
		}
		if(exist[y]==0)
		{
			exist[y]=1;
			check++;
		}
		par[x]=x;
		par[y]=y;
	}
	
	if(check=!v)
		flag=1;
	while(hsize!=0)
	{
		/*	printf("***\n");
			for(i=1;i<=hsize;i++)
				printf("%d ",heap[0][i]);
			printf("\n");
			for(i=1;i<=hsize;i++)
				printf("%d ",heap[1][i]);
			printf("\n");
			for(i=1;i<=hsize;i++)
				printf("%d ",heap[2][i]);
			printf("\n");
			printf("$$$\n");*/
			shuffled();
			v1=findp(v1);
			v2=findp(v2);
			if(v1!=v2)
			{
				par[v1]=v2;
				sum+=lw;
				count++;
			}
	}
	if(flag==1 || hsize==0 && count!=v-1)
		printf("-1\n");
	else
		printf("%d\n",sum);
	return 0;
}

