#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')


#define MAX 1005



void merge(int A[], int p, int q, int r)
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



int binarySearch(int A[],int start,int end,int elem)
{
	int low = start;
	int high = end;

	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(A[mid]==elem)
			return mid;
		else if(A[mid]>elem)
			high = mid-1;
		else if(A[mid]<elem)
			low = mid + 1;
	}

	return -1;
}



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i,j;
		scanf("%d %d",&n,&k);
		int arr[MAX];
		for(i=0;i<n;i++)
		{
			FLUSHN;
			FLUSHS;
			scanf("%d",arr + i);
		}

		mergesort(arr,0,n-1);

		int flag=1;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				int elem = k - arr[i]-arr[j];
				if(binarySearch(arr,j+1,n-1,elem)!=-1)
				{
					printf("YES\n");
					flag=0;
					break;
				}
			}
			if(!flag)
				break;
		}

		if(flag)
			printf("NO\n");
	}

	return 0;
}
