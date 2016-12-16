#include<stdio.h>
int main()
{
		long long int t,size,sp[100000],i,j,mp=0,le;
		scanf("%lld",&t);
		for(i=0;i<t;i++)
		{
				scanf("%lld",&size);
				mp=0;
				for(j=0;j<size;j++)
				{
						scanf("%lld",&sp[j]);
						if(j==0)
								le=sp[j];
						if(le>sp[j])
								le=sp[j];
						if((sp[j]-le)>mp)
								mp=sp[j]-le;
				}
				printf("%lld\n",mp);
		}
		return 0;
}
