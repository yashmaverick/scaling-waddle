#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100000000000000
typedef struct node node;
typedef long long int lli;
struct node
{
	lli vertex;
	lli weight;
	struct node *next;
};
lli size=0;
node heap[1010101];
lli sum,l;
node *master[1010101];
lli visited[1010101],dis[1010101],present[1010101];
void new(lli,lli,lli);
void visitset(lli);
void presentset(lli);
void func(lli,node **);
void insert(node *get)
{
	size++;
	node getit,tmp;
	present[get->vertex] = 1;
	getit = (*get);
	heap[size] = getit;
	lli i = size;
	while(i > 1 && dis[heap[i].vertex] < dis[heap[i>>1].vertex] )
	{
		tmp = heap[i];
		heap[i] = heap[i>>1];
		heap[i>>1] = tmp;
		i = i>>1;
	}
}
node delete()
{
	lli last=size;
	node kk;
	kk=heap[1];
	visited[kk.vertex]=1;
	heap[1]=heap[last];
	size--;
	last=size;
	node tmp;
	lli j,k,l;
	for(j=1;(j<<1)<=last;j=k)
	{
		k=j<<1;
		if(k<last && (dis[heap[k].vertex])>(dis[heap[k+1].vertex]))
			k++;
		if((dis[heap[j].vertex]) > (dis[heap[k].vertex]))
		{
			tmp=heap[j];
			heap[j]=heap[k];
			heap[k]=tmp;
		}
	}
	return kk;
}
void new(lli e,lli x,lli w)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->weight=w;
	tmp->vertex = x;
	tmp->next=NULL;
	if(master[e]!=NULL)
	{
		tmp->next = master[e];
		master[e] = tmp;
		return ;
	}
	else
	{
		master[e] = tmp;
	}
}
void func(lli i,node **master)
{
	node *tmp = master[i];
	while(tmp!=NULL)
	{
		if(visited[tmp->vertex]!=1)
		{

			if(dis[tmp->vertex]>dis[i]+tmp->weight)
			{
				dis[tmp->vertex]=dis[i]+tmp->weight;
			}
			if(present[tmp->vertex]!=1)
			insert(tmp);
		}
		tmp = tmp->next;
	}

}
int main()
{
	lli i,m,l,vrtcs,w,edgs,start,end;
		scanf("%Ld",&vrtcs);
		for(i = 1;i <= vrtcs;i++)
		{
			master[i] = NULL;
			i++;
		}
		scanf("%Ld",&edgs);
		for(i = 1;i < edgs+1;i++)
		{
			scanf("%Ld%Ld%Ld",&m,&l,&w);
			new(m,l,w);
		}
		for(i=1;i<=vrtcs;i++)
		{
			visited[i]=0;
			dis[i]=MAX;
			present[i]=0;
		}
		scanf("%Ld%Ld",&start,&end);
		dis[start]=0;
		node *vpn=(node *)malloc(sizeof(node));
		vpn->vertex=start;
		vpn->weight=0;
		insert(vpn);
		node str;
		lli answer=0;
		while(size && visited[end]==0)
		{
		str=delete();
		func((str.vertex),master);
		}
		if(dis[end]!=100000000000000)
		printf("%Ld",dis[end]);
		else
			printf("NO");
		printf("\n");
	return 0;
}

