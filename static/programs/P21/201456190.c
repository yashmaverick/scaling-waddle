#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 1000001
int flag=0;
int ans=INT_MAX;
int ind=0;
int vis[MAX];
int dist[MAX];
int a[MAX];
int b[MAX];
//int IN[MAX];
struct linked{
	int d;
	int dis;
	struct linked * next;
};

typedef struct linked ELEMENT;
ELEMENT * node[MAX];


void graph(int u,int v,int disti)
{
	ELEMENT *head;
	head=(ELEMENT *)(malloc(sizeof(ELEMENT)));
	head->d=v;
	head->dis=disti;
	head->next=node[u];
	node[u]=head;
	return;
}
void heapinsert(int d,int dis)
{
	ind++;
	if(ind==1)
	{
		a[1]=d;
		b[1]=dis;
	}
	else
	{
		a[ind]=d;
		b[ind]=dis;
		int j=ind;
		while(1)
		{
			int k;
			k=j;
			j=j/2;
			if(b[k]<b[j] && j>0)
			{
				int temp;
				temp=a[k];
				a[k]=a[j];
				a[j]=temp;
				int tem;
				tem=b[k];
				b[k]=b[j];
				b[j]=tem;
			}
			else
			{
				a[k]=d;
				b[k]=dis;
				break;
			}
		}
	}
/*	int q;
	for(q=1;q<=ind;q++)
		printf("a[%d]=%d",q,a[q]);
	printf("\n");
	for(q=1;q<=ind;q++)
		printf("b[%d]=%d",q,b[q]);
	printf("\n"); */
	return;
}

int heapdelete()
{
	if(ind==0)
		return -1;

        int y=a[1];
	int t=a[ind];
	a[ind]=INT_MAX;
	a[1]=t;
        int yy=b[1];
	int tt=b[ind];
	b[ind]=INT_MAX;
	b[1]=tt;
        int k=1;;
        int j=1;
	int g=1;
	while(1)
	{

		j=2*k;
		g=(2*k)+1;

		if(b[j]<b[k] && b[j]<=b[g])
		{

			int temp;
			temp=a[k];
			a[k]=a[j];
			a[j]=temp;
			temp=b[k];
			b[k]=b[j];
			b[j]=temp;
			k=j;

		}
		else if(b[g]<b[k] && b[g]<=b[j])
		{

			int tempo;
			tempo=a[k];
			a[k]=a[g];
			a[g]=tempo;
			tempo=b[k];
			b[k]=b[g];
			b[g]=tempo;
			k=g;
		}
		else{
			ind=ind-1;
			break;
		}
	}

/*	int q;
	for(q=1;q<=ind;q++)
		printf("delete heap a[%d]=%d ",q,a[q]);
	printf("\n");
	for(q=1;q<=ind;q++)
		printf("delete heap b[%d]=%d ",q,b[q]);
	printf("\n");
	printf("y=%d\n",y); */
	return y;
}



void djikstra(int source, int desti)
{ 

	ELEMENT* tail;
	tail=node[source];
	while(tail!=NULL)
	{
 
	   
		if(vis[tail->d]!=1)
		{
			int y;
			int z;
			int x;
			z=tail->d;
			x=tail->dis;
			y=dist[source]+x;
               
			if(y<dist[z])
			{
				dist[z]=y;
				heapinsert(z,y);
			}
			//			printf("to insert node in heap=%d\n",z);

		}
		tail=tail->next;
	}


	int dijk;

	do{
		dijk=heapdelete();
		if(dijk==-1)
			break;
	}while(vis[dijk]==1);


	if(dijk==-1)
	{
		return;
	}

	else 

	{
		//		printf("min=%d\n",dijk);
		if(dijk==desti)
		{       
			ans=dist[desti];
			flag=1;
			return;
		}
	
		vis[dijk]=1;
		djikstra(dijk,desti);
		return;
	}

}






int main()
{
	//	int test;
	//	scanf("%d",&test);
	//	while(test--)
	//   {
	ans=INT_MAX;
	flag=0;
	ind=0;
	int ver;
	int edges;
	int u,v;
	int disti;
	int source,destination;
	scanf("%d %d",&ver,&edges);
	int i;
	for(i=0;i<=MAX;i++)
	{
		node[i]=NULL;
	}


	for(i=0;i<edges;i++)
	{ 
		scanf("%d %d %d",&u,&v,&disti);
		graph(u,v,disti);
	//	graph(v,u,disti);
		//graph(v,u,disti);

	}
	scanf("%d %d",&source,&destination);

	if(edges>0)
	{
		for(i=0;i<=MAX;i++)
		{
			dist[i]=INT_MAX;
			b[i]=INT_MAX;
			a[i]=INT_MAX;
			vis[i]=0;
		}
		dist[source]=0;
		vis[source]=1;
		djikstra(source,destination);
		if(flag==1)
			printf("%d\n",ans);
		else if(ans==INT_MAX)
			printf("NO\n");
	}
	else 
		printf("NO\n");

	//  }
	return 0;
}
