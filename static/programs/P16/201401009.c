#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n,e;
	long long int a[40];
	for(e=0;e<40;e++)
		a[e]=pow(2,e);
	scanf("%d",&n);
	while(n--)
	{
		long long int q,k,i,j,m,flag=0,w,state=0;
		scanf("%lld",&q);
		w=2*q/3;
	//	printf("%lld\n",w);
		for(i=0;i<40;i++)
		{
			j=a[i];
			if(q==0 && !state)
			{
				k=i;
				state=1;
			}
			if(j<q && j*2>q && !state)
			{
				k=i;
				state=1;
			}
			if(j==q && !state)
			{
				k=i;
				state=1;
			}
			if(w==0 && !flag)
			{
				m=0;
				flag=1;
			}
			if(j<w && j*2>w && !flag)
			{
				m=i;
				flag=1;
			}
			if(j==w && !flag)
			{
				m=i;
				flag=1;
			}
			if(state==1 && flag==1)
				break;
		}
	//	printf("%lld %lld\n",k,m);
		printf("%lld\n",k+m);
	}
	return 0;
}
