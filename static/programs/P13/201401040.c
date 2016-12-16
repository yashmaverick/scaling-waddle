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
	int t;
	din(t);
	while(t--)
	{
	int n,post[100005],stack[2][100005],maxdepth=0,minelement,index=-1,i,templevel;
	din(n);
	stack[1][0]=-1;
	for(i=0;i<n;i++)
		din(post[i]);
	for(i=n-1;i>=0;i--)
	{
		if(index==-1)
		{
			stack[0][index+1]=post[i];
			stack[1][index+1]++;
			index++;
			if(stack[1][index]>maxdepth)
			{
				maxdepth=stack[1][index];
				minelement=stack[0][index];
			}
			if(stack[1][index]==maxdepth)
			{
				if(minelement>stack[0][index])
					minelement=stack[0][index];
			}

		}
		else if(post[i]>stack[0][index])
		{
			stack[0][index+1]=post[i];
			stack[1][index+1]=stack[1][index]+1;
			index++;
			if(stack[1][index]>maxdepth)
			{
				maxdepth=stack[1][index];
				minelement=stack[0][index];
			}
			if(stack[1][index]==maxdepth)
			{
				if(minelement>stack[0][index])
					minelement=stack[0][index];
			}
		}
		else if(post[i]<stack[0][index])
		{
			while(post[i]<stack[0][index] && index>-1)
			{
				templevel=stack[1][index];
				index--;
			}
			stack[0][index+1]=post[i];
			stack[1][index+1]=templevel+1;
			index++;
			if(stack[1][index]>maxdepth)
			{
				maxdepth=stack[1][index];
				minelement=stack[0][index];
			}
			if(stack[1][index]==maxdepth)
			{
				if(minelement>stack[0][index])
					minelement=stack[0][index];
			}
		}
	}
	printf("%d %d\n",minelement,maxdepth);
	}
	return 0;
}
