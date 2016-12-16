#include<stdio.h>
int merge(long int A[],long int B[],long int c[],int m,int n)
{	int i=0,j=0,k=0;
	while(i<m&&j<n)
	{	if(A[i]>B[j])
		{	c[k]=B[j];
			j++;k++;}
			else if(A[i]==B[j])
			{	c[k]=A[i];k++;
				c[k]=A[i];k++;
				i++;
				j++;}
				else
				{	c[k]=A[i];
					i++;
					k++;}
	}
	if(j<n)
	{	while(j<n)
		{	c[k]=B[j];
			k++;
			j++;
		}
	}
	if(i<m)
	{	while(i<m)
		{
			c[k]=A[i];
			k++;
			i++;
		}
	} 

}
void mergesort(long int a[],int n)
{	int i;
	long int left[n];
	long int right[n];
	if(n<=1)
	{	return;}
	for(i=0;i<n/2;i++){
		left[i]=a[i];
	}
	for(i=n/2;i<n;i++)
	{	right[i-n/2]=a[i];}
	mergesort(left,n/2);
	mergesort(right,(n-n/2));
	merge(left,right,a,n/2,(n-n/2)); 
}
int main()
{
	int t;
	scanf("%d\n",&t);
	while(t--)
	{
		int i=0;
		int n;
		scanf("%d",&n);
		long int a[n];
		while(i<n)
		{
			scanf("%ld",&a[i]);
			i++;
		}
		mergesort(a,n);
		long long int pv=0;
		long long int co=0,ro;
		for(i=1;i<=n;i++)
		{
			if(i!=n)
				if(a[i]==a[pv])
					continue;
			ro=(i-pv)*(i-pv-1)/2;
			if(ro<0)
				ro=0;
			co+=ro;
			pv=i;
		}
		printf("%lld\n",co);
	}
	return 0;
}
