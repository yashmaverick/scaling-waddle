#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int p;
		scanf("%d",&p);
		int a[p],i;
		for(i=0;i<p;i++)
			scanf("%d",&a[i]);
		int q;
		scanf("%d",&q);
		int b[q];
		for(i=0;i<q;i++)
			scanf("%d",&b[i]);
		int r,j;
		scanf("%d",&r);
		int c[r];
		for(i=0;i<r;i++)
			scanf("%d",&c[i]);
		
		long long int d[q],k=0,l=0;
		for(i=0;i<q;i++)
			d[i]=0;
		for(i=0;i<q;i++) 
		{
			for(j=l;j<r;j++)
			{
				if(c[j]>=b[i] && j>=i)
				{
					d[k]=r-j;
					k++;
					l=j;
					break;
				}
			}
		}
		k--;
		for(i=k-1;i>=0;i--)
			d[i]=d[i]+d[i+1];
		long long int sum=0;
		l=0;k=0;
		for(i=0;i<p;i++)
		{
			for(j=l;j<q;j++)
			{
				if(b[j]>=a[i] && j>=i)
				{
					l=j;
					sum=sum+d[j];
					//k++;
					break;
				}
			}
		}
		printf("%lld\n",sum);
		sum=0;
	}
	return 0;
}


