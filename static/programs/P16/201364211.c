#include<stdio.h>
int main()
{
	long long int n,len,q,flag;
	scanf("%lld",&n);
	while(n--)
	{
		flag=0;
		len=0;
		scanf("%lld",&q);
		if(q==1)
		{
			printf("%lld\n",len);
			continue;
		}
		while(q!=1)
		{
			if(q==3)
			{
				flag=1;
			}
			q=q/2;
			len++;
		}
		len=2*len;
		if(flag==0)
		{
			len--;
		}
		printf("%lld\n",len);
	}
	return 0;
}
