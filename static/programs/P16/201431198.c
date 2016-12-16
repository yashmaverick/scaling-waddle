#include <stdio.h>
#include <math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int q,i=0,a=0,diff=0;
		scanf("%lld",&q);
		for(i=0;a<=q;i++)
			a=pow(2,i);
		//printf("%lld\n",a);
		if(q==1)
			printf("0\n");
		else
		{
			//printf("%lld\n",i);
			diff=a-q;
			if(diff<=a/4)
				printf("%lld\n",2*(i-2));
			else
				printf("%lld\n",(2*(i-2))-1);
		}
	}
	return 0;
}