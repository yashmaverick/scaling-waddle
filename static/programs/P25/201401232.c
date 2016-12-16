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
lli visited[1010101],dis[1010101],present[1010101],klp[1000101];
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
		klp[heap[i].vertex]=i;
	while(i > 1 && dis[heap[i].vertex] < dis[heap[i>>1].vertex] )
	{
		tmp = heap[i];
		heap[i] = heap[i>>1];
		heap[i>>1] = tmp;
		klp[heap[i].vertex]=i;
		i = i>>1;
		klp[heap[i].vertex]=i;

	}
}
void heapify(int m)
{
	long long int i,j,k,l;
	i=klp[m];
	node tmp;
	while(i > 1 && dis[heap[i].vertex] < dis[heap[i>>1].vertex] )
	{
		tmp = heap[i];
		heap[i] = heap[i>>1];
		heap[i>>1] = tmp;
		klp[heap[i].vertex]=i;
		i = i>>1;
		klp[heap[i].vertex]=i;
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
		klp[heap[j].vertex]=j;
		k=j<<1;
		klp[heap[k].vertex]=k;
		if(k<last && (dis[heap[k].vertex])>(dis[heap[k+1].vertex]))
			k++;
		if((dis[heap[j].vertex]) > (dis[heap[k].vertex]))
		{
			tmp=heap[j];
			heap[j]=heap[k];
			heap[k]=tmp;
		klp[heap[k].vertex]=k;
		klp[heap[j].vertex]=j;
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
			if(present[tmp->vertex] && dis[tmp->vertex]>tmp->weight)
			{
				dis[tmp->vertex]=tmp->weight;
				heapify(tmp->vertex);
			}
			else if(dis[tmp->vertex]>tmp->weight)
			{
				dis[tmp->vertex]=tmp->weight;
			}
			if(present[tmp->vertex]!=1)
			{
			//	printf("inserting%Ld\n",tmp->vertex);
			insert(tmp);
			}
		}
		tmp = tmp->next;
	}

}
int main()
{
	lli i,m,l,vrtcs,w,edgs,start,end,count;
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
			new(l,m,w);
		}
		for(i=1;i<=vrtcs;i++)
		{
			visited[i]=0;
			dis[i]=MAX;
			present[i]=0;
		}
		node *vpn=(node *)malloc(sizeof(node));
		vpn->vertex=1;
		vpn->weight=0;
		dis[1]=0;
		insert(vpn);
		node str;
		long long int mk;
		node *uip;
	/*	for(mk=1;mk<=vrtcs;mk++)
		{
			printf("%Ld->",mk);
			uip=master[mk];
			while(uip!=NULL)
			{
				printf("%d ",uip->vertex);
				uip=uip->next;
			}
			printf("\n");
		}*/
		lli answer=0;
		count=0;
		while(size)
		{
		str=delete();
		count++;
		answer+=dis[str.vertex];
	//	printf("%Ld\n",str.vertex);
	//	for(mk=1;mk<=size;mk++)
	//	{
	//		printf("%Ld %Ld\n",heap[mk].vertex,dis[heap[mk].vertex]);
	//	}
	//	printf("done\n");
	//	printf("%d %d\n",answer,str.vertex);
		if(count==vrtcs)
			break;
		func((str.vertex),master);
		}
		if(count==vrtcs)
		printf("%Ld\n",answer);
		else
		printf("-1\n");
		
	return 0;
}

