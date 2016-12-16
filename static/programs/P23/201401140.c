#include<stdio.h>
#include<stdlib.h>
typedef int lli;
typedef struct arr{
	lli nod;
	struct arr *next;
}arr;
typedef struct heap{
	//	lli node;
	lli weit;
}heap;
heap *mina[1000010];//,f[1000010];
arr *s[1000010];
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
void insert_min(/*lli k,*/lli w)
{
	mina[start]=(heap*)malloc(sizeof(heap));
	//	mina[start]->node=k;
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
//-----------------------------------------------------------------
lli o[1000010];
arr* insert(lli k,lli f)
{
	o[f]++;
	arr *temp;
	temp=(arr*)malloc(sizeof(arr));
	temp->nod=f;
	temp->next=s[k];
	s[k]=temp;
	return s[k];
}
lli start1,li[1000010];
void func(lli j)
{
	arr *temp;
	temp=s[j];
	li[start1++]=j;//mina[end]->weit;
	delete_min();
	while(temp!=NULL)
	{
		o[temp->nod]--;
		if(o[temp->nod]==0)
			insert_min(temp->nod);
		temp=temp->next;
	}
	s[j]=NULL;
	if(start!=end)
		func(mina[end]->weit);
}
int main()
{
	lli n,m,i;
	scanf("%d%d",&n,&m);
	lli k,f;
	for(i=0;i<=n;i++)
	{
		s[i]=NULL;
		o[i]=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&k,&f);
		s[k]=insert(k,f);
		//	s[f]=insert(f,k);
	}
	for(i=1;i<=n;i++)
		if(o[i]==0)
			insert_min(i);
	//if(start!=end)
//	{
		func(mina[end]->weit);
		for(i=0;i<start1-1;i++)
			printf("%d ",li[i]);
		printf("%d",li[start1-1]);
		printf("\n");
//	}
//	else
//		printf("Sandro fails.\n");
	return 0;
}
