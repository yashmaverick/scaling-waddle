#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INFINITY 100000000000007
typedef struct linkedlist
{
	long long int vert;
	long long int cost;
	struct linkedlist *next;
}node;
typedef struct heap
{
	long long int vertex;
	long long int dist;
}heap;
heap *heaparr[100005];
int point;
heap *insertheap(int k,int l)
{
	point++;
	heaparr[point]=malloc(sizeof(heap));
	heaparr[point]->vertex=k;
	heaparr[point]->dist=l;
	int index=point;
	while(index>1)
	{
		if(heaparr[index]->dist<heaparr[index/2]->dist)
		{
			long long int temp=heaparr[index]->dist;
			heaparr[index]->dist=heaparr[index/2]->dist;
			heaparr[index/2]->dist=temp;
			temp=heaparr[index]->vertex;
			heaparr[index]->vertex=heaparr[index/2]->vertex;
			heaparr[index/2]->vertex=temp;
		}
		index=index/2;
	}
}
void delete()
{

	heaparr[1]->vertex=heaparr[point]->vertex;
	heaparr[1]->dist=heaparr[point]->dist;
	free(heaparr[point]);
	point--;
	int index=1;
	if(index>point)
		return;
	while(1)
	{

		int maxindex=2*index;
		if(maxindex>point)
			break;
		else if(maxindex+1<=point && heaparr[maxindex]->dist>heaparr[maxindex+1]->dist)
		{
			maxindex++;
		}
		if(heaparr[index]->dist>heaparr[maxindex]->dist)
		{
			long long int temp=heaparr[index]->dist;
			heaparr[index]->dist=heaparr[maxindex]->dist;
			heaparr[maxindex]->dist=temp;
			temp=heaparr[index]->vertex;
			heaparr[index]->vertex=heaparr[maxindex]->vertex;
			heaparr[maxindex]->vertex=temp;
		}
		index=maxindex;
		if(index>point)
			break;
	}
}
long long int numofcities,numofedges;
unsigned long long int d[100005];
node *insert(node *head,int a,int b)
{
	node *q,*p;
	q=(node *)malloc(sizeof(node));
	q->vert=a;
	q->cost=b;
	if(head==NULL)
	{
		head=q;
	}
	else
	{
		q->next=head;
		head=q;
	}
	return head;
}
void printheap()
{
	int i=1;
	heap *q; 
	while(i<=point)
	{
		printf("%lld->",heaparr[i]->vertex);
		i++;
	}
	i=1;
	printf("\n");
	while(i<=point)
	{
		printf("%lld->",heaparr[i]->dist);
		i++;
	}
	printf("\n");
}

void print(node *head)
{
	node *q;
	q=(node *)malloc(sizeof(node));
	q=head;
	while (q!=NULL)
	{
		printf("%lld->",q->vert);
		q=q->next;
	}
	printf("\n");
	q=head;
	while(q!=NULL)
	{
		printf("%lld->", q->cost);
		q=q->next;
	}
	printf("\n");
}
void dijstra(node *q,node *head[],long long int second)
{
	long long int i,k,min,visited[100005],count=0;
	for(i=1;i<=numofcities;i++)
	{
		visited[i]=0;
		d[i]=INFINITY;
	}
	d[q->vert]=0;
	//	printf("%d", q->vert);

	insertheap(q->vert,0);
	while(point>=1 && visited[second]!=1)
	{
/*		if (visited[heaparr[1]->vertex]==1)
		{
			delete();
		}*/
		min=heaparr[1]->vertex;
		delete();
		count++;
		visited[min]=1;
		if(min==second || count==numofcities)
		{
			break;
		}
		node *p; 
		p=head[min];
		while(p!=NULL)
		{
		//	printf("%lld\n",p->vert);
			if(visited[p->vert]!=1)
			{

			//insertheap(p->vert,d[p->vert]);
				if(d[min]+p->cost<d[p->vert])
				{
					d[p->vert]=d[min]+p->cost;
					insertheap(p->vert,d[p->vert]);
	
				}
			}
			p=p->next;
		}
//		printf("%d\n", point);
	//	printheap();
	}
}

int main()
{
	long long int n1,n2,first,second,numofqueries,numofneighbours,test,t,c,in,hash,neighbour,cost,i,len,hash1,hash2;
	node *head[100003];
//	scanf("%lld", &test);
//	for(t=0;t<test;t++)
//	{
	point=0;
	scanf("%lld %lld", &numofcities,&numofedges);
	for(i=0;i<=numofcities;i++)
	{
		head[i]=NULL;
	}
	for(c=1;c<=numofedges;c++)
	{
		scanf("%lld %lld %lld", &n1,&n2,&cost);
		head[n1]=insert(head[n1],n2,cost);
	//	head[n2]=insert(head[n2],n1,cost);
	}
	for(c=1;c<=numofcities;c++)
	{
		head[c]=insert(head[c],c,0);
	}
	
	scanf("%lld %lld", &first,&second);
	if(numofedges!=0)
	{
		dijstra(head[first],head,second);
		if(d[second]!=INFINITY)
		{
			printf("%llu\n", d[second]);
		}
		else
		{
			printf("NO\n");
		}
	}
	else if(numofedges==0 && first==second) 
	{
		printf("0\n");
	}
	else
	{
		printf("NO\n");
	}
//	}
	return 0;
}
