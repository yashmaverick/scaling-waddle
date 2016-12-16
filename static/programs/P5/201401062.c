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

#define MAX 1010

int main()
{
	int t;
	din(t);
	while(t--)
	{
		int n,k,i,j;
		din(n);
		din(k);
		int arr[MAX];
		char temp[MAX];
		for(i=0;i<n;i++)
			scanf("%s %d",temp,arr+i);	
		
		qsort(arr,n,sizeof(int),cmpfunc);

		int flag=1;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				int val = k - arr[i]-arr[j];
				//if(val<0)
				//	break;
				//printf("%d %d %d %d\n",i,j,n-j-1,val);
				if(bsearch(&val,arr+j+1,n-j-1,sizeof(int),cmpfunc))
				{

					printf("YES\n");
					flag=0;
					break;
				}
			}
			if(!flag)
				break;
		}
			
		if(flag)
			printf("NO\n");
	}

	return 0;
}
