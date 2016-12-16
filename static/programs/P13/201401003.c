#include<stdio.h>
long long int max,min,n,t,i,a[100009];
void depth(long long int start, long long int end, long long int level,long long int flag)
{
//	if(level<6)
//		printf("%lld %lld %lld\n",start,end,level);
	if(end<start)
		return ;
	else if(end==start)
	{
		if(level>max)
		{
			max=level;
			min=a[end];
		}
		else if((level==max) && (a[end]<min))
		{
			max=level;
			min=a[end];
		}
		return ;
	}
	else
	{
		if(level>max)
		{
			max=level;
			min=a[end];
		}
		else if((level==max) && (a[end]<min))
		{
			max=level;
			min=a[end];
		}
			depth(start,a[end]-2-flag,level+1,flag);
			depth(a[end]-1-flag,end-1,level+1,flag+1);

		return ;
	}
}
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		max=-1;
		min=n+1;
		depth(0,n-1,0,0);
		printf("%lld %lld\n",min,max);
	}
	return 0;
}
