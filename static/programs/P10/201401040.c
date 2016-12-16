#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

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

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}
char a[10000][105];
int main()
{
	char c,d;
	lli end=-1,start=0,temp,i,k;
	int n;
	din(n);
	if(n==0)
	{
		while(1)
		{
			c=getchar();
			if(c=='Q')
				return 0;
		}
	}

	gu();
	while(1)
	{
		c=getchar();
		if(c=='A')
		{
			lldin(temp);
			d=gu();
			for(i=end+1,k=0;k<temp;k++,i++)
			{
				if(i%n==start%n && end!=-1)
					start++;
				scanf("%s",a[i%n]);
				gu();
				end++;
			}
		}
		else if(c=='R')
		{
			lldin(temp);
			for(i=start,k=0;k<temp && start<=end;i++,k++)
			{
				start++;
			}
			if(temp>=n)
			{
				end=-1;
				start=0;
			}
			if(start>end)
			{
				end=-1;
				start=0;
			}
			//lldout(start);
			//lldout(end);
		}
		else if(c=='L')
		{
			for(i=start;i<=end;i++)
				printf("%s\n",a[i%n]);
		}
		else if(c=='Q')
			return 0;
	}
	return 0;
}
