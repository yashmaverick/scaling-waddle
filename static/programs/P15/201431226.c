#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,j,i;
		scanf("%d%d",&n,&k);
		int a[n],b[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int start=0;
		for(i=0;i<n;i++)
		{
			b[i]=a[i];
			if(i>=k)
				start++;
			for(j=i-1;j>=start;j--)
			{
				if(b[j]>b[j+1])
					b[j]=b[j+1];
				else
					break;
			}
		}
		for(i=0;i<n-k+1;i++)
		{
			if(i==n-k)
				printf("%d\n",b[i]);
			else
				printf("%d ",b[i]);
		}
	}
	return 0;
}
