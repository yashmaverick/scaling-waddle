#include<stdio.h>
#define s(n) scanf("%lld",&n)
typedef long long L;
L w(L a,L b);
int main()
{
	L t,n,i,ans;
	s(t);
	while(t--)
	{
		s(n);
		if(n==1)
			ans=0;
		else if(n==2)
			ans=1;
		else
		{
			L i = 2;
			ans = 0;
			while(i)
			{
				//			printf("%lld\n",w(2,i));
				if( n < w(2,i) && n >= w(2,i-1) )
				{
					if(n>=(w(2,i)-w(2,i-2)))
					{
						ans = 2*i-2;
						break;
					}
					else
					{
						ans=2*i-3;
						break;
					}
				}
				i++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
L w(L a, L b)
{
	if(b==0)
		return 1;
	L ans,i;
	ans=1;
	while(b--)
		ans=ans*a;

	return ans;
}
