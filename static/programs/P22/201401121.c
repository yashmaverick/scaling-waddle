#include<stdio.h>
#define mod 1000000007
long long int a[200005];
long long int b[200005];
long long int size1=0;
long long int size2=0;
long long int min(long long int a,long long int b,long long int i)
{
	if(a>b)
		return 2*i+1;
	return 2*i;
}
long long int max(long long int a,long long int b,long long int i)
{
	if(a>b)
		return 2*i;
	return 2*i+1;
}
void minheapify(long long int i)
{
	if(i>size1/2)
		return ;
	long long int ind;
	if(2*i==size1)
		ind=2*i;
	else ind=min(a[2*i],a[2*i+1],i);
	if(a[i]>=a[ind])
	{
		long long int t=a[i];
		a[i]=a[ind];
		a[ind]=t;
		minheapify(ind);
	}
}
void maxheapify(long long int i)
{
	if(i>size2/2)
		return ;
	long long int ind;
	if(2*i==size2)
		ind=2*i;
	else ind=max(b[2*i],b[2*i+1],i);
	if(b[i]<=b[ind])
	{
		long long int t=b[i];
		b[i]=b[ind];
		b[ind]=t;
		maxheapify(ind);
	}
}
void deletemin()
{

	long long int t=a[1];
	a[1]=a[size1];
	a[size1]=t;
	size1--;
	minheapify(1);
}
void deletemax()
{
	long long int t=b[1];
	b[1]=b[size2];
	b[size2]=t;
	size2--;
	maxheapify(1);
}
void insertmin(long long int val)
{
	long long int i=size1+1;
	while(i>1 && a[i/2] >=val)
	{
		a[i]=a[i/2];
		i/=2;
	}
	a[i]=val;
	size1++;
}
void insertmax(long long int val)
{
	long long int i=size2+1;
	while(i>1 && b[i/2] <=val)
	{
		b[i]=b[i/2];
		i/=2;
	}
	b[i]=val;
	size2++;
}
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int p,q,r,n;
		scanf("%lld%lld%lld%lld",&p,&q,&r,&n);
		long long int s=1;
		insertmax(s);
		long long int i=2;
		long long int sum=1;
		for(;i<=n;i++)
		{
			long long int l=b[1];
			s=((p%mod)*(l%mod))%mod+((q%mod)*(i%mod))%mod+r;
			s%=mod;
			sum=sum+s;
			if(size2>size1)
			{
				if(s>=l)
				{
					insertmin(s);
				}
				else
				{
					insertmax(s);
					insertmin(b[1]);
					deletemax();
				}
			}
			else
			{
				if(s<=l)
				{
					insertmax(s);
				}
				else
				{
					insertmin(s);
					insertmax(a[1]);
					deletemin();
				}
			}
		}
	
		
		printf("%lld\n",sum);
		size1=0;
		size2=0;
		
	}
	return 0;
}

			


	


