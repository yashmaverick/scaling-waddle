#include<stdio.h>
# define NUM 1000000007
long long int min_heap[200005],max_heap[200005];
long long int min,max;

void swap_max(long long int a,long long int b)
{
	long long int temp=max_heap[a];
	max_heap[a]=max_heap[b];
	max_heap[b]=temp;
}

void swap_min(long int a,long int b)
{
	long long int temp=min_heap[a];
	min_heap[a]=min_heap[b];
	min_heap[b]=temp;
}

void insert_max(long long int n)
{
	max++;
	max_heap[max]=n;
	long long int temp=max;
	while(max_heap[temp/2]<max_heap[temp] && temp>1)
	{
		swap_max(temp,temp/2);
		temp=temp/2;
	}
}

void insert_min(long long int n)
{
	min++;
	min_heap[min]=n;
	long long int temp=min;
	while(min_heap[temp/2] > min_heap[temp] && temp>1)
	{
		swap_min(temp,temp/2);
		temp=temp/2;
	}
}

void del_min()
{
	min_heap[1]=min_heap[min];
	min--;
	long long int k=1;
	while((min_heap[2*k]<min_heap[k] && 2*k<=min)  || (min_heap[2*k+1]<min_heap[k] && 2*k+1<=min))
	{
		if(min_heap[2*k+1]<min_heap[2*k] && 2*k+1<=min)
		{
			swap_min(k,2*k+1);
			k=2*k+1;
		}
		else
		{
			swap_min(k,2*k);
			k=2*k;
		}
	}
}

void del_max()
{
	max_heap[1]=max_heap[max];
	max--;
	long long int k=1;
	while((max_heap[2*k]>max_heap[k] && 2*k<=max) || (max_heap[2*k+1]>max_heap[k] && 2*k+1<=max))
	{
		if(max_heap[2*k+1]>max_heap[2*k] && 2*k+1<=max)
		{
			swap_max(k,2*k+1);
			k=2*k+1;
		}
		else
		{
			swap_max(k,2*k);
			k=2*k;
		}
	}
}


void balance()
{
	while(max-min>1)
	{
		insert_min(max_heap[1]);
		del_max();
	}
	while(min-max>1)
	{
		insert_max(min_heap[1]);
		del_min();
	}
}

void insert(long long int n)
{
	if(n<max_heap[1])
	{
		insert_max(n);
	}
	else
	{
		insert_min(n);
	}
	balance();
}

long long int getmedian()
{
	if(min>max)
		return min_heap[1];
	else
		return max_heap[1];
}
void xheap()
{
	int i;
	printf("max ");
	for(i=1;i<=max;i++)
		printf("%lld ",max_heap[i]);
	printf("\n");
}
void nheap()
{
	int i;
	printf("min ");
	for(i=1;i<=min;i++)
		printf("%lld ",min_heap[i]);
	printf("\n");
}

int main()
{
	min=max=1;
	long long int l,j,i,k,t;
	long long int a,b,c,n;
	scanf("%lld",&t);
	while(t--)
	{
		min=max=1;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		long long int f[200005],m[200005];
		f[1]=1;
		f[2]=(a+2*b+c)%NUM;
		if(f[1]<f[2])
		{
			max_heap[1]=f[1];
			min_heap[1]=f[2];
		}
		else
		{
			min_heap[1]=f[1];
			max_heap[1]=f[2];
		}
		m[2]=1;
		long long int sum=f[1]+f[2];
		for(i=3;i<=n;i++)
		{
			m[i]=getmedian();
			f[i]=(a*m[i]+b*i + c)%NUM;
			sum=sum+f[i];
			insert(f[i]);
			//	xheap();
			//	nheap();
		}
		printf("%lld\n",sum);
		//	for(i=0;i<7;i++)
		//		printf("%d ",f[i]);
		//	printf("\n");
		//	for(i=0;i<7;i++)
		//		printf("%d ",m[i]);
		//	printf("\n");
	}
	return 0;
}
