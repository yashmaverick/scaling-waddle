#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define repf(i,l,n) for(i=l;i<n;i++)
#define repb(i,l,n) for(i=l;i>n;i--)
#define LL long long int 
typedef struct info
{
	int value;
	int depth;
	int lmin;
	int lmax;
	bool visited;
}info;
void in(int *address)
{
scanf("%d",address);
}
void solution(info ans)
{
printf("%d %d\n",ans.value,ans.depth);
}
int stack[200000];
info a[200000],max;
int main()
{
	int t,n,i,start;
	in(&t);
	while(t--)
	{
		start=0;
		scanf("%d",&n);
		stack[0]=0;
		i=0;
		a[i].visited=a[i].depth=a[i].lmin=a[i].lmax=0;
		repf(i,1,n+1)
		{
			in(&a[i].value);
			a[i].visited=a[i].depth=a[i].lmin=a[i].lmax=0;
		}
		repf(i,1,n+1)
		{

			while(start>=0 && a[i].value<a[stack[start]].value)
				start--;
			if(start==-1)
				stack[++start]=0;
			stack[++start]=i;
			if(start==0)
				a[i].lmin=0;
			else
				a[i].lmin=stack[start-1];
		}
		start=-1;
		repf(i,1,n+1)
		{

			while(start>=0 && a[i].value>a[stack[start]].value)
				start--;
			if(start==-1)
				stack[++start]=0;
			stack[++start]=i;
			if(start==0)
				a[i].lmax=0;
			else
				a[i].lmax=stack[start-1];
		}
		max.value=n;
		max.depth=0;
		repb(i,n,0)
		{
			if(a[a[i].lmin].visited==0)
			{
				a[a[i].lmin].depth=a[i].depth+1;
				a[a[i].lmin].visited=1;
			}
			if(a[a[i].lmax].visited==0)
			{
				a[a[i].lmax].depth=a[i].depth+1;
				a[a[i].lmax].visited=1;
			}
		}
		repf(i,1,n+1)
		{
			if(max.depth<a[i].depth)
				max=a[i];
			else if(max.depth==a[i].depth &&  max.value>a[i].value)
				max=a[i];		
		}
		solution(max);	
	}
	return 0;
}
