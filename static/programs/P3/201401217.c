#include<stdio.h>
int main()
{
	int t,x,n;
	scanf("%d",&t);
	for(x=0;x<t;x++)
	{
		int y,max;
		scanf("%d",&n);
		int a[n],b[n];
		for(y=0;y<n;y++)
		{
			scanf("%d",&a[y]);
			b[y]=a[y];
		}
		for(y=0;y<n;y++)
		{
			if(a[y]<a[y+1])
				a[y+1]=a[y];
		}
		for(y=n-1;y>=0;y--)
		{
			if(b[y]>b[y-1])
				b[y-1]=b[y];
		}
		for(y=0;y<n;y++)
		{
			b[y]=b[y]-a[y];
		}
		max=0;
		for(y=0;y<n;y++)
		{
			if(b[y]>max)
				max=b[y];
		}
		printf("%d\n",max);
	}
	return 0;
}
