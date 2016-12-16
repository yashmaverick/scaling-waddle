#include<stdio.h>

int po(int a,int b)
{
	if(b==0)
		return 1;
	long long int c;
	c=po(a,b/2);
	if(b%2==1)
		return a*c*c;
	return c*c;
}
int main()
{
	long long int n,t,cnt,ans,temp;
	scanf("%lld",&n);
	while(n--)
	{
		cnt=0;
		scanf("%lld",&t);
		temp=t;
		while(t>2)
		{
			t=t/2;
			cnt++;
		}
		if(temp>(po(2,cnt+1)-1))
			ans=2*cnt+1;
		else
			ans=2*cnt;
		printf("%lld\n",ans);
	}
	return 0;
}
