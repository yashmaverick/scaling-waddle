#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		long long int a[100001],max=0,maxd=0,diff=0;
                int na,i,j,k;
		scanf("%d",&na);
		for(i=0;i<na;i++)
		{
		  scanf("%lld",&a[i]);
                }
                max=a[na-1];
                for(i=na-1;i>=0;i--)
                {
                  diff=max-a[i];
                  if(max<a[i])
	            max=a[i];
               
                  if(maxd<diff)
                    maxd=diff;
		}
		printf("%lld\n",maxd);
                maxd=0;
                max=0;
	}
	return 0;
}
