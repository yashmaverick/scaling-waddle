#include<stdio.h>
#include<stdlib.h>
typedef struct l{
	int data;
	struct l* nxt;
}link;
typedef link* list;
void adjins(list po[],int u,int v)
{
	list temp;
	temp=(list)malloc(sizeof(link));
	temp->data=v;
	temp->nxt=po[u];
	po[u]=temp;
	return;
}
int size,cnt;
void pri(int h[])
{
	int i;
	for(i=1;i<=size;i++)
	{
		printf("%d ",h[i]);
	}
}
void insert(int x,int h[])
{
	int temp,i;
		size++;
		h[size]=x;
		for(i=size;x<h[i/2] && i>1;i=i/2)
		{
			temp=h[i];
			h[i]=h[i/2];
			h[i/2]=temp;
		}

	return;
}
int mi(int x1,int x2)
{
	return x1<x2?x1:x2;
}
int delmin(int h[])
{
	int min,new,i,last;
	min=h[1];last=h[size--];
	for(i=1;size>=2*i;i=new)
	{
		new=2*i;
		if(new!=size && h[new+1]<h[new])
		{
			new++;
			//m=mi(h[2*i],h[2*i+1]);
		}
		if(last>h[new])
		{
			h[i]=h[new];
		}
		else
		{
			break;
		}
	}
	h[i]=last;
	return min;
}
void cpu(list po[],int inindex[],int h[],int n)
{
	int y;list tenp;
	while(cnt!=n){
	y=delmin(h);cnt++;
	if(cnt!=n)
	{printf("%d ",y);}
	else
	{printf("%d\n",y);}
	tenp=po[y];
	while(tenp!=NULL)
	{
		inindex[tenp->data]--;
		if(inindex[tenp->data]==0)
		{
			insert(tenp->data,h);
		}
		tenp=tenp->nxt;
	}
	}
}
int main()
{
	int n,m,i,j,k,u,v;
	size=0;cnt=0;
	scanf("%d %d",&n,&m);
	list po[n+5];
	int inindex[n+5];
	int h[n+5];
	for(i=0;i<n+5;i++)
	{
		inindex[i]=0;
		po[i]=NULL;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		inindex[v]++;
		adjins(po,u,v);
	}
	for(i=1;i<=n;i++)
	{
		if(inindex[i]==0)
		{
			insert(i,h);
		//	pri(h);
		}
	}
	cpu(po,inindex,h,n);
	return 0;
}


