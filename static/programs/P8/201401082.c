#include<stdio.h>
#define max 1000000007
unsigned long long int n;
unsigned long long int prod( unsigned long long int a, unsigned long long int b)
{
	unsigned long long int x,d;
	if(a==0)
	{
		if(b==0)
			return 1%n;
		else
			return 0;


	}
	else if(a==1)
		return 1%n;
	else if(b==0)
		 return 1%n;
	else if(b==1)
		return a%n;
	else
	{
		d=prod(a,b/2);
		x=((d%n)*(d%n))%n;
		if(b%2==0)
			return x;
		else
			return (x*(a%n))%n;
	}
}
int main()
{
	unsigned long long int t,u,d,i,a[100],j,k,p,q,r,sum,m,grg,rac;
	scanf("%llu",&t);
	while(t--)
	{
		scanf("%llu%llu%llu%llu",&u,&d,&m,&n);
	
		
		for(i=0;i<n;i++)
			a[i]=prod(i,d);
		/*for(i=0;i<n;i++)
			printf("%llu ",a[i]);
		printf("\n");*/
		sum=0;
		/*for(i=0;i<=g;i++)
			printf("%llu ",a[i]);
		printf("\n");*/
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if((a[i]+a[j]+a[k])%n==m)
					{
						grg=u%n;
						rac=u/n;
						if(i<= grg  )
							p=rac+1;
						else
							p=rac;						
						if( j<=grg)
							q=rac+1;
						else
							q=rac;
						if(k<= grg)
							r=rac+1;
						else
							r=rac;
						//printf("%llu %llu %llu",p,q,r);
						//printf("\n");
						sum=(sum+((((p%max)*(q%max))%max)*(r%max))%max)%max;
					}

		printf("%llu\n",sum);
	}
	return 0;
}
