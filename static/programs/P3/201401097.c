#include<stdio.h>
int main ()
{
	long long int i,t,j,n,k,a[100000],hp=0,nlowe=0;
        scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&t);
		for(j=0;j<t;j++)
		{
			scanf("%lld",&a[j]);
				
				}

                 hp=0;
		 nlowe=a[0];
           
		for(j=0;j<t;j++)
		{
			if(a[j]<nlowe)
			{
				nlowe=a[j];
			}
			else if((a[j]-nlowe)>hp)
			{
			
				hp=a[j]-nlowe;
			}

		}
		printf("%lld\n",hp);
	}
		return 0;
}
