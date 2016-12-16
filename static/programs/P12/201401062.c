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
#define MAXN 500002
int stack[MAXN];
int head=-1;
int arr[MAXN];
lli right[MAXN];

void push(int n)
{
	stack[++head]=n;
}
void pop()
{
	head--;
}
int top()
{
	return stack[head];
}
int size()
{
	return head+1;
}

void showStack()
{
	int i;
	printf("Stack is :");
	for(i=0;i<=head;i++)
		printf("%d ",stack[head]);
	printf("\n");
}

void showArr(lli n)
{
	int i;
	printf("Array is: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
}

int main()
{
	lli n;
	int i;
	while(1)
	{
		lldin(n);
		if(!n)
			break;
		for(i=0;i<n;i++)
			din(arr[i]);
		/*right[n-1]=0;
		for(i=n-2;i>=0;i--)
			if(arr[i]==arr[i+1])
				right[i]=right[i+1] + 1;
			else
				right[i]=0;
				*/
		//arr[n]=INF;
		//printf("n : %lld\n",n);
		//showArr(n);
		head=-1;
		//showStack();
		//push(n);
		push(n-1);
		lli minus=0;
		right[n-1]=0;
		for(i=n-2;i>=0;i--)
		{
			//showStack();
			lli count=0;
			//int largest=-INF;
			//printf("i : %d , minus : %lld right[i] : %lld\n",i,minus,right[i]);
			int flag=0;
			while(size()>0)
			{
				//printf("%d\n",head);
				if(arr[i]>=arr[top()])
				{
					flag=1;
					//if(arr[top()]>largest)
					//	largest=arr[top()];
					if(arr[top()]==arr[i])
					{
						right[i] = right[top()]+1;
					}
					else
						right[i]=0;
					count+=right[top()];
					pop();
					count++;
				}
				else
				{
					if(!flag)
						right[i]=0;
					break;
				}
			}
			//printf("elem : %d canSee : %lld right[i] : %lld\n",arr[i],(size()==0)?count:count+1,right[i]);
			if(size()==0)
			{
				minus+=count;
				//minus+= ( )
			}
			else
				minus+=count+1;
			//if(top()==n)
			//	minus--;
			
			//minus+=count+1;
			push(i);
			//printf("i : %d , minus : %lld right[i] : %lld\n",i,minus,right[i]);
		}
		lldout(((lli)n*(lli)(n-1))/2 - minus);
	}
	return 0;
}
