#include<stdio.h>
#include<math.h>
long long int power(long long int b, long long int e)
{
	long long int r=1;
	while(e)
	{
		if(e&1)
			r*=b;
		e>>=1;
		b=b*b;
	}
	return r;
}
int main()
{
	long long int t,i,j,num,k,n,flag=0,r,p,q,A[100],f=0;
	for(i=0;i<32;i++)
		A[i]=power(2,i);
	scanf("%lld",&t);
	for(j=0;j<t;j++)
	{
		scanf("%lld",&n);
		if(n==1)
		{
			printf("0\n");
			f=1;
		}
		else
		{
			for(i=0;i<35;i++)
				if(n==A[i])
				{
					printf("%lld\n",2*i-1);
					f=1;
				}
		}
		if(f==0)
		{
			k=0;
			num=0;
			num=num+A[k];
			while(num<=n)
			{
				if(num==n)
				{
					printf("%lld\n",2*k);
					flag=1;
				}
				else
					k++;
				num=num+A[k];
			}
			p=A[k];
			q=A[k-1];
			num=num-p;
			if(flag==0)
			{
				if(n-num>q)
					printf("%lld\n",2*k);
				else
					printf("%lld\n",2*k-1);
			}
		}
		flag=0;
		f=0;

	}
	return 0;
}
