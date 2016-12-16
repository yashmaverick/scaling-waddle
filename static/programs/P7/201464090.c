#include<stdio.h>
long long int tmp[1000000],b[1000000]={1};
void mergesort(long long int a[],long long int s,long long int e)
{
	if(s==e)
		return ;
	long long int mid=(s+e)/2;
	mergesort(a,s,mid);
	mergesort(a,mid+1,e);
	long long int i=s,j=(mid+1),k=0,p;
	while(i<=mid || j<=e)
	{
		if(i>mid)
		{
			tmp[k++]=a[j++];
		}
		else if(j>e)
		{
			tmp[k++]=a[i++];
		}
		else
		{
			if(a[i]<a[j])
				tmp[k++]=a[i++];
			else
				tmp[k++]=a[j++];
		}
	}
	for(p=0;p<k;p++)
		a[s+p]=tmp[p];
}
int main()
{

	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a[1000000],n,e=0,d=1,i,l,h=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		mergesort(a,0,n-1);
		for(i=0;i<n;i++)
		{
			b[i]=1;
		}
		for(i=0;i<(n-1);i++)
		{
				if(a[i]!=a[i+1])
				{  
					b[e]=d;
					e++;
					d=1;
				}
				if(a[i]==a[i+1])
					d++;
		}
		if(e==0)
			b[0]=d;
		for(i=0;i<=e;i++)
		{
			l=((b[i])*(b[i]-1))/2;
			h=h+l;
		}
		printf("%lld\n",h);	
	}
	return 0;
}

