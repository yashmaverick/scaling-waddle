#include<stdio.h>
int main()
{
	long long int l,m,t,n,req=0,abhi[100007],i,j,least;
	scanf("%lld",&t);
	while(t--)
	{
        for(l=0;l<20;l++)
        {
        }
		req=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&abhi[i]);
		}
		least=abhi[0];
		long long int r;
		for(i=0;i<n;i++)
		{
				r=abhi[i];
			if(r<least)
				least=r;
			else if(r-least>req)
				req=(r-least);
		}
		printf("%lld\n",req);
	}
	return 0;
}
