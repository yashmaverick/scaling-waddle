#include<stdio.h>
void merge(long long int a[],long long int l1,long long int r1,long long int l2,long long int r2)
{
	long long int i,j,k,l,t[1000005];
	k=0;
	i=l1;
	
	while((l1<=r1)&&(l2<=r2))
		{
			if(a[l1]<a[l2])
				t[k++]=a[l1++];
			else
				t[k++]=a[l2++];
	}
	while(l1<=r1)
		{
			t[k++]=a[l1++];
	}
	while(l2<=r2)
	{
		t[k++]=a[l2++];
	}
	k=0;
	for(;i<=r2;i++)
	{

		a[i]=t[k++];
	
	}


	return;
	



}
void msort(long long int a[],long long int l,long long int r)
{
	long long int mid;
	
	if(l<r)
	{
	

	
	mid=(r+l)/2;

msort(a,l,mid);
	msort(a,mid+1,r);
	merge (a,l,mid,mid+1,r);
	}
return;

}
int main ()
{
	long long int i,count=0,tsum=0,j,k,l,m,n,a[1000005];
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(j=0;j<k;j++)
		scanf("%lld",&a[j]);	
		tsum=0;
		count=0;
           	msort(a,0,k-1);
		for(j=0;j<k;j++)
		{
			count=count+1;
			if(a[j]!=a[j+1])
			{
				tsum=tsum+(count*(count-1))/2;
				count=0;

			}
		}
		printf("%lld\n",tsum);


	}

//	for(i=0;i<n;i++)
//		cout<<a[i];
	return 0;
}
