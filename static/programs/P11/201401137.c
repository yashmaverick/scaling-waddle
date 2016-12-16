#include<stdio.h>
long long int poi=-1;

void push(long long int a[],long long int i,long long int value)
{
	poi++;
	a[poi]=i;
	poi++;
	a[poi]=value;
}

void pop(long long int a[])
{
	poi=poi-2;
}

int main()
{
	while(1)
	{
		long long int n,i,j;
		poi=-1;
		scanf("%lld",&n);
		if(n==0)
			break;
		long long int a[2*n],b[n],c[n],d[n];
		for(i=0;i<n;i++)
			scanf("%lld",&b[i]);
		for(i=0;i<n;i++)
		{
			while(poi>=1)
			{
				if(a[poi]>=b[i])
				{
					pop(a);
				}
				else
					break;
			}
			push(a,i,b[i]);
			if(poi==1)
				c[i]=-1;
			else
				c[i]=a[poi-3];
//			for(j=0;j<=poi;j++)
//				printf("%d ",a[j]);
//			printf("\n");
		}
//		for(i=0;i<n;i++)
//		{
//			printf("%d ",c[i]);
//		}
//		printf("\n");
		poi=-1;
		for(i=n-1;i>=0;i--)
		{
			while(poi>=1)
			{
				if(a[poi]>=b[i])
				{
					pop(a);
				}
				else
					break;
			}
			push(a,i,b[i]);
			if(poi==1)
				d[i]=n;
			else
				d[i]=a[poi-3];
//			for(j=0;j<=poi;j++)
//				printf("%d ",a[j]);
//			printf("\n");
		}
//		for(i=0;i<n;i++)
//		{
//			printf("%d ",d[i]);
//		}
//		printf("\n");
		long long int max,temp;
		max=(d[0]-c[0]-1)*b[0];
		for(i=1;i<n;i++)
		{
			temp=(d[i]-c[i]-1)*b[i];
			if(temp>max)
				max=temp;
		}
		printf("%lld\n",max);
	}
	return 0;
}




