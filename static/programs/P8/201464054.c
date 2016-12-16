#include<stdio.h>
long long int power_div_and_conquer(long long int x,long long int power,long long int n, long long int m)
{
	long long int divide,ans,temp;
//	if (x==1)
//		return 1%n;
	if (power==0)
		return (1%n);		//will %n be here
	else if (power==1)
		return (x%n);
	else
	{
		divide=power/2;
		temp=power_div_and_conquer(x,divide,n,m);
		ans=(((temp)*(temp%n))%n);
		if (power%2==0)
			return ans;
		else if (power%2==1)
			return ((ans*(x%n))%n);
	}
}
int main()
{
	long long int ul,d,a[100],t,m,n,ct,i,j,k,i2,j2,k2;	//array a storing power%n values
//	unsigned long long int raj,ma=1000000001;
//	raj=ma*ma*ma;
//	printf ("%llu\n",raj);
	scanf ("%lld",&t);
	//printf ("power func test = %lld\n",power_div_and_conquer(2,8,1000000007,1000000007));
	while (t--)
	{
		scanf ("%lld %lld %lld %lld",&ul,&d,&m,&n);
//		printf ("n = %lld\n",n);
		ct=0;
		for (i=0;i<n;i++)
		{
		//	a[i]=0;
//		printf ("dsfhdskfhdskfh\n");
		/*for (i=0;i<n;i++)
		{*/
	//		printf ("i= %lld\n sjkghkfjhgkfdhg\n",i);
			if (i>1)
				a[i]=power_div_and_conquer(i,d,n,m);//pow(i,d)%n function by divide and conquer
			else if (d==0 && i==0)//pow(0,0)=1
				a[0]=1;
			else if (i==0 && d!=0)
				a[0]=0;
			else if (i==1)
				a[1]=1;
		}
	//	for (i=0;i<n;i++)
	//		printf ("i = %lld val = %lld\n",i,a[i]);
	//					printf ("ul_mod_n = %lld\n",ul%n);
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				for (k=0;k<n;k++)
					if (((a[i]+a[j]+a[k])%n)==(m%n))
					{
						i2=(ul/n);j2=i2;k2=i2;
						if ((ul%n)>=i)
						{
	//						printf ("i2 increased ");
							i2++;
						}
						if ((ul%n)>=j)
						{
	//						printf ("j2 increased ");
							j2++;
						}
						if ((ul%n)>=k)
						{
	//						printf ("k2 increased ");
							k2++;
						}
//						printf ("%lld %lld %lld\n",i,j,k);
						ct+=((((((i2%1000000007)*j2)%1000000007)*k2)%1000000007)%1000000007);//do mod at each step to avoid possible overflow
						ct=ct%1000000007;
					}
		printf ("%lld\n",ct);
	}
	return 0;
}
