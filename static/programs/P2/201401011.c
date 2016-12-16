#include<stdio.h>

int main()
{
	long long int T;
	scanf("%lld",&T);

	while(T--)
	{
	   long long int p,q,r,a[100001],b[100001],c[100001],i,j,k,sum,d[100001];
		for(i=0;i<100001;i++)
			a[i]=b[i]=c[i]=d[i]=0;

		scanf("%lld",&p);
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);	
		scanf("%lld",&q);
		for(i=0;i<q;i++)
		{
			scanf("%lld",&b[i]);
		}
		scanf("%lld",&r);
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);
		
		if(q>r)
			q=r;
		if(p>q)
			p=q;
		k=0;
		for(j=0;j<q;j++)
		{	
			if(k < j)
				k = j;
			while((k < r) && (c[k] < b[j]) )
			{
			//	printf("%d%d%d",c[k],b[j],k);
				k++;
			}
			d[j] = r - k ;
		//	printf("d[%d]=%d",j,d[j]);
		}
		
		for(j=q-1;j>0;j--)
			d[j-1] += d[j];
		
		sum=j=0;
		for(i=0;i<p;i++)
		{
			if(j < i)
				j = i;
			while( j<q && (b[j] < a[i] ) )
				j++;
		//	printf("d[%d]=%d",j,d[j]);
			sum += d[j];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
