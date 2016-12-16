#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
ll queue[100001];
int qhead=0;
int cur=0;
void qpush(ll l)
{
	queue[cur++]=l;
}
ll qpop()
{
	qhead++;
	return queue[qhead-1];
}
int stack[100003];
int head=-1;
int arr[100002][2];
void push(ll l)
{
	stack[++head]=l;
}
ll pop()
{
	head--;
	return stack[head+1];
}
void scant(int *p)
{
	register int c = getchar_unlocked();
	int x = 0;
	for(;(c<48 || c>57);c = getchar_unlocked())
		;
	for(;c>47 && c<58;c = getchar_unlocked())
	{
		x = (x<<1) + (x<<3) + c - 48;
	}
	*p = x;
}

int main()
{
	int test,count,n,k,d,i;
	scanf("%d",&test);
	while(test--)
	{
		count=1;
		scanf("%d %d",&n,&k);
		int *arr=(int*)malloc(sizeof(int)*n);
		int*b=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		head=-1;
		b[n-1]=-1;
		for(i=n-1;i>=0;)
		{
			if(head==-1 || arr[i]>arr[stack[head]])
			{
				if(head!=-1)
					b[i]=stack[head];
				push(i);
				i--;
			}
			else
			{

				while(arr[i]<=arr[stack[head]] && head!=-1)
				{
					pop();
				}
				if(head==-1)
					b[i]=-1;
				//	else if(arr[i]==arr[stack[head]])
				//		b[i]=stack[head];
				else if(arr[stack[head]]<arr[i])
				{
					b[i]=stack[head];
				}
				push(i);
				i--;
			}
		}
		int d,g,x;
		for(i=0;i<n-k+1;i++)
		{
			d=b[i];
			g=i;
			x=k;
			while(x>0)
			{
				if(d>i+k-1 || d==-1)
				{
					if(i==n-k)
						printf("%d",arr[g]);
					else
						printf("%d ",arr[g]);
					break;
				}
				else
				{
					g=d;
					d=b[d];
				}
				x--;
			}
			if(x==0)
			{
				if(i==n-k)
					printf("%d",arr[g]);
				else
					printf("%d ",arr[g]);
			}
		}


		/*	for(i=0;i<n-k+1;i++)
			{
			d=b[i];
			int x;
			x=i;
			if(k==1)
			count=0;
			else
			count=1;
			while(count!=k)
			{
			if(d>=k+i || d==-1)
			{
			if(i==n-k)
			printf("%d",arr[x]);
			else
			printf("%d ",arr[x]);
			break;
			}
			else
			{
			d=b[b[i]];
			x=d;
			count++;
			}
			if(count==k)
			{
			if(i==n-k)
			printf("%d",arr[d]);
			else
			printf("%d ",arr[d]);
			break;
			}

			}
			}*/
		printf("\n");
	}
	return 0;
}
/*
   for(i=0;i<n;i++)
   printf("%d ",arr[i]);
   printf("\n");
   for(i=0;i<n;i++)
   printf("%d ",b[i]);
   printf("\n");*/

