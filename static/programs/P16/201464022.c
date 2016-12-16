#include<stdio.h>
#include<math.h>
int main()
{
	long long int t,n,powercount,ans,temp;
	scanf("%lld",&t);
	while(t--)
	{
		powercount=0;
		scanf("%lld",&n);
		temp=n;
		while((temp)>=2)
		{
			//powercount=0;
			temp=temp/2;
			powercount++;
		}
	//	printf("powercount =%d\n",powercount);
		if(n+1-pow(2,powercount)>pow(2,powercount-1))
		{
			ans=2*powercount;
		}
		else ans=(2*powercount)-1;
		printf("%lld\n",ans);
	}
	return 0;
}
				




