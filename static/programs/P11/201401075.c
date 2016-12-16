#include<stdio.h>
int main()
{
	long long int n,i,j,h,count=0,area;
	scanf("%lld",&n);
	long long int pre=0;
	long long int max=0,ar[100001][2];
	while(n!=0)
	{
		max=0;
		count=0;
		pre=-1;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&h);
			if(h>pre)
			{
				ar[count][0]=h;
				ar[count][1]=i;
				count++;
			}
			else if(h<pre)
			{
				count--;
				while(ar[count][0]>h)
				{
					area=ar[count][0]*(i-ar[count][1]);
					if(area>max)
						max=area;
					count--;
					if(count<0)
						break;
				}
				if(count<0)
				{
					count++;
					ar[count][0]=h;
					count++;
				}
				else if(ar[count][0]!=h)
				{
					count++;
					ar[count][0]=h;
					count++;
				}
				else
					count++;
			}
			if(i==n-1)
			{
				count--;
				while(count>=0)
				{
					area=ar[count][0]*(i+1-ar[count][1]);
					if(area>max)
						max=area;
					count--;
				}
			}
			pre=h;
		}
		printf("%lld\n",max);
		scanf("%lld",&n);
	}
	return 0;
}


