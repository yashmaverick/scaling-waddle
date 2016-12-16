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
		int stack[500005],index=0,temp,tempindex,i;
		long long int count=0,n;
		lldin(n);
		if(n==0)
			return 0;
		for(i=0;i<n;i++)
		{
			din(temp);
			if(index==0)
			{
				stack[index]=temp;
				index++;
			}
			else if(stack[index-1]>=temp)
			{
				/*tempindex=index-1;
				  while(tempindex>0)
				  {
				  if(stack[tempindex]!=stack[tempindex-1])
				  count++;
				  tempindex--;
				  }
				  if(stack[tempindex]!=stack[tempindex+1])
				  count++;
				  stack[index]=temp;
				  index++;*/
				tempindex=index-1;
				if(stack[tempindex]==temp)
				{
					while(stack[tempindex]==temp && tempindex>=0)
					{
						count++;
						tempindex--;
					}
					if(tempindex!=-1)
						count++;
				}
				else
					count++;
				stack[index]=temp;
				index++;
			}

			else if(stack[index-1]<temp)
			{
				/*while(stack[index-1]<=temp && index>0)
				  {
				  if(temp==stack[index-1])
				  {
				  tempindex=index-1;
				  while(stack[tempindex]==temp)
				  {
				  count++;
				  tempindex--;
				  }
				  if(tempindex!=-1)
				  count++;
				  break;
				  }
				  index--;
				  count++;
				  }
				  stack[index]=temp;*/
				tempindex=index-1;
				while(stack[tempindex]<temp && tempindex>=0)
				{
					count++;
					tempindex--;
				}
				if(stack[tempindex]==temp && tempindex>-1)
				{
					index=tempindex+1;
					while(stack[tempindex]==temp && tempindex>-1)
					{
						count++;
						tempindex--;
					}
					stack[index]=temp;
				}
				else
				{
					stack[tempindex+1]=temp;
					index=tempindex+1;
				}
				if(tempindex!=-1)
					count++;
				index++;
				//stack[tempindex+1]=temp;
				//index=tempindex+2;

			}
			/*else if(stack[index-1]==temp)
			  {
			  tempindex=index-1;
			  while(stack[tempindex]==temp && tempindex>=0)
			  {
			  count++;
			  tempindex--;
			  }
			//
			if(tempindex>0)
			{
			while(tempindex>0)
			{
			if(stack[tempindex]!=stack[tempindex-1])
			count++;
			tempindex--;
			}
			count++;
			}
			stack[index]=temp;
			index++;
			}*/
		}
		//	dout(count);
		lldout(n*(n-1)/2-count);
	}
	return 0;
}
