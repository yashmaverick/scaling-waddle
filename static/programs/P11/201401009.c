#include<stdio.h>
#include<stdlib.h>
long long int *a,*c,*b,*s;
int main()
{
	long long int n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		long long int max=0,x=0,i,total;
		a=(long long int*)malloc((n+2)*sizeof(long long int));
		s=(long long int*)malloc((n+2)*sizeof(long long int));
		b=(long long int*)malloc((n+1)*sizeof(long long int));
		c=(long long int*)malloc((n+1)*sizeof(long long int));
		for(i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		a[0]=-1;
		a[n+1]=-1;
		s[0]=0;
		s[n+1]=0;
		for(i=1;i<=n;i++)
		{
			while(a[s[x]]>=a[i])
				x--;
			b[i]=s[x];
			x++;
			s[x]=i;
		}
		x=n+1;
		for(i=n;i>=1;i--)
		{
			while(a[s[x]]>=a[i])
				x++;
			if(s[x]!=0)
				c[i]=s[x];
			else
				c[i]=n+1;
			x--;
			s[x]=i;
		}
//		for(i=1;i<=n;i++)
//		{
//			printf("%lld %lld\n",b[i],c[i]);
//		}
		for(i=1;i<=n;i++)
		{
			total=c[i]-b[i]-1;
			if(total*a[i]>max)
				max=total*a[i];
		}
		printf("%lld\n",max);
	}
	return 0;
}



