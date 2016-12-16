#include<stdio.h>
#define mod 1000000007
void insert_min(long long int x,long long int a[],long long int last)
{
	if(last==0)
		a[0]=x;
	else
	{
		while(a[(last-1)/2]>x && last>0)
		{
			a[last]=a[(last-1)/2];
			last=(last-1)/2;
		}
		a[last]=x;
	}
	return;
}
void insert_max(long long int x,long long int a[],long long int last)
{
	if(last==0)
		a[0]=x;
	else
	{
		while(a[(last-1)/2]<x && last>0)
		{
			a[last]=a[(last-1)/2];
			last=(last-1)/2;
		}
		a[last]=x;
	}
	return;
}
void placeparent_max(long long int a[],long long int last,long long int r)
{
	long long int temp;
	while((a[r]<a[2*r+1] && (2*r+1)<last) || (a[r]<a[2*r+2] && (2*r+2)<last))
	{
		if(2*r+2<last && a[2*r+1]<a[2*r+2])
		{
			temp=a[2*r+2];
			a[2*r+2]=a[r];
			a[r]=temp;
			r=2*r+2;
		}
		else
		{
			temp=a[2*r+1];
			a[2*r+1]=a[r];
			a[r]=temp;
			r=2*r+1;
		}
	}
	return;
}
void placeparent_min(long long int a[],long long int last,long long int r)
{
	long long int temp;
	while((a[r]>a[2*r+1] && (2*r+1)<last) || (a[r]>a[2*r+2] && (2*r+2)<last))
	{
		if(2*r+2<last && a[2*r+1]>a[2*r+2])
		{
			temp=a[2*r+2];
			a[2*r+2]=a[r];
			a[r]=temp;
			r=2*r+2;
		}
		else
		{
			temp=a[2*r+1];
			a[2*r+1]=a[r];
			a[r]=temp;
			r=2*r+1;
		}
	}
	return;
}
void delete_max(long long int a[],long long int last)
{
	if(last==0)
		return;
	a[0]=a[last-1];
	placeparent_max(a,last-1,0);
	return;
}
void delete_min(long long int a[],long long int last)
{
	if(last==0)
		return;
	a[0]=a[last-1];
	placeparent_min(a,last-1,0);
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a,b,c,n,max[200001]={0},min[200001]={0},i,new,median=1,mal=0,mil=1,sum=1;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		min[0]=1;
		for(i=1;i<n;i++)
		{
			new=((((a*median)%mod+(b*i)%mod)%mod+b)%mod+c)%mod;
			if(i%2==1)
			{
				if(new>=max[0])
				{
					insert_min(new,min,mil);
					mil++;
				}
				else
				{
					insert_min(max[0],min,mil);
					delete_max(max,mal);
					insert_max(new,max,mal-1);
					mil++;
				}
			}
			else
			{
				if(new>min[0])
				{
					insert_max(min[0],max,mal);
					delete_min(min,mil);
					insert_min(new,min,mil-1);
					mal++;
				}
				else
				{
					insert_max(new,max,mal);
					mal++;
				}
			}
			median=min[0];
		//	printf("%lld %lld\n",new,median);
			sum+=new;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
