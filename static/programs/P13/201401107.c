#include<stdio.h>
#include<stdlib.h>
long long int a[1000000];
long long int maxdepth=0,deepvalue;

long long int binarysearch(long long int start, long long int end, long long int val)
{

if(start==end)
{
	if(a[start]<a[val])
		return start;
	else return -1;
}
if(start>end)
	return -1;
long long int mid=(start+end)/2;
if(a[mid]<a[val])
{
	if(a[mid+1]>a[val])
		return mid;
	else binarysearch(mid+1,end,val);
}
else if(a[mid]>a[val])
{
	if(a[mid-1]<a[val])
		return mid-1;
	else binarysearch(start,mid-1,val);
}
}

void recfunc(long long int end, long long int start,long long int depth)
{
	if(start==end)
	{
		if(depth>maxdepth)
		{
			maxdepth=depth;
			deepvalue=a[start];
		}
		else if(depth==maxdepth)
		{
			if(deepvalue>a[start])
				deepvalue=a[start];
		}
	//	printf("%lld %lld\n",deepvalue,maxdepth);
		return;
	}
	else if(start>end)
		return;
	else
	{
		/*if(a[start]>a[end])
		{
			maxdepth=end;
			deepvalue=a[start];
			return ;
		}*/
		long long int i,breakpoint,flag=0;
/*		for(i=end;i>=0;i--)
		{
			if(a[i]<a[end])
			{
				breakpoint=i;
				break;
			
			}
			


		}*/
		breakpoint=binarysearch(start,end-1,end);
		if(breakpoint==-1||breakpoint==end-1)
		{
			recfunc(end-1,start,depth+1);
		}
		else
		{
		recfunc(end-1,breakpoint+1,depth+1);
		recfunc(breakpoint,start,depth+1);
		}
		return;
	}
}




int main()
{
	long long int depth=0,t,num,i,j;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		maxdepth=0,deepvalue=-1;
		scanf("%lld",&num);
		for(j=0;j<num;j++)
		{
			scanf("%lld",&a[j]);
		}
		recfunc(num-1,0,0);
		printf("%lld %lld\n",deepvalue,maxdepth);
	}

	
return 0;
}
