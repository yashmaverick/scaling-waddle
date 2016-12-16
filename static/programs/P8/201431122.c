#include<stdio.h>
#include<math.h>
long long int ul,n;
long long int sol(int i)
{
	if(ul>=i)
	{
	long long int result = (ul-i)/n;
//	result++;
	//if(ul%n>0) 
	result++;
	return result;
	}
	else
		return 0;
}
long long int po(long long int a,long long int b)
{
	long long int p=1;
	while(b>0)
	{
		if(b&1)
			p=(p*a)%n;
		a=(a*a)%n;
		b=b/2;
	
	}
	return p;
}




int main()
{
	long long int y,d,m,te,a[41],sum;
	int i,j,k;
	scanf("%lld",&te);
	while(te--)
	{
		sum=0;
		scanf("%lld%lld%lld%lld",&ul,&d,&m,&n);
		a[0]=(d==0)?1:0;
		for(y=1;y<n;y++)
		{
			a[y]=po(y,d);
			a[y]=a[y]%n;
//			printf("i %lld a %lld\n",y,a[y]);
		}

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
				{
					if(((a[i]%n+a[j]%n)%n+a[k]%n)%n==m%n)
					{
						sum = (sum +((sol(i)*sol(j)%1000000007)*sol(k))%1000000007)%1000000007;
					}
				}
		printf("%lld\n",sum);
	}
	return 0;
}
