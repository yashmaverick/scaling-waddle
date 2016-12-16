#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define PLUSWRAP(index,n) index = (index+1)%n
#define MINUSWRAP(index,n) index = (index + n -1)%n

#define INF 1000000000	//1 billion (10^9)

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

#define MAXN 10010
int arr[MAXN];
int queue[10*MAXN];
int start=-1,end=-1,size=0;
const int N = 10*MAXN;
void push(int elem)
{
	if(size==0)
	{
		start=0;
		end=0;
		queue[end]=elem;
		size=1;
	}
	else
	{
		end = (end+1)%N;
		queue[end]=elem;
		size++;
	}
}

void popFront()
{
	size--;
	start = (start+1)%N;
	if(size==0)
		start=end=-1;
}
void popBack()
{
	size--;
	end = end - 1;
	if(end<0)
		end = N - 1;
	if(size==0)
		start=end=-1;
}
int front()
{
	if(start!=-1)
		return queue[start];
	else
		return -1;
}
int back()
{
	if(end!=-1)
		return queue[end];
	else
		return -1;
}
void clear()
{
	start=end=-1;
	size=0;
}
void showQ()
{
	int i;
	printf("Queue is : ");
	for(i=0;i<size;i++)
		printf("%d ",queue[(start+i)%N]);
	printf("\n");
}

int main()
{
	int t;
	int i;
	din(t);
	while(t--)
	{
		int n,k;
		//int ans=-1;
		din(n);din(k);
		int mn=0;
		arr[0]=INF;
		clear();
		for(i=1;i<=n;i++)
		{
			din(arr[i]);
			if(i<=k && arr[i]<arr[mn])
				mn = i;
		}
		push(mn);
		//showQ();
		for(i=mn+1;i<=k;i++)
		{
			while(size>0)
			{
				if(arr[i]<arr[back()])
					popBack();
				else
					break;
			}
			push(i);
		}
		printf("%d%s",arr[front()],(k+1>n?"":" "));
		for(i=k+1;i<=n;i++)
		{
			//showQ();
			int start = i-k+1;
			if(front()==start-1)
				popFront();
			while(size>0)
			{
				if(arr[i]<arr[back()])
					popBack();
				else
					break;
			}
			push(i);
			//showQ();
			printf("%d%s",arr[front()],(i==n?"":" "));
		}
		printf("\n");
	}
	return 0;
}
