#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,beg,min,k,index;
		scanf("%d %d",&n,&k);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		min=1000000000;
		for(i=0;i<k;i++)
		{
			if(a[i]<min)
			{
				min=a[i];
				index=i;
			}
		}
		beg=0;
		while(beg!=n-k+1)
		{
			if(beg>index)
			{
				min=1000000000;
				for(i=beg;i<beg+k;i++)
				{
					if(a[i]<min)
					{
						min=a[i];
						index=i;
					}
				}
			}
			if(beg<n-k)
			{
				if(a[beg+k-1]<min)
				{
					min=a[beg+k-1];
					index=beg+k-1;
				}
				printf("%d ",min);
			}
			else if(beg==n-k)
			{
				if(a[beg+k-1]<min)
				{
					min=a[beg+k-1];
					index=beg+k-1;
				}
				printf("%d\n",min);
			}
			beg++;
		}
	}
	return 0;
}
