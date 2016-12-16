#include<stdio.h>
#include<math.h>

int VikasgotPower(long long int Base,long long int Expo)
{
	long long int vikas=1;
	while(Expo!=0)
	{
		if(Expo & 1)
			vikas=vikas*Base;
		Expo>>=1;
		Base=Base*Base;
	}
	return vikas;
}

int main()
{
	int Test;
	scanf("%d",&Test);
	while(Test>0)
	{
		long long int Queries=0,logo=0,x=0;
		scanf("%lld",&Queries);
		if(Queries==1)
			printf("0\n");
		else
		{
			logo=log2(Queries);
			x=VikasgotPower(2,logo);
			if( Queries <= (2*x-1) && Queries >= (3*x)/2 )
				printf("%lld\n",logo*2);
			else if(Queries >= x && Queries <= (3*x)/2)
				printf("%lld\n",logo*2-1);
		}	

		Test--;
	}
	return 0;
}