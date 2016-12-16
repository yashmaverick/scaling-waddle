#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>


#define MAX 1000010

void merge(int A[MAX], int p, int q, int r)
{
	int L[MAX],R[MAX],i=0,j=0,n1,n2,k;
	n1=q-p+1;
	n2=r-q;
	for(;i<n1;i++)
		L[i]=A[p+i];
	for(;j<n2;j++)
		R[j]= A[q+1+j];
	L[n1]=INT_MAX;
	R[n2]=INT_MAX;
	i=0;
	j=0;

	for(k=p;k<=r;k++)
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
	}
}

void mergesort(int A[MAX],int p,int r)
{
	if(p<r)
	{
		int q;
		q=(p+r)/2;
		mergesort(A,p,q);
		mergesort(A,q+1,r);
		merge(A,p,q,r);
	}
}



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[MAX];
		int i;
		for(i=0;i<n;i++)
			scanf("%d",arr + i );

		mergesort(arr,0,n-1);

		int c = arr[0];
		long long int temp =1;
		long long ans=0;
		for(i=1;i<n;i++)
			if(c == arr[i])
			{
				temp++;
				if(i==n-1)
					ans+=(temp * (temp-1))/2;
			}
			else
			{
				c = arr[i];
				ans+=(temp * (temp-1))/2;
				temp=1;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
