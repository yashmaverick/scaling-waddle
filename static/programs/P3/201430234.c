#include<stdio.h>
int main()
{
	int i,j,k,l,max,w,n,a[100001],b[100001],c[100001];
	scanf("%d",&w);
	while(w--)
	{
		int max=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		b[0]=a[0];
		for(i=0;i<n;i++)
		{
			if(b[i]<a[i+1])
				b[i+1]=a[i];
			else
				b[i+1]=a[i+1];
		}
			c[n-1]=a[n-1];
		for(j=n-1;j>=0;j--)
		{
			if(c[j]>a[j-1])
				c[j-1]=c[j];
			else
				c[j-1]=a[j-1];
			l=c[j]-b[j];
			if(max<l)
				max=l;
		}
		printf("%d\n",max);
	}
	return 0;
}



