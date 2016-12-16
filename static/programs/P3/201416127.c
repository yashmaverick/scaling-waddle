#include<stdio.h>
int main()
{
	int i,j,k,t,max;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int a[n],b[n],c[n];
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
			b[j]=a[j];
		}
		j=0;k=n-1;
		while(j!=n)
		{
			if(a[j]<a[j+1])
				a[j+1]=a[j];
			if(b[k]>b[k-1])
				b[k-1]=b[k];
			j++;
			k--;
		}
		max=0;
		for(j=0;j<n;j++)
		{
			c[j]=b[j]-a[j];
			if(c[j]>max)
				max=c[j];
		}
		printf("%d\n",max);
	}

		return 0;
}

