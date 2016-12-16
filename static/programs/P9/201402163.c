#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int n,m,i,j,k,l,p,mod,*a[1001],b[1001],sum,c[1001],sort[1001],max;
	scanf("%lld%lld",&n,&mod);
        i=0;
	while(i<n)
	{
		scanf("%lld",&m);
		a[i]=malloc(m*sizeof(long long int));
		b[i]=m;
		j=0;
		max=0;
		while(j<m)
		{
			scanf("%lld",&a[i][j]);
			max=max+(a[i][j]);
		//	max=max%mod;
			j++;
		}
		max=max%mod;
		c[i]=max;
		i++;
	}
/*	i=0;
	while(i<n)
	{
		printf("*%lld\n",c[i]);
		i++;
	}*/
	i=0;
	while(i<n)
	{
		sort[i]=i;
		i++;
	}

	i=0;
	while(i<n)
	{
		l=i+1;
		while(l<n)
		{
			if(c[sort[i]]>c[sort[l]])
			{
				k=sort[i];
				sort[i]=sort[l];
				sort[l]=k;

			}
			l++;
		}
		i++;
	}
	i=0;
	while(i<n)
	{
		k=sort[i];
		printf("%lld\n",c[k]);
		p=b[k];
		l=0;
		while(l<p)
		{
			printf("%lld\n",a[k][l]);
			l++;
		}
//		if(i!=n-1)
		printf("\n");

		i++;
	}
	




	return 0;
}

