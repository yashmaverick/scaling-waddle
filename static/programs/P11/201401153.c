#include<stdio.h>
int main()
{
	long long n,i,j,area,maxarea, lastarea;
	while(1)
	{
		maxarea=0;
		scanf("%lld",&n);
		if(n==0)
			break;
		else
		{
			long long a[n], left[n], right[n];
			for(i=0;i<n;i++)
			{
				scanf("%lld",&a[i]);
			}
			left[0]=-1;
			right[n-1]=n;
			for(i=1;i<n;i++)
			{
				j=i-1;
				while(j>=0)	
				{
					if(a[j]<a[i])
					{
						left[i]=j;
						break;
					}
					else
					{
						j=left[j];
						if(j==-1)
						{
							left[i]=-1;
							break;
						}
					}
				}
			}
			for(i=n-1;i>=0;i--)
			{
				j=i+1;
				while(j<n)
				{
					if(a[j]<a[i])
					{
						right[i]=j;
						break;
					}
					else
					{
						j=right[j];
						if(j==n)
						{
							right[i]=n;
							break;
						}
					}

				}
				area=(right[i]-left[i]-1)*a[i];
				if(area>maxarea)
					maxarea=area;
			}
			//	if(n==1)
			//		maxarea=a[0];
/*			for(i=0;i<n;i++)
				printf("%lld ",left[i]);
			printf("\n");
			for(i=0;i<n;i++)
				printf("%lld ",right[i]);
			printf("\n");
*/			printf("%lld\n",maxarea);
		}
	}
	return 0;
}
