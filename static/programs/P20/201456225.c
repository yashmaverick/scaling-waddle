#include<stdio.h>
#include<stdlib.h>
typedef long long int lld;
struct node
{
	lld value;
	struct node *next;
};
lld small(lld x,lld y);
struct node *list[1000001],*new1;
lld *done,count=0,*dia,*new2,*max;
lld point,edges,u,v,i;
void link(struct node *list[],lld u,lld v);
void DFS(lld v);
int  main()
{
	
	lld testcases;
	scanf("%lld", &testcases);
	while(testcases--)
	{
		scanf("%lld",&point);
		dia=(lld *)malloc(sizeof(lld)*point);		
		done=(lld *)malloc(sizeof(lld)*point);
		max=(lld *)malloc(sizeof(lld)*point);
		new2=(lld *)malloc(sizeof(lld)*point);
		edges=point-1;
		lld max_edges=(point*(point-1))/2;
		i=0;
		while(i<point)
		{
			list[i]=(struct node *)malloc(sizeof(struct node));
			list[i]->value=i;list[i]->next=NULL;
			done[i]=0;new2[i]=0;max[i]=0;dia[i]=0;
			i++;
		}
		i=0;
		while(i<edges)
		{
			scanf("%lld%lld",&u,&v);
			u--;v--;link(list,u,v);link(list,v,u);
			i++;	
		}
		i=0;
		while(i<point)			
		{
			if(done[i]==0)
			{
				count++;
				DFS(i);
			}
			i++;
		}
		printf("%lld\n",dia[0]+1);
	}
	return 0;
}
void DFS(lld v)
{
	struct node *new1;
	done[v]=1;
	new1=list[v]->next;
	while(new1!=NULL)
	{
		if(done[new1->value]==0)
		{

			DFS(new1->value);
			if(dia[new1->value]>dia[v])
				dia[v]=dia[new1->value];
			if(new2[v]<(max[new1->value]+1))
				new2[v]=max[new1->value]+1;
			if(new2[v]>max[v])
			{
				lld temp;
				temp=new2[v];
				new2[v]=max[v];
				max[v]=temp;
			}
		}
		new1=new1->next;
	}
	if((new2[v]+max[v])>dia[v])
		dia[v]=new2[v]+max[v];
}
lld small(lld x,lld y)
{
	if(x>y)
		return y;
	else
		return x;
}
lld big(lld x, lld y)
{
	if(x>y)
		return x;
	else
		return y;
}
void link(struct node *list[],lld u,lld v)
{
	struct node *new1,*new;
	new1 = list[u];
	while(new1->next!=NULL)
		new1=new1->next;
	new=(struct node *)malloc(sizeof(struct node));
	new->value=v;
	new->next=NULL;
	new1->next=new;
}

