#include <stdio.h>
#include <stdlib.h>
#define infinite 1000000009
typedef struct al{
	int vx;
	int wt;
	struct al *next;
}al;
typedef struct h{
	int nv;
	int nw;
}h;
int ins2;
h heap[500005];
int hash[500005];
void delete();
void insert(int vertex,int weight);
void update(int vertex,int weight);
int main()
{
	int t;
	int v,k;
	int a,b,c;
	int A,B;
	al *arr[500005];

	ins2=1;
	scanf("%d%d",&v,&k);
	int i;
	for(i=1;i<=k;i++)
	{
		arr[i]=NULL;
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		al *temp=(al*)malloc(sizeof(al));
		//	al *temp2=(al*)malloc(sizeof(al));
		//temp2->vx=a;
		//temp2->wt=c;
		temp->vx=b;
		//temp2->next=NULL;			
		temp->wt=c;
		temp->next=NULL;
		if(arr[a]==NULL)
		{
			arr[a]=(al*)malloc(sizeof(al));
			arr[a]=temp;
		}
		else
		{
			temp->next=arr[a];
			arr[a]=temp;
		}
		/*if(arr[b]=NULL)
		  {
		  arr[b]=(al*)malloc(sizeof(al));
		  arr[b]=temp2;
		  }
		  else
		  {
		  temp2->next=arr[b];
		  arr[b]=temp2;
		  }*/
	}
	//inputing
	/*al *te;
	  for(i=1;i<=v;i++)
	  {
	  te=arr[i];
	  printf("%d : ",i); 
	  while(te!=NULL)
	  {
	  printf("%d ",te->vx);
	  te=te->next;
	  }
	  printf("\n");
	  }*/
	scanf("%d%d",&A,&B);
	int visited[500005]={0};
	int dist[500005]={0};

	for(i=1;i<=v;i++)
	{
		if(i==A)
		{
			dist[i]=0;
		}
		else
		{
			dist[i]=infinite;
		}
	}

	//making hash the 1st time

	insert(A,0);
	for(i=1;i<=v;i++)
	{ 
		if(i!=A)
			insert(i,infinite);
	}
	/*for(i=1;i<=v;i++)
	{
		printf("%d %d %d\n",heap[i].nv,heap[i].nw,hash[heap[i].nv]);
	}*/


	al *te;
	visited[A]=1;
	int present=A;
	int j=1;
	int min;
	while(1)
	{
		/*   for(i=1;i<=v;i++)
			 if(visited[i]!=1)
			 break;
			 if(i==v+1)
			 break;*/
		if(j>v)
			break;
		//printf("dijkstra's loop\n");
		te=arr[present];
	/*	printf("before update\n");
		for(i=1;i<=v;i++)
		{
			printf("%d %d %d\n",heap[i].nv,heap[i].nw,hash[heap[i].nv]);
		}*/
		while(te!=NULL)
		{
			if(dist[te->vx]>(te->wt+dist[present]))
			{
				dist[te->vx]=te->wt+dist[present];
			//	printf("in loop %d\n",dist[te->vx]);
				update(te->vx,dist[te->vx]);
			}

			te=te->next;
		}
		/*printf("after update\n");

		for(i=1;i<=v;i++)
		{
			printf("%d %d %d\n",heap[i].nv,heap[i].nw,hash[heap[i].nv]);
		}*/
		//finding minimum
		/*min=infinite;
		  for(i=1;i<=v;i++)
		  {
		  if(visited[i]!=1 && dist[i]<min)
		  {

		  min=dist[i];
		  present=i;


		  }
		  }
		printf("printing distances\n");
		for(i=1;i<=v;i++)
			printf("%d ",dist[i]);
		printf("\n");*/
	    present=heap[1].nv;
		delete();

		if(visited[present]!=1)
		{
			visited[present]=1;

		}
		j++;

	}

	if(dist[B]!=infinite)
		printf("%d\n",dist[B]);
	else
		printf("NO\n");



	return 0;
}
void insert(int vertex,int weight)
{
	heap[ins2].nv=vertex;
	heap[ins2].nw=weight;
	hash[vertex]=ins2;
	ins2++;
	int x=ins2-1;
	while(heap[x/2].nw>heap[x].nw && x>1)
	{
		//swapping weights
		int temp=heap[x].nw;
		heap[x].nw=heap[x/2].nw;
		heap[x/2].nw=temp;

		temp=hash[heap[x/2].nv];
		hash[heap[x/2].nv]=hash[heap[x].nv];
		hash[heap[x].nv]=temp;

		//swapping vertex numbers
		temp=heap[x].nv;
		heap[x].nv=heap[x/2].nv;
		heap[x/2].nv=temp;
		x=x/2;
	}

}
void delete()
{
	heap[1].nw=heap[--ins2].nw;
	heap[1].nv=heap[ins2].nv;
	heap[ins2].nw=infinite;
	int x=1;
	while((heap[x].nw>heap[2*x].nw && heap[2*x].nw!=0) || (heap[x].nw>heap[2*x+1].nw && heap[2*x+1].nw!=0) && 2*x<=(ins2-1))
	{
		if(heap[2*x+1].nw<heap[2*x].nw && heap[2*x+1].nw!=0)
		{
			h temp=heap[x];
			heap[x]=heap[2*x+1];
			heap[2*x+1]=temp;
			//swapping hash values
			int ex=hash[heap[x].nv];
			hash[heap[x].nv]=hash[heap[2*x+1].nv];
			hash[heap[2*x+1].nv]=ex;
			x=2*x+1;
		}
		else
		{
			h temp=heap[x];
			heap[x]=heap[2*x];
			heap[2*x]=temp;
			//swapping hash values
			int ex=hash[heap[x].nv];
			hash[heap[x].nv]=hash[heap[2*x].nv];
			hash[heap[2*x].nv]=ex;
			x=2*x;
		}
	}
}
void update(int vertex,int weight)
{
	heap[hash[vertex]].nv=vertex;
	heap[hash[vertex]].nw=weight;
	int x=hash[vertex];
	while(heap[x/2].nw>heap[x].nw && x>1)
	{
		//swapping weights
		int temp=heap[x].nw;
		heap[x].nw=heap[x/2].nw;
		heap[x/2].nw=temp;

		temp=hash[heap[x/2].nv];
		hash[heap[x/2].nv]=hash[heap[x].nv];
		hash[heap[x].nv]=temp;

		//swapping vertex numbers
		temp=heap[x].nv;
		heap[x].nv=heap[x/2].nv;
		heap[x/2].nv=temp;
		x=x/2;
	}
	while((heap[x].nw>heap[2*x].nw && heap[2*x].nw!=0) || (heap[x].nw>heap[2*x+1].nw && heap[2*x+1].nw!=0) && 2*x<=(ins2-1))
	{
		if(heap[2*x+1].nw<heap[2*x].nw && heap[2*x+1].nw!=0)
		{
			h temp=heap[x];
			heap[x]=heap[2*x+1];
			heap[2*x+1]=temp;
			//swapping hash values
			int ex=hash[heap[x].nv];
			hash[heap[x].nv]=hash[heap[2*x+1].nv];
			hash[heap[2*x+1].nv]=ex;
			x=2*x+1;
		}
		else
		{
			h temp=heap[x];
			heap[x]=heap[2*x];
			heap[2*x]=temp;
			//swapping hash values
			int ex=hash[heap[x].nv];
			hash[heap[x].nv]=hash[heap[2*x].nv];
			hash[heap[2*x].nv]=ex;
			x=2*x;
		}
	}
}
