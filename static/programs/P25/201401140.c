#include<stdio.h>
#include<stdlib.h>
typedef int lli;
typedef struct heap{
	lli node;
	lli weit;
}heap;
typedef struct stor{
	lli nod;
	lli wei;
	struct stor* next;
}stor;
stor *s[1000010];
heap *mina[1000010];
lli start=1,end=1;
void insert_heap_min(lli p)
{
	if(p==1)
		return ;
	if(mina[p/2]->weit>mina[p]->weit)
	{
		heap* temp;
		temp=mina[p];
		mina[p]=mina[p/2];
		mina[p/2]=temp;
		insert_heap_min(p/2);
	}
}
void delete_heap_min(lli e)
{
	if(2*e+1<start)
	{
		if(mina[2*e]->weit<mina[2*e+1]->weit)
		{
			if(mina[e]->weit>mina[2*e]->weit)
			{
				heap* temp;
				temp=mina[e];
				mina[e]=mina[2*e];
				mina[2*e]=temp;
				delete_heap_min(2*e);
			}
		}
		else
		{
			if(mina[e]->weit>mina[2*e+1]->weit)
			{
				heap* temp;
				temp=mina[e];
				mina[e]=mina[2*e+1];
				mina[2*e+1]=temp;
				delete_heap_min(2*e+1);
			}
		}
	}
	else if(2*e+1==start)
	{
		if(mina[e]->weit>mina[2*e]->weit)
		{
			heap* temp;
			temp=mina[e];
			mina[e]=mina[2*e];
			mina[2*e]=temp;
			delete_heap_min(2*e);
		}
	}
}
void insert_min(lli k,lli w)
{
	mina[start]=(heap*)malloc(sizeof(heap));
	mina[start]->node=k;
	mina[start]->weit=w;
	start++;
	insert_heap_min(start-1);
}
void delete_min()
{
	mina[end]=mina[start-1];
	start--;
	delete_heap_min(end);
}
stor* insert(lli x,lli y,lli w)
{
	stor *temp;
	temp=(stor*)malloc(sizeof(stor));
	temp->nod=y;
	temp->wei=w;
	temp->next=s[x];
	s[x]=temp;
	return s[x];
}
lli ans=0,count=0,vis[1000010];
void func(lli n,lli x)
{
	if(vis[n]==0)
	{
		//printf("%d\n",n);
		vis[n]=1;
		stor* temp;
		temp=s[n];
		//	printf("par=%d	",n);
		ans+=mina[end]->weit;
		count++;
		while(temp!=NULL)
		{
			if(vis[temp->nod]==0)
			{
				//		printf("temp->node=%d	temp->wwei=%d",temp->nod,temp->wei);
				insert_min(temp->nod,temp->wei);
			}
			temp=temp->next;
		}
	}
	else
		delete_min();
	//printf("\n");
	//printf("node=%d		weit%d\n",mina[end]->node,mina[end]->weit);
	if(count<x && start!=end)
		func(mina[end]->node,x);
}
int main()
{
	lli n,i,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
	{
		s[i]=NULL;
		vis[i]=0;
	}
	for(i=0;i<m;i++)
	{
		lli k,x,y;
		scanf("%d%d%d",&x,&y,&k);
		s[x]=insert(x,y,k);
		s[y]=insert(y,x,k);
	}
	insert_min(1,0);
	func(1,n);
	if(count==n)
		printf("%d\n",ans);
	else
		printf("-1\n");
	return 0;
}
