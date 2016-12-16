#include<stdio.h>
void merg( long long int a[],long long int s,long long int e)
{
	if(s==e)
		return;
	long long int mid = (s+e)/2;
	long long int t1=s;
	long long int t2 = (s+e)/2+1;
	merg(a,s,mid);
	merg(a,t2,e);
	long long int temp[1000000],t=0;
	while(t1<=mid || t2<=e)
	{
		if(t1>mid)
			temp[t++] = a[t2++];
		else if(t2>e)
			temp[t++] = a[t1++];
		else
		{
			if(a[t1]<a[t2])
				temp[t++] = a[t1++];
			else
				temp[t++] = a[t2++];
		}
	}
	long long int i;
	for(i=0;i<t;i++)
		a[s+i]=temp[i];
}

int main()
{
	long long int t,a[10000000],p,sum,i,nc,n,np;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		merg(a,0,n-1);
		np=a[0];
		p=1;
		sum=0;
		for(i=1;i<n;i++)
		{
			if(a[i]==np)
			{
				p++;
				np=a[i];
//				printf("p %lld\n",p);
			}
			else
			{
				sum += (p*(p-1)/2);
				p=1;
				np=a[i];
			}
		}
		sum += (p*(p-1)/2);
		printf("%lld\n",sum);
	}






	return 0;
}
