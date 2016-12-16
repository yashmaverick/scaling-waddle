#include<stdio.h>
int main()
{
	long long int a[100000],b[100000],c[100000],d[100000],i,j,k,l,m,n,o,p;
	scanf("%lld",&n);
	i=0;
	while(i<n)
	{
		scanf("%lld",&a[i]);
		i++;
	}
	i=0;
	while(i<n)
	{
		scanf("%lld",&b[i]);
		i++;
	}
	i=0;
	j=0;
	while(i<n)
	{
		j=0;
		while(j<n)
		{
			if(b[i]==a[j])
			{
				c[j]=i;
				break;
			}
			j++;
		}
		d[a[i]]=i;

		i++;
	}
	/*i=0;
	  while(i<n)
	  {
	  printf("%lld ",c[i]);
	  i++;
	  }*/
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld%lld",&k,&l);
		i=0;
		while(i<n)
		{
			if(b[i]==k)
			{
				o=i;
			}
			else if(b[i]==l)
			{
				p=i;
			}
			i++;
		}
		i=0;
		if(o>=p)
		{
			i=p;
			p=o;
			o=i;

		}
		i=0;
		while(i<n)
		{
		   if(c[i]<=p && c[i]>=o)
		   {
			   printf("%lld\n",b[c[i]]);
			   break;

		   }
		   i++;

		}

		//printf("%lld %lld\n",o,p);

	}

	return 0;
}
