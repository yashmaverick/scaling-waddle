#include<stdio.h>
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int p,q,r,i,j;
		scanf("%lld",&p);
		long long int a[p];
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		long long int b[q];
		for(i=0;i<q;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&r);
		long long int c[r];
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);
		long long int x,y,z,count[100000]={0};
		long long int co=0;
		y=q-1,z=r-1;
		while(y>=0 && z>=0)
		{
			if(z<y)
				y--;
			else if(c[z]>=b[y])
			{
				z--;
				if(z<y || c[z]<b[y])
				{
					count[y]=r-z-1;
					z++;
					y--;
				}
			}
			else if(c[z]<b[y])
				y--;
//			printf("%lld %lld\n",y,z);
		}
//		for(i=0;i<q;i++)
//			printf("%lld ",count[i]);
//		printf("\n");
		for(i=q-2;i>=0;i--)
			count[i]+=count[i+1];
//		for(i=0;i<q;i++)
//			printf("%lld ",count[i]);
//		printf("\n");
		y=p-1,z=q-1;
		while(y>=0 && z>=0)
		{
//			printf("%lld %lld\n",y,z);
			if(z<y)
				y--;
			else if(b[z]>=a[y])
			{
				z--;
				if(z<y || b[z]<a[y])
				{
					co+=count[z+1];
					z++;
					y--;
				}
			}
			else if(b[z]<a[y])
				y--;
		}
		printf("%lld\n",co);
	}
	return 0;
}
