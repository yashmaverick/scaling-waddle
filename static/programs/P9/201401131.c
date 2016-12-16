#include<stdio.h>
typedef long long int ll;
int main()
{
	ll n,mod,m,temp,temp1,c,i,j,k,r;
	scanf("%lld%lld",&n,&mod);
	ll a[1000000];
	ll b[n][2];
	ll sum=0,sum1=0;
	j=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&m);
		a[j]=m;
		sum=0;
		b[i][0]=j;
		k=0;
		while(k != m)
		{	
			j=j+1;
			scanf("%lld",&a[j]);
			sum=(sum+a[j])%mod;
			k=k+1;	
		}
		b[i][1]=sum;
		j=j+1;
	}
	i=0;
	for(j=0;j<n;j++)
	{
		for(k=j+1;k<n;k++)
		{
			if(b[j][1] > b[k][1])
			{
				temp=b[j][1];
				b[j][1]=b[k][1];
				b[k][1]=temp;
				temp1=b[j][0];
				b[j][0]=b[k][0];
				b[k][0]=temp1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
	
		printf("%lld\n",b[i][1]);
		c=b[i][0]+1;
		sum1=0;
		while(sum1!=b[i][1])
		{
			printf("%lld\n",a[c]);
			sum1=(sum1+a[c])%mod;
			c=c+1;
		}
		printf("\n");
	}
	return 0;
}
