#include<stdio.h>
int main()
{
	long long int N,i,j;
	long long int Q,ans,p,q;
	scanf("%lld",&N);
	while(N>0)
	{
		scanf("%lld",&Q);
		if(Q==1 || Q==0)
			ans=0;
		else if(Q==2)
			ans=1;
		else
		{
			p=2;j=0;q=3;
			while(p<=Q)
			{
				p=p*2;
				q=q*2;
				j++;
			}
			p=p/2;
			q=q/2;
			if(Q<q)
				ans=2*j-1;
			else
				ans=2*j;
			//printf("j:%lld p:%lld q:%lld\n",j,p,q);
		}
		printf("%lld\n",ans);
		N--;
	}
	return 0;
}
