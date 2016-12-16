#include<stdio.h>
int main()
{
	long long sol,p,q,r,a[100002],b[100002],c[100002],i,j,k,t;
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld",&p);
		for(i=0; i<p; i++)
		scanf("%lld", &a[i]);

		scanf("%lld",&q);
		for(i=0; i<q; i++)
		scanf("%lld", &b[i]);

		scanf("%lld",&r);
		for(i=0; i<r; i++)
		scanf("%lld",&c[i]);
			
		if(p>=q)
		p=q;
		if(q>=r)
		q=r;

		sol=i=k=0;
		for(j=0; j<q; j++)
		{
			while(a[i]<=b[j] && i<=j && i<p)
			i++;

			while(b[j]>c[k] &&  k<r)
			k++;
			if(j>=k)
			k=j;

			sol+=i*(r-k);
		}

		printf("%lld\n",sol);


	}
	return 0;
}
	
