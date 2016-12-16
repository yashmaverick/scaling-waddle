#include<stdio.h>
void merge(int L[],int R[],int A[],int n)
{
	int i=0,j=0,k=0,nl,nr,mid=n/2;
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
void mergesort(int A[],int n)
{

	if(n<2)
		return;

	int mid=n/2;
	int L[mid],R[n-mid],i,j;
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
int main()
{
	int t;
	char c[100001];
	int n,i,j,l,k,A[100001],flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		flag=1;
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			scanf("%d",&A[i]);
		}
		mergesort(A,n);
		for(i=0;i<n-2;i++)
		{
			j=i+1;
			l=n-1;
			while(j<l)
			{
				if(A[i]+A[j]+A[l]==k)
				{
					flag=0;
					break;
				}
				else if(A[i]+A[j]+A[l]>k)
				{
					l--;
				}
				else
					j++;
			}
			if(flag==0)
				break;
		}
		if(flag==0)
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}



