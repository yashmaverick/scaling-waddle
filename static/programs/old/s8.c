#include<stdio.h>
void merge(long long int a[],long long int beg,long long int mid,long long int end)
{
	long long int n1,n2,i,j,k;
	n1=mid-beg+1;
	n2=end-mid;
	long long int l[n1],r[n2];
	for(i=0;i<n1;i++)
		l[i]=a[beg+i];
	for(i=0;i<n2;i++)
		r[i]=a[mid+1+i];
	i=0;
	j=0;
	k=beg;
	while(i<n1 && j<n2)
	{
		if(l[i]<r[j])
			a[k++]=l[i++];
		else
			a[k++]=r[j++];
	}
	while(i<n1)
		a[k++]=l[i++];
	while(j<n2)
		a[k++]=r[j++];
	return;	
}
void sort(long long int a[],long long int beg,long long int end)
{
	if(beg<end)
	{
		long long int mid=beg+(end-beg)/2;
		sort(a,beg,mid);
		sort(a,mid+1,end);
		merge(a,beg,mid,end);
	}
	return;
}

int main()
{
	long long int k,count=0,n,a[1000005],i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	scanf("%lld",&k);
	sort(a,0,n-1);
//	for(i=0;i<n;i++)
//		printf("%lld ",a[i]);
	for(i=1;i<n;i++)
	{
		count=count+(i*(a[i]-a[i-1]));
		if(count>k)
			break;
	}
	if(i!=n)
	{
		count=count-(i*(a[i]-a[i-1]));
		printf("%lld\n",(k-count)/i+a[i-1]);
	}
	else
		printf("%lld\n",(k-count)/n+a[n-1]);
	return 0;
}
