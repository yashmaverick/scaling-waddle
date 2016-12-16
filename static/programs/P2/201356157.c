#include<stdio.h>
int main()
{
	int i,t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int p,q,r;
		scanf("%d  ",&p);
		long int a[p];
		int j,k;
		long int cnt=0;
		for(j=0;j<p;j++)
		{
			scanf("%ld",&a[j]);
		}
		scanf("%d  ",&q);
		long int b[q];
		long int bc[q];
		long int cb[q];
		for(j=0;j<q;j++)
		{
			scanf("%ld",&b[j]);
			bc[j]=0;
			cb[j]=0;
		}
		scanf("%d  ",&r);
		long int c[r];
		for(j=0;j<r;j++)
		{
			scanf("%ld",&c[j]);
		}
		int z=r-1;
		for(j=q-1;j>=0;j--)
		{
			for(k=z;k>=j;k--)
			{
				if(b[j]>c[k])
				{
					bc[j]=r-k-1;
					z=k;
					break;
				}
				if(k==j)
				{
					bc[j]=r-j;
					z=j;
					break;
				}

			}
		}
		cb[q-1]=bc[q-1];
		for(j=q-2;j>=0;j--)
		{
			cb[j]=bc[j]+cb[j+1];
		}
		z=q-1;
		for(j=p-1;j>=0;j--)
		{
			for(k=z;k>=j;k--)
			{
				if(a[j]>b[k])
				{
					if(k<q-1)
						cnt=cnt+cb[k+1];
					else
						cnt=cnt;
					z=k;
					break;
				}
				if(k==j)
				{
					cnt=cnt+cb[j];
					z=j;
					break;
				}		
			}
		}
		printf("%ld\n",cnt);
	}
	return 0;
}
