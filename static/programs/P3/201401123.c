#include<stdio.h>
#define s(n) scanf("%d",&n) 

int main()
{
	int N,NA,i;
	long long int a[100001],minterm,maxdiff;
	s(N);
	while(N--)
	{
		s(NA);
		for(i=0;i<NA;i++)
			scanf("%lld",&a[i]);
		if(NA>1)
		{
			maxdiff=a[1]-a[0];
			minterm=a[0];
			for(i=1;i<NA;i++)
			{
				if( (a[i]-minterm) > maxdiff ) 
					maxdiff=a[i]-minterm;
				if(a[i] < minterm)
					minterm = a[i];							
			}
			if(maxdiff<0)
				maxdiff=0;

			printf("%lld\n",maxdiff);
		}
		else{
			int p=0;
			printf("%d\n",p);
		}
	}
	return 0;
}
