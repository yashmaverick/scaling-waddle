#include<stdio.h>
long long int expo(long long int a,long long int b,long long int m)
{
	long long int temp;
	if(b==0)
		return 1;
	if(b%2!=0)
	{
		temp=expo(a,b/2,m)%m;
		temp=(((temp*temp)%m)*a)%m;
		return temp;
	}
	else
	{
		temp=expo(a,b/2,m)%m;
		temp=(temp*temp)%m;
		return temp;
	}
}

int main()
{
	long long int ucount,i,j,l,m,q,n,x,y,u,k,d,number=0,temp=0,count=0,rtemp=0,remcount=0,a[50];
	long long int b,c,mod=1000000007;
	scanf("%lld",&k);
	for(i=0;i<k;i++)
	{
		remcount=0;

		rtemp=0;
		temp=0;
		count=0;
		scanf("%lld%lld%lld%lld",&u,&d,&m,&n);
		ucount=u%n;
		
		for(j=0;j<n;j++)
			a[j]=(u/n)%mod;
		
		for(j=0;j<=ucount;j++)
		{
			a[j]=(a[j]+1)%mod;
		}
		q=n;

		if(u<n)
			q=u+1;


		for(j=0;j<q;j++)
		{
			for(x=0;x<q;x++)
			{
				for(y=0;y<q;y++)
				{
					temp=((expo(x,d,n)+expo(j,d,n))%n+expo(y,d,n))%n;
					if (temp==m)
					{

					//	if((j<=ucount)&&(x<=ucount)&&(y<=ucount))
					//		remcount++;
                                                count=(count+(((a[x]*a[y])%mod)*a[j])%mod)%mod;

						
					}


				}
			}
		}

	//	if(u<n)
	//	{

	//		printf("%lld\n",remcount);
	//	}
	//	else
	//	{
		//	rtemp=u/n;
		//	count=count+rtemp;// doubt
			//	if(u%n!=0)
	//				count=count+remcount;

			printf("%lld\n",count);
	//	}

	}
	return 0;
}
