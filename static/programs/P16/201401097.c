#include<stdio.h>
int main()
{
	long long int i,n,j,k,l,pow=1,a,mid;
        scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		k=-1;
		pow=1;
		scanf("%lld",&a);
		while(a>=pow)
		{
			pow=pow*2;
			k++;


		}
		mid=(pow-(pow/2))/2;
		if(a<((pow/2)+mid))
			printf("%lld\n",(2*k)-1);
		else
			printf("%lld\n",2*k);
		
	}
		return 0;

}
