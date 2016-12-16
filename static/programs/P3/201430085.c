#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d",&x);
	for(y=0;y<x;y++)
	{
		long long int n,i,a[100001],m,p;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		m=a[0];
		p=a[1]-a[0];
		//printf("m=%lld ",m);
		for(i=1;i<(n-1);i++)
		{
			if(a[i]<m)
				m=a[i];
			if((a[i+1]-m)>p)
				p=a[i+1]-m;
		}
		if(p>0)
			printf("%lld\n",p);
		else
			printf("0\n");
	}
	return 0;
}
