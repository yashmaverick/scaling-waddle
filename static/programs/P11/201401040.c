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


int main()
{
	while(1)
	{
		int i,n,heights[100005],stack[2][100005],index=-1,flag=0,tempindex;
		lli tempmax=0,max=0;
		din(n);
		if(n==0)
			return 0;
		for(i=0;i<n;i++)
			din(heights[i]);
		for(i=0;i<n;i++)
		{
			flag=0;
			if(index==-1 || heights[i]>stack[0][index])
			{
				stack[0][index+1]=heights[i];
				stack[1][index+1]=i;
			//	printf("index is %d",index);
				index++;
			}
			else if(heights[i]<stack[0][index])
			{
				while(heights[i]<=stack[0][index] && index>-1)
				{
					if(heights[i]==stack[0][index])
					{
						flag=1;
						break;
					}
					tempmax=(lli)stack[0][index]*(lli)(i-stack[1][index]);
					if(tempmax>max)
						max=tempmax;
					index--;
				}
				if(flag)
					continue;

				stack[0][index+1]=heights[i];
				index++;
			}
		}
		while(index>-1)
		{
			tempmax=(lli)(i-stack[1][index])*(lli)stack[0][index];
			if(tempmax>max)
				max=tempmax;
			index--;
		}
		lldout(max);
	}
		return 0;
	}
