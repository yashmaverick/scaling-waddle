#include <stdio.h>
#define s 1000000
long long int A[s];
long long int A1[s];
void Merge(long long int left,long long int mid, long long int right);

void MergeSort(long long int left,long long  int right)
{
	long long int mid = (left+right)/2;
	if(left<right)
	{
		MergeSort(left,mid);
		MergeSort(mid+1,right);
		Merge(left,mid,right);
	}
	else
		return;
}
void Merge(long long int left,long long  int mid,long long int right)
{

//	long long int *A1=malloc((right-left+1)*(sizeof(long long int)));
//	long long int A1[right-left+1];
	long long int pos=0,leftpos = left,rightpos = mid + 1,k=0;
	while(leftpos <= mid && rightpos <= right)
	{
		if(A[leftpos] <=A[rightpos])
		{
			A1[k++] = A[leftpos++];
		}
		else
		{
			A1[k++] = A[rightpos++];
		}
	}
	while(leftpos <= mid)  A1[k++] = A[leftpos++];
	while(rightpos <= right) A1[k++] = A[rightpos++];
	long long int iter;
	k=0;
	for(iter = left;iter <= right; iter++)
	{
		A[iter] = A1[k++];
	}
	return;
}

int main()
{
	int test,q;
	scanf("%d",&test);
	for(q=0;q<test;q++)
	{
		long long int n,i;
		scanf("%lld",&n);
//		long long int *A=(malloc(n*(sizeof(long long int))));

		for(i=0;i<n;i++)
		{
			scanf("%lld",&A[i]);
		}
		MergeSort(0,n-1);

	/*	for(i=0;i<n;i++)
			printf("%lld ",A[i]);
		printf("\n");
*/
		long long int current=A[0];
		long long int ans=0;
		long long int count=1;
		for(i=1;i<n;i++)
		{
			if(A[i]==current)
			{
				count++;

			}
			else if(A[i]!=current)
			{
				ans=ans+(count*(count-1))/2 ;
				current=A[i];
				count=1;
			}
		}
		ans+=(count*(count-1))/2;

		printf("%lld\n",ans);
	}
	return 0;
}
