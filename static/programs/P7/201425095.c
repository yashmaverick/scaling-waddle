#include<stdio.h>
long long int tmp[1000001];
long long int A[1000001];
void merge(long long int A[],long long int s,long long int mid,long long int e)
{
	long long int p1 = s;
	long long int p2 = mid + 1;
	long long int p = s;
	while ( p1<=mid &&  p2<=e )
	{
		if ( A[p1]>A[p2])
			tmp[p++] = A[p2++];
		else
			tmp[p++] = A[p1++];
	}
	while(p1<=mid)
		tmp[p++] = A[p1++];
	while(p2<=e)
		tmp[p++] = A[p2++];
	long long int i;
	for ( i=s; i<=e; i++)
		A[i] = tmp[i];
}
void mergesort( long long int A[], long long int s, long long int e)
{
	if ( s>=e )/*termination condition*/
		return;
	long long int mid = (s+e)/2;
	mergesort(A, s, mid ); /* solving left half*/
	mergesort(A, (mid)+1, e);/*solving right half*/
	merge(A,s,mid,e);
}
int main()
{
	long long int t;
	scanf("%lld", &t);
	long long int n, i,sum = 0,count = 1;
	while ( t-- )
	{
		sum=0;
		i=0;
		scanf("%lld", &n);
		for(i=0;i<n;i++) scanf("%lld",&A[i]);
		mergesort(A, 0, n-1);
		count=1;
		for ( i=1; i<n; i++ )
		{
			if( A[i] == A[i-1])
				count++;
			else 
			{
				sum = sum + (count*(count-1))/2;
				count =1;
			}
		}
		sum+=count*(count-1)/2; 
		printf("%lld\n", sum);
	}
	return 0;
}
