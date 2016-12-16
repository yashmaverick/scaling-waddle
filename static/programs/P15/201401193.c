#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,j;
		scanf("%d %d",&n,&k);
		int i,a[n],c[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			c[i]=0;
		}
		c[n-1]=n;
		for(i=n-2;i>=0;i--)
		{
			j=i+1;
			if(a[j]<a[i])
				c[i]=j;
			else
			{
				while(c[j]!=n)
				{
					if(a[c[j]]<a[i])
					{
						c[i]=c[j];
						break;
					}
					else
						j=c[j];
				}
				if(c[j]==n)
				{
					c[i]=n;
				}
			}
		}
		int p=0;
		for(i=0;i<n-k+1;i++)
		{
			if(p<i)
				p=i;
			while(1)
			{
				if(c[p]>i+k-1)
					break;
				else
					p=c[p];
			}
			if(i==n-k)
				printf("%d",a[p]);
			else
				printf("%d ",a[p]);
		}
		printf("\n");
	}
	return 0;
}
