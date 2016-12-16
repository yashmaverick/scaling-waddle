#include<stdio.h>
long long int A[1000000];
long long int temp[1000000];
long long int merge_sort( long long int s, long long int e);
long long int merge(  long long int s1, long long int e1, long long int s2, long long int e2);
long long int copy( long long int s, long long int e);
long long int comb(long long int n,long long int k)
{
	if (k==0)
		return 1;
	else
		return comb(n-1,k-1) * n / k;
}
long long int merge_sort( long long int s, long long int e)
{
	long long int mid;
	
	if(s<e)
	{
		mid=(s+e)/2;
		merge_sort(s,mid);
		merge_sort(mid+1,e);
		merge(s,mid,mid+1,e);
		copy(s,e);
	}
	return 0;
}
long long int merge( long long int s1, long long int e1, long long int s2, long long int e2)
{
	long long int i=s1;
	long long int j=s2;
	long long int m=s1;
	while((i<=e1)&&(j<=e2))
	{
		if(A[i]<=A[j])
			temp[m++]=A[i++];
		else
			temp[m++]=A[j++];
	}
	while(i<=e1)
		temp[m++]=A[i++];
	while(j<=e2)
		temp[m++]=A[j++];

	return 0;
}
long long int copy( long long int s, long long int e)
{
	long long int i;
	for(i=s;i<=e;i++)
	{
		A[i]=temp[i];
	}
	return 0;
}
int main()
{
	long long int a,b;
	scanf("%lld", &a);
	for(b=0;b<a;b++)
	{
		long long int i,n;
		long long int count=1,flag=0;
		long long int first,final=0;
		long long int ans=0;
		scanf("%lld", &n);
		for(i=0;i<n;i++)
		{
			scanf("%lld", &A[i]);
		}
		merge_sort(0,n-1);
		//	for(i=0;i<n;i++)
		//		printf("%lld ",A[i]);
		//	printf("\n");
		first=A[0];
		for(i=1;i<n;i++)
		{			
			if(first==A[i])
				count++;
			if(first!=A[i])
			{				
				long long int k=2;
				ans=comb(count,k);
				final=final+ans;
				first=A[i];
				count=1;
			}
			//if(first!=A[i])
			//	first=A[i];
		
			
		}

		final=final+(count*(count-1))/2;
		printf("%lld\n",final);

	}
	return 0;
}	
