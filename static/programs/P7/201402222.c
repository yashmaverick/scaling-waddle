#include<stdio.h>
void merge(long long int L[],long long int R[],long long int A[],long long int n)
{
	long long int i=0,j=0,k=0,nl,nr,mid=n/2;
	nl=mid;
	nr=(n-mid);
	while(i<nl && j<nr)
	{
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		A[k]=L[i];
		i++;
		k++;
	}
	while(j<nr)
	{
		A[k]=R[j];
		j++;
		k++;
	}
}
void mergesort(long long int A[],long long int n)
{

	if(n<2)
		return;

	long long int mid=n/2;
	long long int L[mid],R[n-mid],i,j;
	for(i=0;i<mid;i++)
	{
		L[i]=A[i];
	}
	for(i=mid;i<n;i++)
	{
		R[i-mid]=A[i];
	}
	mergesort(L,mid);
	mergesort( R,(n-mid));
	merge(L,R,A,n);
}
long long int A[10000001],b[10000001];
int main()
{
	int t;

	long long int y,s, n,i,k,max;
	scanf("%d",&t);
	while(t--)
	{
		s=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&A[i]);
		}
		mergesort(A,n);
		k=A[n-1]-A[0]+1;
		for(i=0;i<k;i++)	
			b[i]=0;
		max=A[n-1];
		for(i=0;i<n;i++)
			b[max-A[i]]=b[max-A[i]]+1;
		for(i=0;i<(A[n-1]-A[0]+1);i++)
		{
			y=(b[i]*(b[i]-1))/2;
			s=s+y;
		}
		printf("%lld\n",s);
	}
	return 0;
}





