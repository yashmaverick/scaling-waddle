#include<stdio.h>
int main ()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		long int a[n],b[n],c[n],ans=0;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		b[0]=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]<b[i-1])
				b[i]=a[i];
			else
				b[i]=b[i-1];
			c[i]=0;
		}
		c[n-1]=a[n-1];
		for(i=n-2;i>=0;i--)
		{
			if(a[i]>c[i+1])
				c[i]=a[i];
			else
				c[i]=a[i+1];
		}
		for(i=0;i<n;i++)
		{
			if(c[i]-b[i]>ans)
				ans=c[i]-b[i];
		}
		printf("%d\n",ans);
	}
return 0;
}

