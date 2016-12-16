#include<stdio.h>
#include<stdlib.h>
#define mod 1000000007
int maxheap[200001],minheap[200001];
int maxheap_size=0,minheap_size=0;
long long int sum;
int getmadian();
void insert_maxheap(int n);
void insert_minheap(int n);
void update_heap(int median,int n);
void delete_minheap(int n);
void delete_maxheap(int n);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a,b,c,median,j;
		  int  n,i,ans;
//		sum=0;
		maxheap_size=0,minheap_size=0;
		  scanf("%lld %lld %lld %d",&a,&b,&c,&n);
	//	maxheap[++maxheap_size]=1;
		for(i=1;i<=200001;i++)
			maxheap[i]=0;
		for(i=1;i<=200001;i++)
			minheap[i]=0;
		sum=1;
		maxheap[++maxheap_size]=1;
		for(i=2;i<=n;i++)
		{
			median=getmedian();
	//		printf("median %lld\n",median);
			ans=((a*median)+(b*i)+c)%mod;
			//printf("ans %d\n",ans);
			sum+=ans;
			update_heap(median,ans);
//			for(j=1;j<=minheap_size;j++)
//				printf("%d ",minheap[j]);
//			printf("\n");
//			for(j=1;j<=maxheap_size;j++)
//				printf("%d ",maxheap[j]);
//			printf("\n");
		}
		printf("%lld\n",sum);
	}
return 0;
}
void insert_maxheap(int n)
{
	maxheap_size++;
	maxheap[maxheap_size]=n;
	int now=maxheap_size;
	while(now>1 && maxheap[now/2]<n)
	{
		maxheap[now]=maxheap[now/2];
		maxheap[now/2]=n;
		now=now/2;
	}
}
void insert_minheap(int n)
{
	minheap_size++;
	minheap[minheap_size]=n;
	int now=minheap_size;
	while(now>1 && minheap[now/2]>n)
	{
		minheap[now]=minheap[now/2];
		minheap[now/2]=n;
		now=now/2;
	}
}
int getmedian()
{
	if(minheap_size>maxheap_size)
		return minheap[1];
	else
		return maxheap[1];
}
void update_heap(int median,int n)
{
	if(n>median && minheap_size<=maxheap_size && maxheap_size-minheap_size<=1)
		insert_minheap(n);
	else if(n>median && minheap_size>maxheap_size && minheap_size-maxheap_size<=1)
	{
		int num=minheap[1];
		delete_minheap(1);
		insert_maxheap(num);
		insert_minheap(n);
	}
	else if(n<median && maxheap_size<=minheap_size && minheap_size-maxheap_size<=1)
		insert_maxheap(n);
	else if(n<median && maxheap_size>minheap_size && maxheap_size-minheap_size<=1)
	{
		int num=maxheap[1];
		delete_maxheap(1);
		insert_minheap(num);
		insert_maxheap(n);
	}
	else if(n==median)
	{
		if(minheap_size<=maxheap_size)
			insert_minheap(n);
		else
			insert_maxheap(n);
	}
}
void delete_minheap(int n)
{
	minheap[1]=minheap[minheap_size];
	minheap_size--;
	int now=n;
	int no=minheap[1];
	while(now<=minheap_size/2 && (minheap[2*now]<no || minheap[2*now+1]<no) )
	{
		int t;
		if(minheap[2*now]>minheap[2*now+1] && minheap[2*now+1]!=0)
		{
			t=minheap[now];
			minheap[now]=minheap[2*now+1];
			minheap[2*now+1]=t;
			now=now*2+1;
		}
		else if(minheap[2*now]<=minheap[2*now+1])
		{
			t=minheap[now];
			minheap[now]=minheap[2*now];
			minheap[2*now]=t;
			now=now*2;
		}
	}
}
void delete_maxheap(int n)
{
	maxheap[1]=maxheap[maxheap_size];
	maxheap_size--;
	int now=n;
	int no=maxheap[1];
	while(now<=maxheap_size/2 &&(maxheap[2*now]>no || maxheap[2*now+1]>no))
	{
		int t;
		if(maxheap[2*now]<maxheap[2*now+1] && maxheap[2*now+1]!=0)
		{
			t=maxheap[now];
			maxheap[now]=maxheap[2*now+1];
			maxheap[2*now+1]=t;
			now=now*2+1;
		}
		else if(maxheap[2*now]>=maxheap[2*now+1])
		{
			t=maxheap[now];
			maxheap[now]=maxheap[2*now];
			maxheap[2*now]=t;
			now=now*2;
		}
	}
}
