#include<stdio.h>
long long int power(int x , long long int y)
{
	if(y==0)
		return 1;

	else if(y%2==0)
		return power(x,y/2)*power(x,y/2);

	else
		return x* power(x,y/2)*power(x,y/2);
}

int main()
{
	long long int n,Q,ele;
	scanf("%lld",&n);

	long long int a[40];
	long long int i;
	long long int res,ans;
	a[0]=1;
	for(i=1;i<=40;i++)
	{
		res=power(2,i);
		a[i]=res;
	}
	while(n--)
	{
		scanf("%lld",&Q);
		for(i=0;i<=40;i++)
		{
			if(Q<a[i])
				break;
		}
		i=i-1;
		Q=Q-a[i];
		ele=a[i];

		if(Q>=(ele/2))
			ans=2*i;
		else
			ans=2*i-1;
		printf("%lld",ans);
		printf("\n");
	}
	return 0;
}

