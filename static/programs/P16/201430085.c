#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		long long int q,c=0,f=0,ans;
		scanf("%lld",&q);
		while(q>1)
		{
			if(q==2)
				f=1;
			c++;
			q=q/2;
		}
		if(f==1)
			ans=2*c-1;
		else
			ans=2*c;
		printf("%lld\n",ans);
	}
	return 0;
}
