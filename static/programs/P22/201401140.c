#include<stdio.h>
#define mod 1000000007
long long int median;
//----------------------max_heap----------------------------------------------------------
long long int maxa[1000010];
long long int start_max=1,end_max=1;
void insert_heap_max(long long int p)
{
	if(p==1)
		return ;
	if(maxa[p/2]<maxa[p])
	{
		long long int temp;
		temp=maxa[p];
		maxa[p]=maxa[p/2];
		maxa[p/2]=temp;
		insert_heap_max(p/2);
	}
}
void delete_heap_max(long long int e)
{
	if(2*e+1<start_max)
	{
		if(maxa[2*e]>maxa[2*e+1])
		{
			if(maxa[e]<maxa[2*e])
			{
				long long int temp;
				temp=maxa[e];
				maxa[e]=maxa[2*e];
				maxa[2*e]=temp;
				delete_heap_max(2*e);
			}
		}
		else
		{
			if(maxa[e]<maxa[2*e+1])
			{
				long long int temp;
				temp=maxa[e];
				maxa[e]=maxa[2*e+1];
				maxa[2*e+1]=temp;
				delete_heap_max(2*e+1);
			}
		}
	}
	else if(2*e+1==start_max)
	{
		if(maxa[e]<maxa[2*e])
		{
			long long int temp;
			temp=maxa[e];
			maxa[e]=maxa[2*e];
			maxa[2*e]=temp;
			delete_heap_max(2*e);
		}
	}
}
void insert_max(long long int w)
{
	maxa[start_max]=w;
	start_max++;
	insert_heap_max(start_max-1);
}
void delete_max()
{
	maxa[end_max]=maxa[start_max-1];
	start_max--;
	delete_heap_max(end_max);
}

//----------------------min_heap------------------------------------------------------

long long int mina[1000010];
long long int start_min=1,end_min=1;
void insert_heap_min(long long int p)
{
	if(p==1)
		return ;
	if(mina[p/2]>mina[p])
	{
		long long int temp;
		temp=mina[p];
		mina[p]=mina[p/2];
		mina[p/2]=temp;
		insert_heap_min(p/2);
	}
}
void delete_heap_min(long long int e)
{
	if(2*e+1<start_min)
	{
		if(mina[2*e]<mina[2*e+1])
		{
			if(mina[e]>mina[2*e])
			{
				long long int temp;
				temp=mina[e];
				mina[e]=mina[2*e];
				mina[2*e]=temp;
				delete_heap_min(2*e);
			}
		}
		else
		{
			if(mina[e]>mina[2*e+1])
			{
				long long int temp;
				temp=mina[e];
				mina[e]=mina[2*e+1];
				mina[2*e+1]=temp;
				delete_heap_min(2*e+1);
			}
		}
	}
	else if(2*e+1==start_min)
	{
		if(mina[e]>mina[2*e])
		{
			long long int temp;
			temp=mina[e];
			mina[e]=mina[2*e];
			mina[2*e]=temp;
			delete_heap_min(2*e);
		}
	}
}
void insert_min(long long int w)
{
	mina[start_min]=w;
	start_min++;
	insert_heap_min(start_min-1);
}
void delete_min()
{
	mina[end_min]=mina[start_min-1];
	start_min--;
	delete_heap_min(end_min);
}
//---------------------------------------------------------------
void insert(long long int j)
{
	if(j>median)
		insert_min(j);
	else
		insert_max(j);
	if(start_max+1<start_min)
	{
		long long int l;
		l=mina[1];
		delete_min();
		insert_max(l);
	}
	else if(start_max>start_min+1)
	{
		long long int l;
		l=maxa[1];
		delete_max();
		insert_min(l);
	}
	if(start_min>start_max)
		median=mina[1];
	else
		median=maxa[1];
}
long long int func(long long int a,long long int b,long long int c,long long int n)
{
	if(n==1)
		return 1;
	else
	{
		long long int k;
		k=((a*median)%mod+(b*n)%mod+c)%mod;
		insert(k);
		return k;
	}
}
int main()
{
	long long int t,t1;
	scanf("%lld",&t);
	for(t1=0;t1<t;t1++)
	{
		start_max=1;
		start_min=1;
		end_max=1;
		end_min=1;
		long long int a,b,c,n,i;
		long long int sum=0,l;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		median=1;
		insert_max(1);
		for(i=1;i<=n;i++)
		{
			l=func(a,b,c,i);
			sum=sum+l;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
