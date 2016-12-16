#include<stdio.h>
int main()
{
	int t,n,i;
	long long int a[100000],s,min;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		min=a[0];
		s=0;
		for(i=1;i<n;i++)
		{
			if(min>a[i])
				min=a[i];
			if((a[i]-min)>s)
			{
				s=-1*(min-a[i]);
			}
		}
		printf("%lld\n",s);
	}
	return 0;
}
