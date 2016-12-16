#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
typedef struct heap{
	lli node;
	lli weit;
}heap;
typedef struct arr{
	long long int no;
	long long int dis;
	struct arr *next;
}arr;
heap a[100010];
arr *s[100010];
lli start=1,end=1,vis[100010],wei[100010],f[100010],in_heap[100010];
void swap(lli i1,lli i2)
{
	lli temp;
	temp=f[i1];
	f[i1]=f[i2];
	f[i2]=temp;
}
void insert_heap(lli p)
{
	if(p==1)
		return ;
	if(a[p/2].weit>a[p].weit)
	{
		heap temp;
		temp=a[p];
		a[p]=a[p/2];
		a[p/2]=temp;
		insert_heap(p/2);
		swap(p/2,p);
	}
}
void delete_heap(lli e)
{
	if(2*e+1<start)
	{
		if(a[2*e].weit<a[2*e+1].weit)
		{
			if(a[e].weit>a[2*e].weit)
			{
				heap temp;
				temp=a[e];
				a[e]=a[2*e];
				a[2*e]=temp;
				swap(e,2*e);
				delete_heap(2*e);
			}
		}
		else
		{
			if(a[e].weit>a[2*e+1].weit)
			{
				heap temp;
				temp=a[e];
				a[e]=a[2*e+1];
				a[2*e+1]=temp;
				swap(e,2*e+1);
				delete_heap(2*e+1);
			}
		}
	}
	else if(2*e+1==start)
	{
		if(a[e].weit>a[2*e].weit)
		{
			heap temp;
			temp=a[e];
			a[e]=a[2*e];
			a[2*e]=temp;
			swap(e,2*e);
			delete_heap(2*e);
		}
	}
}
void insert(lli k,lli w)
{
	a[start].node=k;
	a[start].weit=w;
	f[k]=start;
	start++;
	in_heap[k]=1;
	insert_heap(start-1);
}
void delete()
{
	//in_heap[a[end]->node]=0;
	a[end]=a[start-1];
	start--;
	delete_heap(end);
}
arr* insert1(long long int x,long long int y,long long int w)
{
	arr *temp;
	temp=(arr*)malloc(sizeof(arr));
	temp->no=y;
	temp->dis=w;
	temp->next=s[x];
	s[x]=temp;
	return s[x];
}
void func(long long int j)
{
	arr *temp;
	temp=s[j];
	vis[j]=1;
	while(temp!=NULL)
	{
		if(vis[temp->no]==0)
		{
			if(wei[temp->no]>temp->dis+wei[j] || wei[temp->no]==0)
			{
				wei[temp->no]=wei[j]+temp->dis;
				if(in_heap[temp->no]==0)
					insert(temp->no,wei[temp->no]);
				a[f[temp->no]].weit=wei[temp->no];
				insert_heap(f[temp->no]);
			}
			else
				if(in_heap[temp->no]==0)
					insert(temp->no,wei[temp->no]);

		}
		temp=temp->next;
	}
	delete();
	if(start>end)
		func(a[end].node);
}

int main()
{
	start=1;
	end=1;
	long long int t=1,t1;
	//scanf("%lld",&t);
	for(t1=0;t1<t;t1++)
	{
		long long int i,n,m,x,y,w;
		scanf("%lld%lld",&n,&m);
		for(i=0;i<=n;i++)
		{
			s[i]=NULL;
			f[i]=0;
			wei[i]=0;
			vis[i]=0;
			in_heap[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&w);
			s[x]=insert1(x,y,w);
		}
		long long int n1,n2;
		scanf("%lld%lld",&n1,&n2);
		insert(n1,0);
		func(n1);
		if(wei[n2]==0)
			printf("NO\n");
		else
			printf("%lld\n",wei[n2]);
	}
	return 0;
}
